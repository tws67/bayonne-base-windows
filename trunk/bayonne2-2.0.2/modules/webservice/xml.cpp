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

namespace moduleWebservice {
using namespace ost;
using namespace std;

void Session::xmlSuccess(void)
{
	sendText("<result id=\"command\" value=\"success\"/>\r\n");
}

void Session::xmlFooter(void)
{
	sendText(" </results>\r\n");
	sendText("</serverResponse>\r\n");
	sendText("\r\n");
	syncExit();
}

void Session::xmlHeader(const char *service)
{
	sendHeader("text/xml");
	sendText("<?xml version=\"1.0\"?>\r\n");
	sendText("<serverResponse>\r\n");
	snprintf(buffer, sizeof(buffer),
		"  <results server=\"bayonne\" service=\"%s\">\r\n", service);
	sendText(buffer);
}

void Session::xmlFault(int code, const char *string)
{
	char msg[96];
	const char *svc = string;

	if(code < 600)
	{
		snprintf(msg, sizeof(msg), "HTTP/1.1 %d %s\r\n", code, string);
		if(code == 401)
			sendAuth(msg, "text/xml");
		else
			sendError(msg, "text/xml");
	}
	else
		sendHeader("text/xml");

	sendText("<?xml version=\"1.0\"?>\r\n");
	sendText("<serverResponse>\r\n");
	if(code >= 300 && code <= 500)
		svc = "http";			
	snprintf(buffer, sizeof(buffer),
		" <faults server=\"bayonne\" service=\"%s\">\r\n", svc);
	sendText(buffer);
	snprintf(buffer, sizeof(buffer),
		"  <fault id=\"code\" value=\"%d\"/>\r\n", code);
	sendText(buffer);
	if(svc != string)
	{
		snprintf(buffer, sizeof(buffer),
			"  <fault id=\"text\" value=\"%s\"/>\r\n", string);
		sendText(buffer);
	}
	sendText(" </faults>\r\n");
	sendText("</serverResponse>\r\n");
	sendText("\r\n");
	syncExit();
}

void Session::xmlReload(void)
{
	xmlHeader("reload");
	reload();
	xmlSuccess();
	xmlFooter();
}

void Session::xmlShutdown(void)
{
        xmlHeader("shutdown");
        down();
	xmlSuccess();
        xmlFooter();
}

void Session::xmlStop(void)
{
	char *tok;
	char *sid = NULL;
	BayonneSession *s;
	Event event;

	if(req_query)
		req_query = strtok_r(req_query, "&\r\n", &tok);

	while(req_query)
	{
		if(!strnicmp(req_query, "session=", 8))
		 	sid = urlDecode(req_query + 8);
		req_query = strtok_r(NULL, "&\r\n", &tok);
	}
	if(!sid)
		xmlFault(XML_ARGUMENT_MISSING, "stop");
	
	s = getSid(sid);
	if(!s)
		xmlFault(XML_SESSION_INVALID, "stop");

	memset(&event, 0, sizeof(event));
	event.id = STOP_SCRIPT;
	if(!s->postEvent(&event))	
		xmlFault(XML_COMMAND_FAILED, "stop");
	xmlHeader("stop");
	xmlSuccess();
	xmlFooter();
}

void Session::xmlHold(void)
{
	char *tok;
	char *sid = NULL;
	BayonneSession *s;
	Event event;

	if(req_query)
		req_query = strtok_r(req_query, "&\r\n", &tok);

	while(req_query)
	{
		if(!strnicmp(req_query, "session=", 8))
		 	sid = urlDecode(req_query + 8);
		req_query = strtok_r(NULL, "&\r\n", &tok);
	}
	if(!sid)
		xmlFault(XML_ARGUMENT_MISSING, "hold");
	
	s = getSid(sid);
	if(!s)
		xmlFault(XML_SESSION_INVALID, "hold");

	memset(&event, 0, sizeof(event));
	event.id = CALL_HOLD;
	if(!s->postEvent(&event))	
		xmlFault(XML_COMMAND_FAILED, "hold");
	xmlHeader("hold");
	xmlSuccess();
	xmlFooter();
}

void Session::xmlResume(void)
{
	char *tok;
	char *sid = NULL;
	BayonneSession *s;
	Event event;

	if(req_query)
		req_query = strtok_r(req_query, "&\r\n", &tok);

	while(req_query)
	{
		if(!strnicmp(req_query, "session=", 8))
		 	sid = urlDecode(req_query + 8);
		req_query = strtok_r(NULL, "&\r\n", &tok);
	}
	if(!sid)
		xmlFault(XML_ARGUMENT_MISSING, "resume");
	
	s = getSid(sid);
	if(!s)
		xmlFault(XML_SESSION_INVALID, "resume");

	memset(&event, 0, sizeof(event));
	event.id = CALL_NOHOLD;
	if(!s->postEvent(&event))	
		xmlFault(XML_COMMAND_FAILED, "resume");
	xmlHeader("resume");
	xmlSuccess();
	xmlFooter();
}

void Session::xmlStart(void)
{
	char *tok;
	const char *sid = NULL;
	BayonneSession *s;
	char *qtarget = NULL;
	char *qscript = NULL;
	char *qcaller = NULL;
	char *qdisplay = NULL;

	if(req_query)
		req_query = strtok_r(req_query, "&\r\n", &tok);

	while(req_query)
	{
		if(!strnicmp(req_query, "target=", 7))
		 	qtarget = urlDecode(req_query + 7);
		else if(!strnicmp(req_query, "script=", 7))
			qscript = urlDecode(req_query + 7);
		else if(!strnicmp(req_query, "caller=", 7))
			qcaller = urlDecode(req_query + 7);
		else if(!strnicmp(req_query, "display=", 8))
			qdisplay = urlDecode(req_query + 8);	
		req_query = strtok_r(NULL, "&\r\n", &tok);
	}
	if(!qtarget || !qscript)
		xmlFault(XML_ARGUMENT_MISSING, "start");
	
	s = startDialing(qtarget, qscript, qcaller, qdisplay);
	if(!s)
		xmlFault(XML_COMMAND_FAILED, "start");

	s->setConst("session.manager", "webservice");
	sid = s->getExternal("session.id");
	xmlHeader("start");
	snprintf(buffer, sizeof(buffer),
		"  <result id=\"session\" value=\"%s\"/>\r\n", sid);
	sendText(buffer);
	xmlFooter();
}

void Session::xmlRefer(void)
{
	char *tok;
	const char *sid = NULL;
	BayonneSession *s;
	char *target = NULL;
	Event event;

	if(req_query)
		req_query = strtok_r(req_query, "&\r\n", &tok);

	while(req_query)
	{
		if(!strnicmp(req_query, "target=", 7))
		 	target = urlDecode(req_query + 7);
		else if(!strnicmp(req_query, "session=", 8))
			sid = urlDecode(req_query + 8);
		req_query = strtok_r(NULL, "&\r\n", &tok);
	}
	if(!target || !sid)
		xmlFault(XML_ARGUMENT_MISSING, "refer");
	
	s = getSid(sid);
	if(!s)
		xmlFault(XML_SESSION_INVALID, "refer");

	s->enterMutex();
	if(!s->isJoined())
	{
		s->leaveMutex();
		xmlFault(XML_COMMAND_FAILED, "refer");
	}
	if(!s->isHolding())
	{
		s->leaveMutex();
		xmlFault(XML_COMMAND_FAILED, "refer");
	}
	memset(&event, 0, sizeof(event));
	event.id = START_REFER;
	event.dialing = target;
	if(!s->postEvent(&event))
	{
		s->leaveMutex();
		xmlFault(XML_COMMAND_FAILED, "refer");
	}
	s->leaveMutex();
	xmlHeader("refer");
	xmlSuccess();
	xmlFooter();
}
	
void Session::xmlRegistrations(void)
{
	BayonneDriver *d = BayonneDriver::getPrimary();
	char *dn = NULL;
	char *tok;
	unsigned count;
	regauth_t *r;

	if(req_query)
		req_query = strtok_r(req_query, "&\r\n", &tok);

	while(req_query)
	{
		if(!strnicmp(req_query, "driver=", 7))
			dn = req_query + 7;
		req_query = strtok_r(NULL, "&\r\n", &tok);
	} 

	xmlHeader("registrations");
	sendText("  <lists id=\"registrations\">\r\n");
	while(d)
	{
		if(dn && stricmp(dn, d->getName()))
		{
			d = d->getNext();
			continue;
		}
		reloading.readLock();
		count = d->getRegistration(regs, 1024);
		r = regs;
		while(count--)
		{
			snprintf(buffer, sizeof(buffer), 
				"   <list id=\"registration\">\r\n"
				"    <item id=\"driver\" value=\"%s\"/>\r\n"
				"    <item id=\"remote\" value=\"%s\"/>\r\n"
				"    <item id=\"userid\" value=\"%s\"/>\r\n"
				"    <item id=\"access\" value=\"%s\"/>\r\n"
				"    <item id=\"status\" value=\"%s\"/>\r\n"
				"    <item id=\"active\" value=\"%d\"/>\r\n"
				"   </list>\r\n",
				d->getName(),
				r->remote, r->userid, r->type, r->status,
				(int)r->active_calls);
			sendText(buffer);
			++r;
		}
		reloading.unlock();
		d = d->getNext();
	}
	sendText("  </lists>\r\n");
	xmlFooter();
}

void Session::xmlDrivers(void)
{
	BayonneDriver *d = BayonneDriver::getPrimary();
	xmlHeader("drivers");
	sendText("  <lists id=\"drivers\">\r\n");
	while(d)
	{
		snprintf(buffer, sizeof(buffer), 
			"   <list id=\"driver\">\r\n"
			"    <item id=\"driver\" value=\"%s\"/>\r\n"
			"    <item id=\"firstTimeslot\" value=\"%d\"/>\r\n"
			"    <item id=\"countTimeslots\" value=\"%d\"/>\r\n"
			"    <item id=\"activeTimeslots\" value=\"%d\"/>\r\n"
			"    <item id=\"firstSpan\" value=\"%d\"/>\r\n"
			"    <item id=\"countSpans\" value=\"%d\"/>\r\n"
			"    <item id=\"incomingAttempts\" value=\"%lu/>\r\n"
                        "    <item id=\"outgoingAttempts\" value=\"%lu/>\r\n"
                        "    <item id=\"incomingComplete\" value=\"%lu/>\r\n"
                        "    <item id=\"outgoingComplete\" value=\"%lu/>\r\n"

			"   </list>\r\n",
			d->getName(),
			(int)d->getFirst(), (int)d->getCount(),
			(int)d->active_calls,
			(int)d->getSpanFirst(), (int)d->getSpansUsed(),
			d->call_attempts.iCount, d->call_attempts.oCount,
                        d->call_complete.iCount, d->call_complete.oCount);
		sendText(buffer);
		d = d->getNext();
	}
	sendText("  </lists>\r\n");
	xmlFooter();
}

void Session::xmlCalls(void)
{
	BayonneSession *s;
	timeslot_t index = 0;
	xmlHeader("calls");
	sendText("  <lists id=\"calls\">\r\n");
	while(index < ts_used)
	{
		s = getSession(index++);
		if(!s)
			continue;

		s->enter();
		if(s->isIdle())
		{
			s->leave();
			continue;
		}
		snprintf(buffer, sizeof(buffer),
			"   <list id=\"call\">\r\n"
			"    <item id=\"session\" value=\"%s\"/>\r\n"
			"    <item id=\"parent\" value=\"%s\"/>\r\n"
			"    <item id=\"type\" value=\"%s\"/>\r\n"
			"    <item id=\"duration\" value=\"%s\"/>\r\n"
			"    <item id=\"caller\" value=\"%s\"/>\r\n"
			"    <item id=\"dialed\" value=\"%s\"/>\r\n"
			"   </list>\r\n",
			s->getExternal("session.id"),
			s->getExternal("session.pid"),
			s->getExternal("session.type"),
			s->getExternal("session.duration"),
			s->getSymbol("session.caller"),
			s->getSymbol("session.dialed"));
		sendText(buffer);
		s->leave();
	}
	sendText("  </lists>\r\n");
	xmlFooter();
}

void Session::xmlUptime(void)
{
        xmlHeader("uptime");
        snprintf(buffer, sizeof(buffer),
                "  <result id=\"uptime\" value=\"%ld\"/>\r\n", uptime());
        sendText(buffer);
        xmlFooter();
}

void Session::xmlStatus(void)
{
	BayonneSession *s = NULL;
	char *sid = NULL;
	char *tok;
	const char *stat;

	if(req_query)
		req_query = strtok_r(req_query, "&\r\n", &tok);

	while(req_query)
	{
		if(!strnicmp(req_query, "session=", 8))
			sid = urlDecode(req_query + 8);
		req_query = strtok_r(NULL, "&\r\n", &tok);
	}
	if(sid)
	{
		s = getSid(sid);
		if(s)
		{
			xmlHeader("status");
			if(s->isRefer())
				stat = "refer";
			else if(s->isHolding())
				stat = "holding";
			else
				stat = "success";
			snprintf(buffer, sizeof(buffer),
				"  <result id=\"command\" value=\"%s\"/>\r\n", stat);	
			sendText(buffer);		
			xmlFooter();
		}
		else
			xmlFault(XML_SESSION_INVALID, "status");
	}

	xmlHeader("status");
	snprintf(buffer, sizeof(buffer), 
		"  <result id=\"status\" value=\"%s\"/>\r\n", status);
	sendText(buffer);
	xmlFooter();
}

void Session::xmlTraffic(void)
{
	xmlHeader("traffic");
	snprintf(buffer, sizeof(buffer),
		"  <result id=\"timestamp\" value=\"%lu\"/>\r\n", 
			Bayonne::Traffic::getStamp());
	sendText(buffer);
        snprintf(buffer, sizeof(buffer),
                "  <result id=\"incomingAttempts\" value=\"%lu\"/>\r\n",
                        Bayonne::total_call_attempts.iCount);
        sendText(buffer);

        snprintf(buffer, sizeof(buffer),
                "  <result id=\"outgoingAttempts\" value=\"%lu\"/>\r\n",
                        Bayonne::total_call_attempts.oCount);
        sendText(buffer);

        snprintf(buffer, sizeof(buffer),
                "  <result id=\"incomingComplete\" value=\"%lu\"/>\r\n",
                        Bayonne::total_call_complete.iCount);
        sendText(buffer);
	
	snprintf(buffer, sizeof(buffer),
		"  <result id=\"outgoingComplete\" value=\"%lu\"/>\r\n",
			Bayonne::total_call_complete.oCount);
	sendText(buffer);

        snprintf(buffer, sizeof(buffer),
                "  <result id=\"activeCalls\" value=\"%u\"/>\r\n",
                        (int)Bayonne::total_active_calls);
        sendText(buffer);

	xmlFooter();
}

void Session::xmlTimeslots(void)
{
	xmlHeader("timeslots");
	snprintf(buffer, sizeof(buffer), 
		"  <result id=\"timeslots\" value=\"%d\"/>\r\n", ts_used);
	sendText(buffer);
	xmlFooter();
}

void Session::xmlServicelevel(void)
{
	const char *sl = sla;
	if(!*sl)
		sl = "up";
	xmlHeader("servicelevel");
	snprintf(buffer, sizeof(buffer), 
		"  <result id=\"level\" value=\"%s\"/>\r\n", sl);
	sendText(buffer);
	xmlFooter();
}

} // namespace 
