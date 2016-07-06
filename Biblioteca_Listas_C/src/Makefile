SOURCES = listas.c main.c cadenas.c
HEADERS = listas.h estructuras.h cadenas.h

main : main.o listas.o cadenas.o
	gcc -o main main.o listas.o cadenas.o

main.o : main.c $(HEADERS)
	gcc -c main.c

listas.o : listas.c $(HEADERS)
	gcc -c listas.c
	
cadenas.o : cadenas.c $(HEADERS)
	gcc -c cadenas.c

clean:
	rm -f main \
		main.o listas.o cadenas.o

send:
		tar zcvf listas.tar $(SOURCES) $(HEADERS) Makefile


