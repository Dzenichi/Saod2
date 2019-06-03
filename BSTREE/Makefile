all: bstree

bstree: main.o bstree.o
	gcc -Wall -O0 -o main main.o bstree.o

main.o: main.c
	gcc -c main.c -g -o main.o

bstree.o: bstree.c
	gcc -c bstree.c -g -o bstree.o

clean:
	rm -rf *.o main.exe