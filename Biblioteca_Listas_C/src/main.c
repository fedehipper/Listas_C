#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "listas.h"
#include <stdarg.h>


#define contenido_length 2

struct t_contenido {
	int un_valor;
	char * un_string;
};


struct t_contenido * llenar(int longitud, ... );
void mostrar(nodo ** una_lista);
nodo * new(int valor, char * cadena);

/*---------------------------------------------------------------------------------*/

int main(void) {
	nodo * uno = new(1, "hola");
	nodo * dos = new(2, "como");
	nodo * tres = new(3, "estas?");

    nodo * una_lista;
	una_lista = NULL;

	insertar_por_indice(&una_lista, &uno, 0);
	insertar_por_indice(&una_lista, &dos, 1);
	nodo * otro = new(1, "chau");
	insertar_por_indice(&una_lista, &otro , 0);
	insertar_por_indice(&una_lista, &tres, 1);

	mostrar(&una_lista);

	return EXIT_SUCCESS;
}

/*---------------------------------------------------------------------------------*/

nodo * new(int valor, char * cadena) {
	return crear_nodo(llenar(contenido_length, valor, cadena));
}

struct t_contenido * llenar(int longitud, ... ) {
	struct t_contenido * contenido = malloc(sizeof(struct t_contenido));
	va_list args;
	va_start(args, longitud);
	contenido->un_valor = va_arg(args, int);
	contenido->un_string = va_arg(args, char *);
	return contenido;
}

void mostrar(nodo ** una_lista) {
	nodo * aux = *una_lista;
	while(aux != NULL) {
		printf("%d -----  %s\n", aux->contenido->un_valor, aux->contenido->un_string);
		aux = aux->sig;
	}
}
