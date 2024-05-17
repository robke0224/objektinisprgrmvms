CC = g++
CFLAGS = -Wall -std=c++17

.PHONY: all clean

all: list3

list3: main.cpp student.cpp 
	$(CC) $(CFLAGS) -O1 $^ -o $@


clean:
	rm -f list3
