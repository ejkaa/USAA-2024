# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Executable name
TARGET = test

# Source files
SRC = heapsort.c quicksort.c test.c sort.c
# Header files
HEADERS = heapsort.h quicksort.h sort.h

# Object files
OBJ = $(SRC:.c=.o)

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile each object file
heapsort.o: heapsort.c heapsort.h
	$(CC) $(CFLAGS) -c heapsort.c

quicksort.o: quicksort.c quicksort.h
	$(CC) $(CFLAGS) -c quicksort.c

sort.o: sort.c sort.h
	$(CC) $(CFLAGS) -c sort.c

test.o: test.c $(HEADERS)
	$(CC) $(CFLAGS) -c test.c

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET)

# Rebuild everything
rebuild: clean all