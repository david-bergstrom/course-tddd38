CC=g++
CFLAGS=-c -Wall -std=gnu++1z
LDFLAGS=
SOURCES=main.cc smart_pointer.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=a.out

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o a.out
