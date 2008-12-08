dnl Copyright (C) 1999-2001 Open Source Telecom Corporation.
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

AC_DEFUN([OST_CC_SIGNAL],[
	AC_REQUIRE([OST_SYS_POSIX])
	AC_CHECK_FUNCS(sigaction)
	AC_CHECK_FUNCS(setitimer)
	AC_CHECK_FUNCS(sigwait)
	AC_CHECK_HEADERS(bsd/signal.h)
	AC_TYPE_SIGNAL
	AC_CACHE_CHECK(whether sigwait has 2 arguments,
		ac_cv_ost_sigwait2,
		AC_TRY_COMPILE([
			#define _POSIX_PTHREAD_SEMANTICS
			#include <stdio.h>
			#include <signal.h>],
			[sigwait(NULL, NULL);],
			 ac_cv_ost_sigwait2=yes,
			ac_cv_ost_sigwait2=no
		)
	)
	if test "$ac_cv_ost_sigwait2" = "yes" ; then
		AC_DEFINE(HAVE_SIGWAIT2, [1], [2 argument form])
	fi
AH_BOTTOM([
#ifdef HAVE_SIGACTION
#ifdef HAVE_BSD_SIGNAL_H
#undef HAVE_BSD_SIGNAL_H
#endif
#endif

/* Cause problem with Solaris... and perhaps Digital Unix?
  However, the autoconf test in ost_signal defines _POSIX_PTHREAD_SEMANTICS 
 when trying to compile sigwait2. */

#ifdef  HAVE_SIGWAIT2
#ifndef	_POSIX_PTHREAD_SEMANTICS
#define _POSIX_PTHREAD_SEMANTICS
#endif
#endif

#ifdef HAVE_BSD_SIGNAL_H
#include <bsd/signal.h>
#else
#include <signal.h>
#endif
#ifndef SA_ONESHOT
#define SA_ONESHOT SA_RESETHAND
#endif

	])
])
