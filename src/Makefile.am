#
# Copyright (c) 2005, 2006, 2007, 2009 Thorsten Kukuk <kukuk@thkukuk.de>
# Copyright (c) 2011 Red Hat, Inc.
# Copyright (c) 2011 Tomas Mraz <tm@t8m.info>
# Copyright (c) 2019 Olivier Charloton <oliviers.open.source.softwares@gmail.com>
#

CLEANFILES = *~

securelibdir = @SECUREDIR@

secureconfdir = @SCONFIGDIR@

EXTRA_DIST = libpwquality.map pwquality.conf pwqualityex.pc

include_HEADERS = pwquality.h

noinst_HEADERS = pwqprivate.h klist.h ModuleVersionInfo.h

if HAVE_LD_VERSION_SCRIPT
  libpwqualityex_version_script = -Wl,--version-script=$(srcdir)/libpwquality.map
else
  libpwqualityex_version_script =
endif

libpwqualityex_la_CPPFLAGS = `pkg-config --cflags libpcre`

libpwqualityex_la_LDFLAGS = `pkg-config --libs libpcre`
libpwqualityex_la_LDFLAGS += -no-undefined $(libpwqualityex_version_script) \
	-version-info @pwqualityex_LT_CURRENT@:@pwqualityex_LT_REVISION@:@pwqualityex_LT_AGE@
libpwqualityex_la_LDFLAGS += -Wl,-e,displayVersionInfo

libpwqualityex_la_LIBADD = $(LIBCRACK) $(LIBINTL)

libpwqualityex_la_SOURCES = generate.c check.c settings.c error.c version.c

if HAVE_PAM
  pam_pwqualityex_la_LDFLAGS = -no-undefined -avoid-version -module
  pam_pwqualityex_la_LIBADD = libpwqualityex.la $(PAM_LIBS) $(LIBINTL)
  pam_pwqualityex_la_SOURCES = pam_pwquality.c
else
  pam_pwqualityex_la_LDFLAGS =
  pam_pwqualityex_la_LIBADD =
  pam_pwqualityex_la_SOURCES =
endif

pwscore_SOURCES = pwscore.c

pwscore_LDADD = libpwqualityex.la $(LIBINTL)

pwmake_SOURCES = pwmake.c

pwmake_LDADD = libpwqualityex.la $(LIBINTL)

lib_LTLIBRARIES = libpwqualityex.la

if HAVE_PAM
  securelib_LTLIBRARIES = pam_pwqualityex.la
else
  securelib_LTLIBRARIES =
endif

secureconf_DATA = pwquality.conf

bin_PROGRAMS = pwscore pwmake

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = pwqualityex.pc
