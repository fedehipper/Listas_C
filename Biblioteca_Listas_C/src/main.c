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

	encolar(&uno, &una_lista);
	encolar(&dos, &una_lista);
	encolar(&tres, &una_lista);

	printf("tamanio: %d\n", size(&una_lista));

	mostrar(&una_lista);

	int i = 0;
	nodo * un_nodo = busca_por_indice(&una_lista, i);

	if(i <= size(&una_lista) && i >= 0)
		printf("buscar por indice: %d con---> %s", un_nodo->contenido->un_valor, un_nodo->contenido->un_string);

	printf("\nlista desencolar \n\n");

	printf("desencole el numero: %d\n", sacar(&una_lista)->contenido->un_valor);
	printf("desencole el numero: %s\n", sacar(&una_lista)->contenido->un_string);


	printf("\ninsertar por indice\n");
	encolar(&uno, &una_lista);
	encolar(&dos, &una_lista);
	encolar(&tres, &una_lista);

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
