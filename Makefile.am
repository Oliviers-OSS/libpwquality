#
# Copyright (c) 2005, 2006, 2007 Thorsten Kukuk <kukuk@thkukuk.de>
# Copyright (c) 2011 Red Hat, Inc.
# Copyright (c) 2011 Tomas Mraz <tm@t8m.info>
# Copyright (c) 2019 Olivier Charloton <oliviers.open.source.softwares@gmail.com>
#

AUTOMAKE_OPTIONS = 1.9 gnu dist-bzip2 check-news

# Temporary work around until the python module build will be fixed during distcheck (work in progress)
AM_DISTCHECK_CONFIGURE_FLAGS = --disable-python-bindings

SUBDIRS = po src doc
if BUILD_PYTHON_BINDINGS
SUBDIRS += python
endif

CLEANFILES = *~

M4_FILES = m4/libtool.m4

EXTRA_DIST = config.rpath $(M4_FILES) libpwqualityex.spec libpwqualityex.spec.in

ACLOCAL_AMFLAGS = -I m4

tag: Makefile
	hg tag libpwqualityex-@PACKAGE_VERSION@

force-tag: Makefile
	hg tag -f libpwqualityex-@PACKAGE_VERSION@
