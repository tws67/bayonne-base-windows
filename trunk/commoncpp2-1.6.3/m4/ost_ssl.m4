dnl Copyright (C) 2001 Open Source Telecom Corporation.
dnl  
dnl This program is free software; you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License as published by
dnl the Free Software Foundation; either version 2 of the License, or
dnl (at your option) any later version.
dnl 
dnl This program is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.
dnl 
dnl You should have received a copy of the GNU General Public License
dnl along with this program; if not, write to the Free Software 
dnl Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
dnl 
dnl As a special exception to the GNU General Public License, if you 
dnl distribute this file as part of a program that contains a configuration 
dnl script generated by Autoconf, you may include it under the same 
dnl distribution terms that you use for the rest of that program.

AC_DEFUN([OST_LIB_NOSSL],[
	SSL_LIBS=""
	AC_SUBST(SSL_LIBS)
])

AC_DEFUN([OST_LIB_SSL],[
	SSL_LIBS=""
#
#	WE CANNOT YET USE GNUTLS BECAUSE GNUTLS OPENSSL EMULATION DOES 
#	NOT SUPPORT THREAD SAFETY, SO ssl.cpp MUST BE REWRITTEN TO USE
#	NATIVE GNUTLS API.
#
#	AC_CHECK_HEADER(gnutls/gnutls.h,[
#		AC_CHECK_LIB(gnutls, gnutls_init, [
#			SSL_LIBS="-lgnutls -lgcrypt -ltasn1"
#			ost_cv_ssl=true
#			AC_DEFINE(CCXX_SSL, [GNUTLS], [defines ssl])
#			AC_DEFINE(CCXX_GNUTLS, [1], [define gnutls])
#		])
#	],[
		AC_CHECK_HEADER(openssl/ssl.h,[
			SSL_LIBS="-lssl"
			ost_cv_ssl=true
			AC_DEFINE(CCXX_OPENSSL, [1], [define openssl])
			AC_DEFINE(CCXX_SSL, [OPENSSL], [defines ssl])
		])
#	])
	AC_SUBST(SSL_LIBS)
])

