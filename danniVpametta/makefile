all:safeint.o safeadd.exe safesubtract.exe safedivide.exe safemultiply.exe

safeint.o:
	gcc -c safeint.c -o safeint.o
	
safeadd.exe:
	gcc safeadd.c safeint.o -o safeadd.exe

safesubtract.exe:
	gcc safesubtract.c safeint.o -o safesubtract.exe

safedivide.exe:
	gcc safedivide.c safeint.o -o safedivide.exe

safemultiply.exe:
	gcc safemultiply.c safeint.o -o safemultiply.exe

clean:
	del -f *.o *.exe