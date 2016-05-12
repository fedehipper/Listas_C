#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "listas.h"

struct t_contenido {
	int un_valor;
	char * un_string;
};

struct t_contenido * llenar(int valor, char * cadena);
void mostrar(nodo ** una_lista);
nodo * new(int valor, char * cadena);


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


/*-----------------------------------------------------------------*/

nodo * new(int valor, char * cadena) {
	return crear_nodo(llenar(valor, cadena));
}

struct t_contenido * llenar(int valor, char * cadena) {
	struct t_contenido * cont = malloc(sizeof(struct t_contenido));
	cont->un_valor = valor;
	cont->un_string = cadena;
	return cont;
}

void mostrar(nodo ** una_lista) {
	nodo * aux;
	aux = *una_lista;
	while(aux != NULL) {
		struct t_contenido * con;
		con = aux->contenido;
		printf("%d -----  %s\n", con->un_valor, con->un_string);
		aux = aux->sig;
	}
}
