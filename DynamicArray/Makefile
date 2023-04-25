
all: donors.exe

dynamicarr.o: dynamicarr.h dynamicarr.c
	gcc -c dynamicarr.c -o dynamicarr.o

donors.exe: dynamicarr.o donors.c
	gcc donors.c dynamicarr.o -o donors.exe 

clean:
	rm -f *.exe *.o