VERSION = 0.1

# including a Makefile configuration file - edit only config.mk,
# avoid editions of this file.
include config.mk

LIB = util.c
OBJ = ${LIB:.c=.o}

all: options donstranding

options:
	@echo "donstranding build options:"
	@echo "CC          = ${CC}"
	@echo "CFLAGS      = ${CFLAGS}"
	@echo "CPPFLAGS    = ${CPPFLAGS}"
	@echo "LDFLAGS     = ${LDFLAGS}"

donstrandingc: donstrandingc.c
	${CC} ${CFLAGS} ${CPPFLAGS} -o $@ $<

donstrandingd: donstrandingd.c
	${CC} ${CFLAGS} ${CPPFLAGS} -o $@ $<

donstranding: donstranding.c donstrandingc donstrandingd
	${CC} ${CFLAGS} ${CPPFLAGS} -o $@ $<

clean:
	rm -f ${OBJ} donstranding donstrandingc donstrandingd

.PHONY: all options clean
