CC=g++
CFLAGS=-c -g -ggdb -Wall -std=gnu++1z
LDFLAGS=-g -ggdb
SOURCES=main.cc smart_pointer.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=a.out

all: $(SOURCES) $(EXECUTABLE) tags
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o a.out tags

tags: $(SOURCES)
	ctags *.cc *.h
