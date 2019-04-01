# CSCI3081 C++ Templates

CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++14 $(DEBUG)

LFLAGS = -Wall $(DEBUG)
OBJS = main.o circle.o math_vector.o

all: $(OBJS)
	$(CC) $(LFLAGS) -o data $(OBJS)

%.o : %.cc
	$(CC) $(CFLAGS) -o $@ $<

clean:
	\rm *.o *.*~ data
