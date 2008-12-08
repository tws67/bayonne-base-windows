// Copyright (C) 2005 Open Source Telecom Corporation.
//  
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software 
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

#include "module.h"
#ifndef	WIN32
#include "private.h"
#endif
#include <cerrno>

namespace moduleWebservice {
using namespace ost;
using namespace std;

Session::Session(SOCKET so) :
BayonneRPC(), Socket(so), Thread(0)
{
	setError(false);
	SLOG_DEBUG("webservice/%d: starting session", so);

	sendBuffer(TCP::getOutputBuffer());
	receiveBuffer(TCP::getInputBuffer());
}

Session::~Session()
{
	if(so != INVALID_SOCKET)
	{
		SLOG_DEBUG("webservice/%d: ending session", so);
	}
	endSocket();
	terminate();
}

char *Session::b64Decode(char *src)
{
	static const unsigned char alphabet[65] =
        	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	char *ret = src;
	unsigned char *pdst = (unsigned char *)src;

	char decoder[256];
	int i, bits, c;

        for (i = 0; i < 256; ++i)
                decoder[i] = 64;
        for (i = 0; i < 64 ; ++i)
                decoder[alphabet[i]] = i;

	bits = 1;

	while(*src && !isspace(*src))
	{
                c = (unsigned char)(*(src++));
                if (c == '=')
                {
                        if(bits & 0x40000)
                        {
                                *(pdst++) = (bits >> 10);
                                *(pdst++) = (bits >> 2) & 0xff;
                                break;
                        }
                        if (bits & 0x1000)
                                *(pdst++) = (bits >> 4);
                        break;
                }
                if (decoder[c] == 64)
                        continue;
                bits = (bits << 6) + decoder[c];
                if (bits & 0x1000000)
                {
                        *(pdst++) = (bits >> 16);
                        *(pdst++) = (bits >> 8) & 0xff;
                        *(pdst++) = (bits & 0xff);
                        bits = 1;
                }
	}
	*pdst = 0;
	return ret;
}

char *Session::urlDecode(char *source)
{
	char *ret = source;
	char *dest = source;
        char hex[3];

        while(*source)
        {
                switch(*source)
                {
                case '+':
                        *(dest++) = ' ';
                        break;
                case '%':
                        if(source[1])
                        {
                                hex[0] = source[1];
                                ++source;
                                if(source[1])
                                {
                                        hex[1] = source[1];
                                        ++source;
                                }
                                else
                                        hex[1] = 0;
                        }
                        else
                                hex[0] = hex[1] = 0;
                        hex[2] = 0;
                        *(dest++) = (char)strtol(hex, NULL, 16);
                        break;
                default:
                        *(dest++) = *source;
                }
                ++source;
        }
        *dest = 0;
        return ret;
}

void Session::syncExit(void)
{
	SLOG_DEBUG("webservice/%d: ending session", so);
	endSocket();
	Thread::exit();
}

#ifndef	VERSION
#define	VERSION "w32"
#endif

void Session::sendError(const char *text, const char *cttype)
{
	sendText(text);
	sendText("Server: Bayonne/" VERSION "\r\n");
	sendText("Pragma: no-cache\r\n");
	sendText("Cache-Control: no-cache\r\n");
	sendText("Connection: close\r\n");
	if(cttype)
	{
		snprintf(buffer, sizeof(buffer), 
			"Conection-Type: %s\r\n", cttype);
		sendText(buffer);
	}
	sendText("\r\n");
}

void Session::sendAuth(const char *text, const char *cttype)
{
	const char *realm = Service::webservice.getLast("realm");
        sendText(text);
        sendText("Server: Bayonne/" VERSION "\r\n");
	sendText("Pragma: no-cache\r\n");
	sendText("Cache-Control: no-cache\r\n");
        sendText("Connection: close\r\n");
	snprintf(buffer, sizeof(buffer),
		"WWW-Authenticate: Basic realm=\"%s\"\r\n", realm);
	sendText(buffer);
        if(cttype)
        {
                snprintf(buffer, sizeof(buffer),
                        "Conection-Type: %s\r\n", cttype);
                sendText(buffer);
        }
        sendText("\r\n");
}

#ifndef	ECONNRESET
#define	ECONNRESET -99
#endif

void Session::sendText(const char *text)
{
	int flag = 0;
#ifdef	MSG_NOSIGNAL
	flag |= MSG_NOSIGNAL;
#endif
	unsigned len = strlen(text);
	if(::send(so, text, len, flag) < (int)len)
	{
		if((errno == EPIPE) || (errno == ECONNRESET))
			Thread::exit();
	}
}

void Session::sendHeader(const char *cttype, unsigned long clen)
{
	const char *typeinfo = strchr(cttype, '/');
	char buf[96];
	sendText("HTTP/1.1 200 OK\r\n");
	sendText("Connection: close\r\n");
	snprintf(buf, sizeof(buf), "Server: Bayonne/%s\r\n", VERSION);
	sendText(buf);
	snprintf(buf, sizeof(buf), "Connection-Type: %s\r\n", cttype);
	sendText(buf);	

	if(!typeinfo)
		typeinfo = cttype;
	else
		++typeinfo;

	if(!stricmp(typeinfo, "xml") || !stricmp(typeinfo, "html"))
	{
		sendText("Pragma: no-cache\r\n");
		sendText("Cache-Control: no-cache\r\n");
	}

	if(clen)
		snprintf(buf, sizeof(buf), "Content-Length: %ld\r\n", clen);
	sendText("\r\n");
}

void Session::run(void)
{
	const char *secret = Service::webservice.getLast("secret");
	const char *cp;
	char *tok;
	if(readLine(request, sizeof(request), 10000) < 1)
	{
timeout:
		slog.notice("webservice/%d: request timeout", so);
		sendError("HTTP/1.1 408 Request Timeout\r\n");
		syncExit();
	}

	req_command = strtok_r(request, " \t\r\n", &tok);
	req_path = strtok_r(NULL, " \t\r\n", &tok);
	req_query = NULL;
	req_auth = NULL;
	if(req_path)
		tok = strchr(req_path, '?');
	else
		tok = NULL;
	if(tok)
	{
		*tok = 0;
		req_query = ++tok;
	}

	for(;;)
	{
		if(readLine(buffer, sizeof(buffer), 10000) < 1)
			goto timeout;

		if(!strnicmp(buffer, "Authorization: Basic", 20))
		{
			cp = buffer + 20;
			while(isspace(*cp))
				++cp;
			setString(auth, sizeof(auth), cp);
			b64Decode(auth);
			req_auth = auth;
		} 

		cp = buffer;
		while(isspace(*cp))
			++cp;
		if(!*cp)
			break;
	}

	if(!req_path || (stricmp(req_command, "get") && stricmp(req_command, "post")))
	{
		slog.notice("webservice/%d: invalid request", so);
		sendError("HTTP/1.1 400 Bad Request\r\n");
		syncExit();
	}
	if(*req_path == '/')
		++req_path;

	if(!req_auth && secret)
		xmlFault(401, "Authorization Required");	

	if(secret)
	{
		cp = strchr(req_auth, ':');
		if(cp)
			++cp;
		if(cp && stricmp(cp, secret))
			xmlFault(401, "Authorization Invalid");
	}

	if(!stricmp(req_command, "post"))
	{
		slog.notice("webservice/%d: unknown xmlrpc %s", so, req_path);
		sendError("HTTP/1.1 404 Not Found\r\n");
		syncExit();
	}			

	if(!stricmp(req_path, "status.xml"))
		xmlStatus();

	if(!stricmp(req_path, "traffic.xml"))
		xmlTraffic();

	if(!stricmp(req_path, "timeslots.xml"))
		xmlTimeslots();

	if(!stricmp(req_path, "servicelevel.xml"))
		xmlServicelevel();

	if(!stricmp(req_path, "uptime.xml"))
		xmlUptime();

	if(!stricmp(req_path, "drivers.xml"))
		xmlDrivers();

	if(!stricmp(req_path, "registrations.xml"))
		xmlRegistrations();

	if(!stricmp(req_path, "calls.xml"))
		xmlCalls();

	if(!stricmp(req_path, "reload.xml"))
		xmlReload();

	if(!stricmp(req_path, "stop.xml"))
		xmlStop();

	if(!stricmp(req_path, "hold.xml"))
		xmlHold();

	if(!stricmp(req_path, "refer.xml"))
		xmlRefer();

	if(!stricmp(req_path, "resume.xml"))
		xmlResume();

	if(!stricmp(req_path, "start.xml"))
		xmlStart();

	if(!stricmp(req_path, "shutdown.xml"))
		xmlShutdown();

	if(!stricmp(req_path, "status.html"))
		htmlStatus();

	if(!stricmp(req_path, "calls.html"))
		htmlCalls();

	if(!stricmp(req_path, "control.html"))
		htmlControl();

	slog.notice("webservice/%d: unknown page %s", so, req_path);

	cp = strrchr(req_path, '.');

	xmlFault(404, "Not Found");	
	syncExit();
}
	
} // namespace 
