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

AC_DEFUN([OST_CC_ENDIAN],[
	AC_REQUIRE([AC_CANONICAL_SYSTEM])
	AC_REQUIRE([OST_SYS_POSIX])
	AC_CHECK_HEADER(endian.h,[
		AC_DEFINE(HAVE_ENDIAN_H, [1], [have endian header])
		],[
		AC_CHECK_HEADER(sys/isa_defs.h,[
			AC_DEFINE(HAVE_SYS_ISA_DEFS_H, [1], [solaris endian])
			],[
			case "$target_cpu" in
			alpha* | i?86)
				AC_DEFINE(__BYTE_ORDER, [1234], [endian byte order])
				;;
			hppa* | m68* | mips* | powerpc* | sparc*)
				AC_DEFINE(__BYTE_ORDER, [4321])
				;;
			esac
		])
	])
	AH_BOTTOM([
#if defined(HAVE_ENDIAN_H)
 #include <endian.h>
#elif defined(HAVE_SYS_ISA_DEFS_H)
 #include <sys/isa_defs.h>
 #ifdef	_LITTLE_ENDIAN
  #define	__BYTE_ORDER 1234
 #else
  #define	__BYTE_ORDER 4321
 #endif
 #if _ALIGNMENT_REQUIRED > 0
  #define	__BYTE_ALIGNMENT _MAX_ALIGNMENT
 #else
  #define	__BYTE_ALIGNMENT 1
 #endif
#endif

#ifndef	__LITTLE_ENDIAN
#define __LITTLE_ENDIAN 1234
#define __BIG_ENDIAN 4321
#endif

#ifndef	__BYTE_ORDER
#define	__BYTE_ORDER 1234
#endif

#ifndef	__BYTE_ALIGNMENT
#if defined(SPARC) || defined(sparc)
#if defined(__arch64__) || defined(__sparcv9)
#define	__BYTE_ALIGNMENT 8
#else
#define	__BYTE_ALIGNMENT 4
#endif
#endif
#endif

#ifndef	__BYTE_ALIGNMENT
#define	__BYTE_ALIGNMENT 1
#endif

	])

])
