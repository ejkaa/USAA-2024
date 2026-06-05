# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Executable and object files
EXEC = test
OBJS = test.o tree_arr.o

# Default target
all: $(EXEC)

# Rule to build the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) -lm

# Rule to build object files
test.o: test.c tree_arr.h err.h
	$(CC) $(CFLAGS) -c test.c

tree_arr.o: tree_arr.c tree_arr.h err.h
	$(CC) $(CFLAGS) -c tree_arr.c

# Clean target to remove object files and the executable
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets
.PHONY: all clean