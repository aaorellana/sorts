CFLAGS=-Wall -g

all:
	gcc -o mainsorts mainsorts.c Sorts.h Sorts.c -lm

clean:
	rm -f mainsorts