EXEFILE = ducks
CXXFLAGS = -Wall -c -std=c++11
SOURCES = $(wildcard *.cc)
OBJECTS = $(SOURCES:.cc=.o)

$(EXEFILE): $(OBJECTS)
	g++ $^ -o $@

%.o: %.cc
	g++ $(CXXFLAGS) $^ -o $@

clean:
	rm *.o $(EXEFILE)

.PHONY: clean
