all:prog

prog: main.o menu.o funcionario.o
    gcc -g -o prog main.o menu.o funcionario.o

main.o: main.c menu.h
    gcc -g -o main.o main.c -c 

menu.o: menu.c funcionario.h clinica.h
    gcc -g -o menu.o menu.c -c 

funcionario.o: funcionario.c 
    gcc -g -o funcionario.o funcionario.c -c 

clinica.o: clinica.c 
    gcc -g -o clinica.o clinica.c -c 


clean:
    rm -rf *o *~prog

run:
    mingw32-make clean
    ming32-make all
    ./math