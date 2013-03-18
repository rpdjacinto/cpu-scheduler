CC = g++
CFLAGS = -c -Wall
LDFLAGS =
SOURCES = cpu-scheduler-driver.cpp file-parser.cpp Pcb.cpp
INCLUDES = file-parser.h
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = cpusched

all: $(SOURCES) $(EXECUTABLE)
		
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o
	rm -rf cpusched

