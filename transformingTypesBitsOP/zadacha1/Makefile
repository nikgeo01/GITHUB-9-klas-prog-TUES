all:quadraticroots.o main.exe

quadraticroots.o:
	gcc -c quadraticroots.c -o quadraticroots.o

main.exe:
	gcc -lm main.c quadraticroots.o -o main.exe

clean:
	del -f *.o *.exe