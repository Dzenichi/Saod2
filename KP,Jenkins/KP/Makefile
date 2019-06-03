all: hashtab_KR

hashtab_KR: main.o hashtab_KR.o
	gcc -Wall -O0 -o main main.o hashtab_KR.o

main.o: main.c
	gcc -c main.c -g -o main.o

hashtab_KR.o: hashtab_KR.c
	gcc -c hashtab_KR.c -g -o hashtab_KR.o

clean:
	rm -rf *.o main.exe