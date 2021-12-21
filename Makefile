all: mark6 mark6.exe

mark6: mark6.c
	gcc -s -o mark6 mark6.c 

mark6.exe: mark6.c
	i686-w64-mingw32-gcc -o mark6.exe mark6.c -mwindows
	i686-w64-mingw32-strip mark6.exe

clean:
	rm -f mark6 mark6.exe
