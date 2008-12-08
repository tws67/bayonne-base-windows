Summary: "ccrtp" - a Common C++ class framework for RTP/RTCP
Name: ccrtp
Version: 1.6.2
Release: 1
Epoch: 0
License: LGPL
Group: Development/Libraries
URL: http://www.gnu.org/software/commoncpp/commoncpp.html
Source0: ftp://ftp.gnu.org/gnu/cccrtp/ccrtp-%{PACKAGE_VERSION}.tar.gz
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root 
Requires: commoncpp2 >= 1.4.0
Requires: libgcrypt
BuildRequires: commoncpp2-devel >= 1.4.0
BuildRequires: pkgconfig
BuildRequires: libstdc++-devel
BuildRequires: libgcrypt-devel

%package devel
Group: Development/Libraries
Summary: Headers and static link library for ccrtp.
Requires: %{name} = %{epoch}:%{version}-%{release} 
Requires: commoncpp2-devel >= 1.4.0
Requires: libgcrypt-devel

%description
ccRTP is a generic, extensible and efficient C++ framework for
developing applications based on the Real-Time Transport Protocol
(RTP) from the IETF. It is based on Common C++ and provides a full
RTP/RTCP stack for sending and receiving of realtime data by the use
of send and receive packet queues. ccRTP supports unicast,
multi-unicast and multicast, manages multiple sources, handles RTCP
automatically, supports different threading models and is generic as
for underlying network and transport protocols.

%description devel
This package provides the header files, link libraries, and 
documentation for building applications that use GNU ccrtp. 

%prep
%setup
%build
%configure

make %{?_smp_mflags} LDFLAGS="-s" CXXFLAGS="$RPM_OPT_FLAGS"

%install

%makeinstall
rm -rf %{buildroot}/%{_infodir} 

%clean
rm -rf %{buildroot}

%files
%defattr(-,root,root,0755)
%doc AUTHORS COPYING ChangeLog README COPYING.addendum
%{_libdir}/*.so.*

%files devel
%defattr(-,root,root,0755)
%{_libdir}/*.a
%{_libdir}/*.so
%{_libdir}/*.la   
%{_libdir}/pkgconfig/*.pc
%dir %{_includedir}/ccrtp
%{_includedir}/ccrtp/*.h

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig  
