CC := gcc
CFLAGS := -Wall -Wextra -O2 -g
LDFLAGS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)
TARGET := openpiece

.PHONY: all clean run rebuild

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

rebuild: clean all
