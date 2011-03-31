all: mark6 mark6.exe

mark6: mark6.c
	gcc -s -o mark6 mark6.c 

mark6.exe: mark6.c
	i586-mingw32msvc-gcc -o mark6.exe mark6.c -mwindows
	i586-mingw32msvc-strip mark6.exe

clean:
	rm -f mark6 mark6.exe
