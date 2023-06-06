
all: library.exe

library.exe: linkedlist.o book.o library.c
	gcc linkedlist.o book.o library.c -o library.exe

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c -o linkedlist.o

book.o: book.c book.h
	gcc -c book.c -o book.o

clean:
	del -f *.o *.exe