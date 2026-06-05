# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Executable name
TARGET = test

# Source files
SRC = radix.c lqueue.c test.c
# Header files
HEADERS = radix.h lqueue.h err.h

# Object files
OBJ = $(SRC:.c=.o)

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile each object file
radix.o: radix.c radix.h
	$(CC) $(CFLAGS) -c radix.c

lqueue.o: lqueue.c lqueue.h
	$(CC) $(CFLAGS) -c lqueue.c

test.o: test.c $(HEADERS)
	$(CC) $(CFLAGS) -c test.c

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET)

# Rebuild everything
rebuild: clean all