main : main.o listas.o
	gcc -o main main.o listas.o

main.o : main.c listas.h estructuras.h
	gcc -c main.c

listas.o : listas.c listas.h estructuras.h
	gcc -c listas.c 

clean:
	rm -f main \
		main.o listas.o
		
