CC = gcc
CXX=g++
OBJ = main.o binary_heap.o sll.o graph.o
FLAGS = -g3 -O0  -Werror -std=c++11
OFLAGS = -O2 -Wall -Werror -std=c++11

main: $(OBJ) 
	$(CXX) $(OBJ) -o main

main.o: main.cpp
	$(CXX) $(FLAGS) main.cpp -c

binary_heap.o: binary_heap.cpp
	$(CXX) $(FLAGS) binary_heap.cpp -c

sll.o: sll.cpp
	$(CXX) $(FLAGS) sll.cpp -c

graph.o: graph.cpp
	$(CXX) $(FLAGS) graph.cpp -c

.PHONY: clean

clean:
	rm *.o main