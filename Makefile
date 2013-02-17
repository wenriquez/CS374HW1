
CC=/usr/bin/gcc
CFLAGS= -g -Wall -I.
LINKFLAGS= -g -Wall

all: Main

Main: main.o data.o print.o tests.o
	$(CC) $(LINKFLAGS) -o Main main.o data.o print.o tests.o

data.o: data.c data.h print.h
	$(CC) $(CFLAGS) -c data.c -o data.o

print.o: print.c print.h data.h
	$(CC) $(CFLAGS) -c print.c -o print.o

tests.o: tests.c tests.h print.h data.h
	$(CC) $(CFLAGS) -c tests.c -o tests.o

main.o: main.c data.h print.h
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f *.o Main

