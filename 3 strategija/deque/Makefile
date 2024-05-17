CC = g++
CFLAGS = -Wall -std=c++17

.PHONY: all clean

all: deque3

deque3: main.cpp student.cpp 
	$(CC) $(CFLAGS) -O1 $^ -o $@


clean:
	rm -f deque3
