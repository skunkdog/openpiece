CC := gcc
CFLAGS := -Wall -Wextra -O2 -g
LDFLAGS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
SRC := main-stripped.c
OBJ := $(SRC:.c=.o)
TARGET := openpiece-stripped

build: $(OBJ)
	$(CC) $(LDFLAGS) -o $(TARGET) $^

run: 
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)
