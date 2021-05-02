VERSION = 0.1

# including a Makefile configuration file - edit only config.mk,
# avoid editions of this file.
include config.mk

all: options donstranding

options:
	@echo "donstranding build options:"
	@echo "CC          = ${CC}"
	@echo "CFLAGS      = ${CFLAGS}"
	@echo "CPPFLAGS    = ${CPPFLAGS}"
	@echo "LDFLAGS     = ${LDFLAGS}"

.PHONY: all options
