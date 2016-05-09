#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "listas.h"

struct t_contenido {
	int un_valor;
	char * un_string;
};

struct t_contenido * llenar(int valor, char * palabra);
void mostrar(nodo ** una_lista);


int main(void) {
	nodo * uno = crear_nodo(llenar(1, "hola"));
	nodo * dos = crear_nodo(llenar(2, "como"));
	nodo * tres = crear_nodo(llenar(3, "estas?"));

    nodo * una_lista;
	una_lista = NULL;

	mostrar(&una_lista);

	return 0;
}


struct t_contenido * llenar(int valor, char * palabra) {
	struct t_contenido * cont = malloc(sizeof(struct t_contenido));
	cont->un_valor = valor;
	cont->un_string = palabra;
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
