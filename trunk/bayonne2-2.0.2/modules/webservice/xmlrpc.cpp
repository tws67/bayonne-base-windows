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

void Session::rpcFault(int code, const char *string)
{
	char buf[28];
	snprintf(buf, sizeof(buf), "<int>%d</int>", code);

	strcpy(buffer, "<?xml version=\"1.0\"?>\r\n");
	strcat(buffer, "<methodResponse><fault><value><struct>\r\n");

	strcat(buffer, " <member><name>faultCode</name>\r\n  <value>");
	strcat(buffer, buf);
	strcat(buffer, "</value>\r\n </member>\r\n");

	strcat(buffer, " <member><name>faultString</name>\r\n  <value><string>");
	strcat(buffer, string);
	strcat(buffer, "</string></value>\r\n </member>\r\n");

	strcat(buffer, "</struct></value></fault></methodResponse>\r\n");
	sendHeader("text/xml", strlen(buffer));
	sendText(buffer);
	syncExit();
}

void Session::rpcReply(const char *string)
{
	strcpy(buffer, "<?xml version=\"1.0\"?>\r\n");
	strcat(buffer, "<methodResponse>\r\n");
	if(string)
	{
		strcat(buffer, " <params><param><value>\r\n  <string>");
		strcat(buffer, string);
		strcat(buffer, "</string>\r\n </value></param></params>\r\n");
	}
	strcat(buffer, "</methodResponse>\r\n");
	sendHeader("text/xml", strlen(buffer));
	sendText(buffer);
	syncExit();
}
	
} // namespace 
