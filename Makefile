# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# Target executable name
TARGET = game

# Source files and Object files
SRCS = game.c system_utilities.c entities.c rooms.c
OBJS = $(SRCS:.c=.o)
HEADERS = entities.h system_utilities.h rooms.h

# Default rule (built when running 'make')
all: $(TARGET)

# Link object files into final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compile .c files into .o object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Declare non-file targets
.PHONY: all clean
