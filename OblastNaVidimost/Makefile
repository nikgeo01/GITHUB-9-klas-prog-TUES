all: taskmanager.exe

taskmanager.exe: taskmanager.c processes.o processes.h
	gcc taskmanager.c processes.o -o taskmanager.exe

processes.o: processes.c processes.h
	gcc -c processes.c -o processes.o

clean:
	del -f *.o *.exe