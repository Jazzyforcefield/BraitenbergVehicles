# CSCI3081 robot exercise makefile

CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: main.o legged_robot.o
	$(CC) $(LFLAGS) main.o legged_robot.o -o robot

main.o : main.cc
	$(CC) $(CFLAGS) main.cc -o main.o

legged_robot.o : legged_robot.cc
	$(CC) $(CFLAGS) legged_robot.cc -o legged_robot.o

clean:
	\rm -f *.o *.*~ robot
