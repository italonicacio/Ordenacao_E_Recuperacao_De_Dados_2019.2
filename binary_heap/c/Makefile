main: main.o binary_heap.o max_heap.o heapsort.o
	gcc main.o binary_heap.o max_heap.o heapsort.o -o main

main.o: main.c
	gcc -g3 -O0 -Wall -Werror -std=c99 main.c -c

binary_heap.o: binary_heap.c
	gcc -g3 -O0 -Wall -Werror -std=c99 binary_heap.c -c

max_heap.o: max_heap.c
	gcc -g3 -O0 -Wall -Werror -std=c99 max_heap.c -c

heapsort.o: heapsort.c
	gcc -g3 -O0 -Wall -Werror -std=c99 heapsort.c -c

.PHONY: clean

clean:
	rm *.o main