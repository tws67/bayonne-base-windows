# Copyright (C) 1999-2005 Open Source Telecom Corporation.
#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

AUTOMAKE_OPTIONS = no-dependencies dist-shar
EXTRA_DIST = COPYRIGHT *.h

noinst_HEADER = gsm.h

noinst_LIBRARIES = libgsm.a

libgsm_a_SOURCES = add.c code.c debug.c decode.c \
	gsm_create.c gsm_decode.c gsm_destroy.c gsm_encode.c \
	gsm_explode.c gsm_implode.c gsm_option.c gsm_print.c \
	long_term.c lpc.c preprocess.c rpe.c short_term.c table.c
libgsm_a_CFLAGS = -DSASR -DUSE_FLOAT_MUL -DFAST -DNO_CPP -fPIC -I$(top_srcdir)/gsm
