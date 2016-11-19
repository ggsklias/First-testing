SHELL := /bin/bash

CC := vfcc
ANA_CC := cc

default:
	@echo Pick one of make targets: vfs_fork.exe ntv_fork.exe
	@exit 1

ntv_fork.exe: ntv_main.o vfscode.o
	$(CC) -o $@ $^ $(ANA_LDFLAGS)

test.exe: vfs_main.o vfscode.o
	$(CC) -o $@ $^ $(ANA_LDFLAGS)

ntv_main.o: test.c
	$(ANA_CC) $(ANA_CFLAGS) -o $@ -c $<

vfs_main.o: test.c
	$(CC) $(CFLAGS) -o $@ -c $<

vfscode.o: vfscode.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f ntv_main.o vfs_main.o vfscode.o

clean_all: clean
	rm -f ntv_fork.exe vfs_fork.exe
