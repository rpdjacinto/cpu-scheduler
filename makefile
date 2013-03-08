CC        = g++
CCFLAGS   = -ansi -g  

LINK      = g++

cpusched: cpusched.o
	$(LINK) cpusched.o -o cpusched
	rm cpusched.o

cpusched.o: cpu-scheduler-driver.cpp
	$(CC) $(CCFLAGS) -c cpu-scheduler-driver.cpp -o cpusched.o

clean:
	rm -f *.o
	rm -f cpusched
