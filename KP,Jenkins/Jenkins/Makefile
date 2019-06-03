all: hashtab_Jenkins

hashtab_Jenkins: main.o hashtab_Jenkins.o
	gcc -Wall -O0 -o main main.o hashtab_Jenkins.o

main.o: main.c
	gcc -c main.c -g -o main.o

hashtab_Jenkins.o: hashtab_Jenkins.c
	gcc -c hashtab_Jenkins.c -g -o hashtab_Jenkins.o

clean:
	rm -rf *.o main.exe