CC := gcc
CFLAGS := -Wall -Wextra -O2 -g
LDFLAGS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
SRC1 := main.c
SRC2 := main-stripped.c
OBJ1 := $(SRC1:.c=.o)
OBJ2 := $(SRC2:.c=.o)
TARGET1 := openpiece
TARGET2 := openpiece-stripped

$(TARGET1): $(OBJ1)
	$(CC) $(LDFLAGS) -o $@ $^

$(TARGET2): $(OBJ2)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

run1: $(TARGET1)
	./$(TARGET1)

run2: $(TARGET2)
	./$(TARGET2)

clean:
	rm -f *.o $(TARGET1) $(TARGET2)
