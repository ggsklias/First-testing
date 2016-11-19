SHELL := /bin/bash

CC := vfcc
ANA_CC := cc
FLAGS := -pthread
CFLAGS=-c -Wall
LIBSRC=lib.c
LIB=$(patsubst %.c,%.so,$(LIBSRC))
LDFLAGS=-ldl $(ANA_LDFLAGS)

default:
	@exit 1

test.exe: vfs_test.o $(LIB)
	$(CC) $(FLAGS) -o $@ $^ $(LDFLAGS)

vfs_test.o: test.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIB): $(LIBSRC)
	$(CC) -fPIC -shared $< -o $@

clean:
	rm -f vfs_test.o lib.so

clean_all: clean
	rm -f test.exe
