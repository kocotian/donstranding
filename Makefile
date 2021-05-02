VERSION = 0.1

# including a Makefile configuration file - edit only config.mk,
# avoid editions of this file.
include config.mk

all: options donstranding

LIB = util.c
OBJ = ${LIB:.c=.o} termbox/bin/termbox.a

# termbox
TERMBOXSRCD=termbox/src
TERMBOXSRCS=$(TERMBOXSRCD)/termbox.c
TERMBOXSRCS+=$(TERMBOXSRCD)/input.c
TERMBOXSRCS+=$(TERMBOXSRCD)/memstream.c
TERMBOXSRCS+=$(TERMBOXSRCD)/ringbuffer.c
TERMBOXSRCS+=$(TERMBOXSRCD)/term.c
TERMBOXSRCS+=$(TERMBOXSRCD)/utf8.c

termbox/bin/termbox.a: ${TERMBOXSRCS}
	cd termbox && make && cd ..

# main
options:
	@echo "donstranding build options:"
	@echo "CC          = ${CC}"
	@echo "CFLAGS      = ${CFLAGS}"
	@echo "CPPFLAGS    = ${CPPFLAGS}"
	@echo "LDFLAGS     = ${LDFLAGS}"

donstrandingc: donstrandingc.c ${OBJ}
	${CC} ${CFLAGS} ${CPPFLAGS} -o $@ $< ${OBJ}

donstrandingd: donstrandingd.c ${OBJ}
	${CC} ${CFLAGS} ${CPPFLAGS} -o $@ $< ${OBJ}

donstranding: donstranding.c donstrandingc donstrandingd ${OBJ}
	${CC} ${CFLAGS} ${CPPFLAGS} -o $@ $< ${OBJ}

clean:
	rm -f ${OBJ} donstranding donstrandingc donstrandingd
	cd termbox && make clean && cd ..

.PHONY: all options clean
