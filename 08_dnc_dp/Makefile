# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Executable name
TARGET = test

# Source files
SRC = binkoef.c fibonacci.c test.c maxmin.c matrix.c
# Header files
HEADERS = binkoef.h fibonacci.h maxmin.h matrix.h

# Object files
OBJ = $(SRC:.c=.o)

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile each object file
binkoef.o: binkoef.c binkoef.h
	$(CC) $(CFLAGS) -c binkoef.c

fibonacci.o: fibonacci.c fibonacci.h
	$(CC) $(CFLAGS) -c fibonacci.c

maxmin.o: maxmin.c maxmin.h
	$(CC) $(CFLAGS) -c maxmin.c

matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c

test.o: test.c $(HEADERS)
	$(CC) $(CFLAGS) -c test.c

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET)

# Rebuild everything
rebuild: clean all