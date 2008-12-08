# Copyright (C) 2005 David Sugar, Tycho Softworks
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#
# Bayonne python libexec interface module.  

import sys, os, string, urllib2
from xml.dom import minidom

class Server:
	hostid = ''
	secret = ''

	def http_error_401(self, url, fp, errcode, errmsg, headers, data=None):
		return None

	def __init__(self, hostid, secret=None):
		self.hostid = hostid
		self.secret = secret
		password_mgr = urllib2.HTTPPasswordMgrWithDefaultRealm()
		password_mgr.add_password(None, "http://%s/" % hostid, "server", secret)
		auth_handler = urllib2.HTTPBasicAuthHandler(password_mgr)
		self.opener = urllib2.build_opener(auth_handler)
		return

	def fetch(self, document):
		data = self.opener.open("http://%s/%s" % (self.hostid, document))
		xmldoc = minidom.parseString(data.read())
		self.opener.close()
		return xmldoc
