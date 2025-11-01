CC = gcc
CFLAGS = -Wall -std=c18 -ggdb
LDFLAGS = -lm

test: isPrime
	./isPrime

isPrime: isPrime.c
	$(CC) $(CFLAGS) -o isPrime isPrime.c ${LDFLAGS}

clean:
	-rm isPrime
