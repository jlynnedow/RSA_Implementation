CC = gcc
CFLAGS = -Wall -std=c18 -ggdb
LDFLAGS = -lm

test: rsa input.txt
	./rsa <input.txt

rsa: rsa.c tools.c tools.h rsa.h
	$(CC) $(CFLAGS) -o rsa rsa.c tools.c

clean:
	-rm rsa
