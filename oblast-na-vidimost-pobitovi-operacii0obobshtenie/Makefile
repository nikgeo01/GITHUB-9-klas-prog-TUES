all: robot.exe

robot.exe: bitstate.o robot.c bitstate.h 
	gcc robot.c bitstate.o -o robot.exe

bitstate.o: bitstate.c bitstate.h
	gcc -c bitstate.c -o bitstate.o

clean:
	del -f *.o *.exe