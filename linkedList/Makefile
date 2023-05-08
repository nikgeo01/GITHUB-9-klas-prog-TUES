all: priorityList.exe

linkedList.o: linkedList.c linkedList.h
	gcc -c linkedList.c -o linkedList.o

priorityList.exe: priorityList.c linkedList.o
	gcc priorityList.c linkedList.o -o priorityList.exe