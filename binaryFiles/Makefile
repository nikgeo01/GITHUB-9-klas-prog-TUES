
all: statistics.c

statistics.c: citizen.o linkedlist.o
	gcc citizen.o linkedlist.o statistics.c -o statistics.exe

citizen.o: citizen.h citizen.c
	gcc -c citizen.c -o citizen.o

linkedlist.o: linkedlist.h linkedlist.c
	gcc -c linkedlist.c -o linkedlist.o

clean:
	del -f *.o *.exe