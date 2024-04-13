all:
	gcc main.c insertion_sort.c quick_sort.c selection_sort.c -o main.o

debug:
	gcc -DDEBUG main.c insertion_sort.c quick_sort.c selection_sort.c -o main.o
