CC = gcc
CFLAGS = -g -Wall -pthread
TARGET = race

all: $(TARGET)

$(TARGET): race.c
	$(CC) $(CFLAGS) -o $(TARGET) race.c

clean:
	rm -f $(TARGET)