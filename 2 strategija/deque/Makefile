CC = g++
CFLAGS = -Wall -std=c++17

.PHONY: all clean

all: deque2

deque2: main.cpp student.cpp 
	$(CC) $(CFLAGS) -O1 $^ -o $@


clean:
	rm -f deque2
