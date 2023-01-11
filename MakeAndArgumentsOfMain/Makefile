all: mystrings.o help.exe strlength.exe strconcat.exe strcompare.exe
	
help.exe:
	gcc help.c -o help.exe

mystrings.o:
	gcc -c mystrings.c -o mystrings.o

strlength.exe:
	gcc strlength.c  mystrings.o -o strlength.exe

strconcat.exe:
	gcc strconcat.c  mystrings.o -o strconcat.exe

strcompare.exe:
	gcc strcompare.c  mystrings.o -o strcompare.exe

clean:
	del -f *.exe *.o