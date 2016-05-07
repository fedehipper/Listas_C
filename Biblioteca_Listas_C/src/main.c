#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "listas.h"

struct t_contenido {
	int un_valor;
	char * un_string;
};

struct t_contenido * llenar(int valor, char * palabra);
void mostrar(struct nodo ** una_lista);


int main(void) {

	struct nodo * uno = crear_nodo(llenar(1, "hola"));
	struct nodo * dos = crear_nodo(llenar(2, "como"));
	struct nodo * tres = crear_nodo(llenar(2, "estas?"));

	struct nodo * una_lista;
	una_lista = NULL;

	encolar(&uno, &una_lista);
	encolar(&dos, &una_lista);
	encolar(&tres, &una_lista);

	printf("tamanio: %d\n", size(&una_lista));

	mostrar(&una_lista);

	int i = 0;
	struct nodo * un_nodo = busca_contenido_por_indice(&una_lista, i);

	if(i <= size(&una_lista) && i >= 0)
		printf("buscar por indice: %d con---> %s", un_nodo->contenido->un_valor, un_nodo->contenido->un_string);

	printf("\nlista desencolar \n\n");

	printf("desencole el numero: %d\n", sacar(&una_lista)->contenido->un_valor);
	printf("desencole el numero: %s\n", sacar(&una_lista)->contenido->un_string);

	mostrar(&una_lista);



	return 0;



}





struct t_contenido * llenar(int valor, char * palabra) {
	struct t_contenido * cont = malloc(sizeof(struct t_contenido));
	cont->un_valor = valor;
	cont->un_string = palabra;
	return cont;
}

void mostrar(struct nodo ** una_lista) {
	struct nodo * aux;
	aux = *una_lista;
	while(aux != NULL) {
		struct t_contenido * con;
		con = aux->contenido;
		printf("%d -----  %s\n", con->un_valor, con->un_string);
		aux = aux->sig;
	}
}
