# CSCI3081 decorator exercise makefile

EXEFILE = coffee
CC = g++
DEBUG = -g
CXXFLAGS = -Wall -c -std=c++11 $(DEBUG)
SOURCES = $(wildcard *.cc)
OBJECTS = $(SOURCES:.cc=.o)

$(EXEFILE): $(OBJECTS)
	g++ $^ -o $@

%.o: %.cc
	g++ $(CXXFLAGS) $^ -o $@

clean:
	\rm -f *.o $(EXEFILE)

.PHONY: clean
