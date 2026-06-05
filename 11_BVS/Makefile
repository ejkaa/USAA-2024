# Compiler settings
CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -g
LDFLAGS=-lm

# Target executable name
TARGET=test

# Source files
SOURCES=test.c BVS.c
HEADERS=BVS.h

# Object files
OBJECTS=$(SOURCES:.c=.o)

# Main target
all: $(TARGET)

# Linking the target executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Compiling source files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target for removing compiled files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Phony targets
.PHONY: all clean