CC = g++
CFLAGS = -c -Wall
LDFLAGS =
SOURCES = cpu-scheduler-driver.cpp file-parser.cpp Pcb.cpp scheduling-algorithm.cpp shortest-previous-burst.cpp first-in-first-out.cpp gantt.cpp shortest-job-first.cpp impatient-priority.cpp polite-priority.cpp priority-npr.cpp
INCLUDES = file-parser.h pcb.h scheduling-algorithm.h shortest-previous-burst.h first-in-first-out.h gantt.h shortest-job-first.h
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = cpusched

all: $(SOURCES) $(EXECUTABLE)
		
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	rm -rf *.o

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o
	rm -rf cpusched

