# includes
INC = -Itermbox/src/ -Iinclude/

# flags
CFLAGS = -Wall -Wextra -Wconversion -std=c99 -pedantic ${INC}
CPPFLAGS = -D_XOPEN_SOURCE=700 -DVERSION=\"${VERSION}\"
LDFLAGS = -static

# compiler
CC = gcc
