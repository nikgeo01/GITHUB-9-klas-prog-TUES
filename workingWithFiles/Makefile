
all:eLibrary.exe

eLibrary.exe: eLibrary.c linkedList.o
	gcc linkedList.o -o eLibrary.exe

linkedList.o: linkedList.c linkedList.h
	gcc -c linkedList.c

clean:
	del -f *.exe *.o