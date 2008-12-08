Summary: GNU ccAudio2 - a C++ class framework for processing audio files.
Name: ccaudio2
Version: 0.9.5
Release: 1
Group: Development/Libraries
URL: http://www.gnu.org/software/ccaudio
Source: ftp://ftp.gnu.org/gnu/ccaudio/ccaudio2-%{PACKAGE_VERSION}.tar.gz
Prefix: %{_prefix}
Copyright: GPL
BuildRoot: %{_tmppath}/ccaudio2-root
Packager: David Sugar <dyfet@ostel.com>
BuildRequires: libstdc++-devel

%package devel
Group: Development/Libraries
Summary: header files and static link library for GNU ccAudio.
Requires: %{name} = %{epoch}:%{version}-%{release}
Requires: libstdc++-devel 

%description
The GNU ccAudio package offers a highly portable C++ class framework for
developing applications which manipulate audio streams and various
disk based audio file formats.  At the moment ccaudio is primarly a class
framework for handling .au, .wav (RIFF), and various .raw audio encoding
formats under Posix and win32 systems, though it may expand to become a
general purpose audio and soundcard support library.  Support for
controlling CD audio devices has recently been added as well as support
for codecs and other generic audio processing services.

%description devel
This package provides the header files and documentation for building
applications that use GNU ccAudio. 

%prep 
%setup
%build
%configure
make %{?_smp_mflags} LDFLAGS="-s" CXXFLAGS="$RPM_OPT_FLAGS"

%install

%makeinstall 

%clean
rm -rf %{buildroot}  

%files
%defattr(-,root,root,0755)
%doc AUTHORS COPYING ChangeLog NEWS README TODO
%dir %{_libdir}/ccaudio2* 
%{_libdir}/*.so.*
%{_libdir}/ccaudio2*/* 
%{_bindir}/*
%{_mandir}/*/* 

%files devel
%defattr(-,root,root,0755)
%{_libdir}/*.a
%{_libdir}/*.so
%{_libdir}/*.la
%{_libdir}/pkgconfig/*.pc
%{_includedir}/cc++/*.h   

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig   

