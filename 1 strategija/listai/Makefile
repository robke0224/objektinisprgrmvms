CC = g++
CFLAGS = -Wall -std=c++17

.PHONY: all clean

all: list1

list1: main.cpp student.cpp 
	$(CC) $(CFLAGS) -O1 $^ -o $@


clean:
	rm -f list1
