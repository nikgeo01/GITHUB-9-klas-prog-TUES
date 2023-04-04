
all: tests.exe

dynamicarr.o: dynamicarr.h dynamicarr.c
	gcc -c dynamicarr.c -o dynamicarr.o

tests.exe: dynamicarr.o tests.c
	gcc tests.c dynamicarr.o -o tests.exe 

clean:
	rm -f *.exe *.o