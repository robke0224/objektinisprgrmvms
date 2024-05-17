CC = g++
CFLAGS = -Wall -std=c++17

.PHONY: all clean

all: list2

list2: main.cpp student.cpp 
	$(CC) $(CFLAGS) -O1 $^ -o $@


clean:
	rm -f list2
