# Copyright (C) 2004 Open Source Telecom Corporation.
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

AC_INIT(reconfig)

VERSION="0.8.0"
LT_RELEASE="0.8"
LT_VERSION="0:0"

cfg_options=""
if test -z "$*" ; then
        if test -f ~/.configure ; then
		cfg_options=`grep ^ccscript3: ~/.configure | sed -e s/^ccscript3://`
	elif test -f /etc/configure.conf ; then
		cfg_options=`grep ^ccscript3: /etc/configure.conf | sed -e s/^ccscript3://`
	fi
fi

if test ! -z "$cfg_options" ; then
        echo "using ~/.configure defaults...$cfg_options"
        case "$SHELL" in
        */bash*)
                exec $SHELL $0 $cfg_options
                exit -1
                ;;
        esac
        exec $0 $cfg_options
        exit -1
fi

AC_CONFIG_AUX_DIR(autoconf)
AC_CANONICAL_SYSTEM
AC_PROG_CPP
AC_PROG_CXXCPP
AC_PROG_CXX
AM_PROG_LIBTOOL
AM_INIT_AUTOMAKE(ccscript3,[$VERSION])
AM_CONFIG_HEADER(src/private.h)
AM_MAINTAINER_MODE

AC_ARG_WITH(odbc, [--without-odbc          Disable postgres support],,[
        ost_cv_odbc_database=false
        AC_CHECK_HEADER(odbc/sql.h,[   
                AC_DEFINE(HAVE_ODBC_SQL_H, [1], [offset odbc header])
                ost_cv_odbc_database=true
        ],[
                AC_CHECK_HEADER(sql.h,[
                        AC_DEFINE(HAVE_SQL_H, [1], [local odbc header])
                        ost_cv_odbc_database=true
                ])
        ])
        if "$ost_cv_odbc_database" = "true" ; then
                ODBC_LIB="-liodbc"
                AC_CHECK_LIB(odbc, SQLConnect,
                        ODBC_LIB="-lodbc")
                AC_SUBST(ODBC_LIB)
        fi
])

if test -z "$PKG_CONFIG_PATH" ; then
	PKG_CONFIG_PATH="/usr/local/lib/pkgconfig"
fi

if test "$prefix" != "NONE" ; then
	PKG_CONFIG_PATH="$prefix/lib/pkgconfig:$PKG_CONFIG_PATH"
fi

export PKG_CONFIG_PATH

PKG_CHECK_MODULES(COMMON, libccgnu2 >= 1.3.5)
CXXFLAGS="$CXXFLAGS $COMMON_CFLAGS"
COMMON_LIBPATH=`pkg-config --variable=libdir libccgnu2`
LIBS="$LIBS -L$COMMON_LIBPATH $COMMON_LIBS"
COMMON_MODFLAGS=`pkg-config --variable=modflags libccgnu2`
AC_SUBST(COMMON_MODFLAGS)
AC_CHECK_HEADERS(regex.h)



AC_DEFUN([OST_DEBUG],[
	AC_MSG_CHECKING(for debugging)
	AC_ARG_ENABLE(debug, [  --enable-debug          compile for debugging])	
	if test -z "$enable_debug" ; then
		enable_debug="no"
	elif test $enable_debug = "yes" ; then
		CXXFLAGS="${CXXFLAGS} -g -DDEBUG"
#		CXXFLAGS=`echo $CFLAGS | sed 's/-O.//'`
	fi
	AC_MSG_RESULT([$enable_debug])
	AC_MSG_CHECKING(for profiling)
	AC_ARG_ENABLE(profiling, [  --enable-profiling      compile for profiling])
	if test -z "$enable_profiling" ; then
		enable_profiling="no"
	elif test "$enable_profiling" = "yes" ; then
		CXXFLAGS="${CXXFLAGS} -p"
	fi
	AC_MSG_RESULT([$enable_profiling])
])


AC_DEFUN([AC_SUBST_DIR], [
        ifelse($2,,,$1="[$]$2")
        result="***"
        prior="A"
        while test "$prior" != "$result" ; do
                prior=`(echo "[$]$1")`
                $1=`(
                test "x$prefix" = xNONE && prefix="$ac_default_prefix"
                test "x$exec_prefix" = xNONE && exec_prefix="${prefix}"
                eval echo \""[$]$1"\"      
                )`
                result=`(echo "[$]$1")`
        done
        AC_SUBST($1)
])


ODBC_MODULE=""
if test "$ost_cv_odbc_database" = true ; then
        ODBC_MODULE=odbc ; fi

AC_SUBST(ODBC_MODULE)

OST_DEBUG

case "$prefix" in
/opt/*)
        if test "$localstatedir" == '${prefix}/var' ; then
                localstatedir=/var${prefix} ; fi

        if test "$datadir" == '${prefix}/share' ; then
                if test "$mandir" == '${datadir}/man' ; then
                        mandir='${prefix}/man' ; fi
                if test "$infodir" == '${datadir}/info' ; then
                        infodir='${prefix}/info' ; fi
                datadir='${prefix}'
        fi
        AC_SUBST(mandir)
        AC_SUBST(infodir)
        AC_SUBST(datadir)
        AC_SUBST(localstatedir)
        ;;
esac

if test "$localstatedir" == '${prefix}/var' ; then
        localstatedir="/var" ; fi
AC_SUBST(localstatedir)

script_libdir=""
eprefix=${exec_prefix}
if test "$eprefix" == "NONE" ; then
        eprefix=${prefix} ; fi

case "$eprefix" in
NONE)
        if test "$libdir" == '${exec_prefix}/lib' ; then
                script_libdir='${exec_prefix}/lib/ccscript3-'${LT_RELEASE}
        fi
        ;;
/opt/*)
        if test "$libdir" == '${exec_prefix}/lib' ; then
                script_libdir='${exec_prefix}/lib/ccscript3'
        fi
        ;;
*)
        if test "$libdir" == '${exec_prefix}/lib' ; then
                script_libdir='${exec_prefix}/lib/ccscript3-'${LT_RELEASE}
        fi
        ;;
esac

if test -z "$script_libdir" ; then
       	script_libdir='${libdir}/ccscript3' ; fi

AC_SUBST(STAGE2)
AC_SUBST(script_libdir)
AC_SUBST_DIR(script_libpath, script_libdir)
AC_SUBST(LT_VERSION)
AC_SUBST(LT_RELEASE)

AC_DEFINE_UNQUOTED(SCRIPT_LIBPATH, "$script_libpath", [define codec path])

SHARED_FLAGS=""
STAGE2=""       
case "$target_os" in
cygwin*)
        SHARED_FLAGS="-no-undefined"
        ;;
darwin6*)
	STAGE2="macosx"
        ;;
esac

AC_PATH_PROG(DOXYGEN, doxygen, no)
AC_SUBST(DOXYGEN)
AM_CONDITIONAL(DOXY, test "$DOXYGEN" != "no")

AC_OUTPUT(Makefile src/Makefile tests/Makefile modules/Makefile
optional/Makefile optional/odbc/Makefile
libccscript3.pc ccscript3.spec ccscript3.list)


