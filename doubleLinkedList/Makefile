all: tests.exe

doubleLinkedList.o: doubleLinkedList.c doubleLinkedList.h
	gcc -c doubleLinkedList.c -o doubleLinkedList.o

tests.exe: tests.c doubleLinkedList.o
	gcc tests.c doubleLinkedList.o -o tests.exe

clean:
	del -f *.exe