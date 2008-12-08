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
#include <cc++/process.h>

namespace moduleWebservice {
using namespace ost;
using namespace std;

Service Service::webservice;
bool Service::active = false;

Service::Service() :
BayonneService(0, 0), 
BayonneZeroconf("_http._tcp"),
Keydata("/bayonne/module/webservice")
{
	const char *cp;

	static Keydata::Define defkeys[] = {
	{"interface", "127.0.0.1"},
	{"port", "8055"},
	{"backlog", "5"},
	{"output", "2048"},
	{"input", "1024"},
	{"segment", "536"},
	{"refresh", "10"},
	{"realm", "bayonne"},
	{"datafiles", WEBSERVER_FILES}, 
	{"zeroconf", "yes"},
	{NULL, NULL}};

	if(Bayonne::getUserdata())
	        load("~bayonne/webservice");

	load(defkeys);
#ifdef	WIN32
	loadFile("C:\\Program Files\\GNU Telephony\\Bayonne Config\\module.ini", "webservice");
#endif
	cp = getLast("zeroconf");
	switch(*cp)
	{
	case 'y':
	case 'Y':
	case 't':
	case 'T':
	case '1':
		zeroconf_port = atoi(getLast("port"));
	}
}

void Service::stopService(void)
{
	active = false;
	terminate();
}

void Service::run(void)
{
	Session *s;
	SOCKET so;
	TCP *tcp;
	const char *cp;
	char *tok;
	char *p = (char *)getLast("interface");
	unsigned count = 0, ipv6_count = 0;

	slog.info("webservice started");
	
	cp = strtok_r(p, " ,;\t", &tok);
	while(cp)
	{
#ifdef	CCXX_IPV6
		++count;
		if(strchr(cp, ':'))
		{
			++ipv6_count;
			new TCPV6(cp);
		}
		else
#endif
		new TCPV4(cp);
		cp = strtok_r(NULL, " ,;\t", &tok);
	}

	if(count && ipv6_count == count)
		zeroconf_family = ZEROCONF_IPV6;
	else if(count && !ipv6_count)
		zeroconf_family = ZEROCONF_IPV4;
	
	for(;;)
	{
		tcp = TCP::getSelect();
		if(!tcp)
			break;
		so = tcp->getAccept();
		if(so == INVALID_SOCKET)
			continue;
		s = new Session(so);
		s->detach();
	}
}

} // namespace 
