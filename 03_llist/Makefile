# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Executable and object files
EXEC = test
OBJS = test.o llist.o

# Default target
all: $(EXEC)

# Rule to build the executable
$(EXEC):$(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Rule to build object files
test.o: test.c llist.h err.h
	$(CC) $(CFLAGS) -c test.c

llist.o: llist.c llist.h err.h
	$(CC) $(CFLAGS) -c llist.c

# Clean target to remove object files and the executable
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets
.PHONY: all clean