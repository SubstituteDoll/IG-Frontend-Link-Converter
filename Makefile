CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c99
TARGET = IGconvert

SRC_DIR = src
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/converter.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

# Debug build target enabling macro expansions
debug: CFLAGS += -DDEBUG -g
debug: clean $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/converter.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all debug clean
