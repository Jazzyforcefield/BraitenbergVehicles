# CSCI3081 cart exercise makefile

CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: main.o order.o
	$(CC) $(LFLAGS) main.o order.o -o cart

main.o : main.cc cart_entry.h cart_contents.h order.h
	$(CC) $(CFLAGS) main.cc -o main.o

order.o: order.h
	$(CC) $(CFLAGS) order.cc -o order.o

clean:
	\rm *.o *.*~ cart
