CC = g++
CFLAGS = -c -Wall
LDFLAGS =
SOURCES = round-robin.cpp cpu-scheduler-driver.cpp file-parser.cpp Pcb.cpp scheduling-algorithm.cpp shortest-previous-burst.cpp first-in-first-out.cpp gantt.cpp shortest-job-first.cpp impatient-priority.cpp polite-priority.cpp priority-npr.cpp
INCLUDES = -I./INCLUDES
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = cpusched

all: $(SOURCES) $(EXECUTABLE)
		
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	rm -rf *.o

.cpp.o:
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o
	rm -rf cpusched

