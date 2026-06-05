# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Executable and object files
EXEC = test
OBJS = test.o lstack.o

# Default target
all: $(EXEC)

# Rule to build the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Rule to build object files
test.o: test.c lstack.h err.h
	$(CC) $(CFLAGS) -c test.c

lstack.o: lstack.c lstack.h err.h
	$(CC) $(CFLAGS) -c lstack.c

# Clean target to remove object files and the executable
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets
.PHONY: all clean