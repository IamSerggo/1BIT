CC=gcc
CFLAGS=-O2 -std=c99 -lm -Wall -pedantic

all: primes primes-i steg-decode

steg-decode: steg-decode.c error.c eratosthenes.c bit_array.h
	$(CC) $(CFLAGS) steg-decode.c -o steg-decode -lm

primes: primes.c error.c eratosthenes.c bit_array.h
	$(CC) $(CFLAGS) primes.c -o primes -lm

primes-i: primes.c error.c eratosthenes.c bit_array.h
	$(CC) $(CFLAGS) -DUSE_INLINE primes.c -o primes-i -lm

run: primes primes-i
	time ./primes
	time ./primes-i

clean:
	rm -f steg-decode primes primes-i xbabic09.zip

zip: *.c *.h Makefile
	zip xbabic09.zip *.c *.h Makefile
