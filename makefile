CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: program

program: main.o binary_search.o utils.o
	$(CC) $(CFLAGS) -o program main.o binary_search.o utils.o

main.o: main.c utils.h
	$(CC) $(CFLAGS) -c main.c -o main.o

binary_search.o: binary_search.c utils.h
	$(CC) $(CFLAGS) -c binary_search.c -o binary_search.o

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c -o utils.o

clean:
	rm -f *.o program binary_search.o  utils.o
