# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Executable and object files
EXEC = test
OBJS = test.o graph.o lqueue.o

# Default target
all: $(EXEC)

# Rule to build the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) -lm

# Rule to build object files
test.o: test.c graph.h err.h lqueue.h
	$(CC) $(CFLAGS) -c test.c

graph.o: graph.c graph.h err.h lqueue.h
	$(CC) $(CFLAGS) -c graph.c

lqueue.o: lqueue.c graph.h err.h lqueue.h
	$(CC) $(CFLAGS) -c lqueue.c

# Clean target to remove object files and the executable
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets
.PHONY: all clean