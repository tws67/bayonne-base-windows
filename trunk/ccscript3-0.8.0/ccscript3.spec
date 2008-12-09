Summary: GNU ccScript3 - a C++ class framework for scripting.
Name: ccscript3
Version: 0.8.0
Release: 1
Group: Development/Libraries
URL: http://www.gnu.org/software/ccscript
Source: ftp://ftp.gnu.org/gnu/ccscript/ccscript3-%{PACKAGE_VERSION}.tar.gz
Prefix: %{_prefix}
Copyright: GPL
BuildRoot: %{_tmppath}/ccaudio3-root
Requires: commoncpp2 >= 1.3.1
Packager: David Sugar <dyfet@ostel.com>

%package devel
Group: Development/Libraries
Summary: header files and static link library for GNU ccScript.
Requires: ccaudio2, commoncpp2-devel

%description
GNU ccScript3 is a C++ class framework for creating a virtual machine
execution system for use with and as a scripting/assembler language for
state-transition driven realtime systems. 

%description devel
This package provides the header files and documentation for building
applications that use GNU ccScript3. 

%prep
rm -rf $RPM_BUILD_ROOT

%setup -n ccscript3-%{PACKAGE_VERSION}
CXXFLAGS="$RPM_OPT_FLAGS" ./configure --prefix=%{_prefix}

%build
uname -a|grep SMP && make -j 2 || make

%install
mkdir -p $RPM_BUILD_ROOT/%{_mandir}/man3

#make docs
make prefix=$RPM_BUILD_ROOT/%{_prefix} \
	mandir=$RPM_BUILD_ROOT/%{_mandir} install
make prefix=$RPM_BUILD_ROOT/%{_prefix} \
        mandir=$RPM_BUILD_ROOT/%{_mandir} man
strip $RPM_BUILD_ROOT/%{_prefix}/lib/libcc*.so.*

%files
%defattr(-,root,root,0755)
%{_prefix}/lib/libcc*so*
%{_prefix}/lib/ccscript3-0.8

%files devel
%defattr(-,root,root,0755)
%doc AUTHORS COPYING NEWS README TODO ChangeLog 
%{_prefix}/lib/libcc*a
%{_prefix}/include/cc++2/cc++/script3.h

%clean
rm -rf $RPM_BUILD_ROOT

%post
/sbin/ldconfig -n ${exec_prefix}/lib

%postun
/sbin/ldconfig -n ${exec_prefix}/lib
