all:prog

prog: main.o menu.o
    gcc -g -o prog main.o menu.o

main.o: main.c menu.h
    gcc -g -o main.o main.c -c 

menu.o: menu.c 
    gcc-g -o menu.o menu.c -c 

clean:
    rm -rf *o *~prog

run:
    mingw32-make clean
    ming32-make all
    ./math