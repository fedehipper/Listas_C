#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "listas.h"

/* estructura solo para este ejemplo, el contenido puede ser otro depende el programa */
struct t_contenido {
	int un_valor;
	char * un_string;
};

struct t_contenido * llenar(int valor, char * palabra) {
	struct t_contenido * cont = malloc(sizeof(struct t_contenido));
	cont->un_valor = valor;
	cont->un_string = palabra;
	return cont;
}

struct t_contenido * devolve_contenido(struct nodo * un_nodo) {
	return un_nodo->contenido;
}


/* muestra el contenido, depende cual sea puede cambiar */
void mostrar(struct nodo ** una_lista) {
	struct nodo * aux = malloc(sizeof(struct nodo));
	aux = *una_lista;
	while(aux != NULL) {
		struct t_contenido * con = malloc(sizeof(struct t_contenido));
		con = aux->contenido;
		printf("%d -----  %s\n", con->un_valor, con->un_string);
		aux = aux->sig;
	}
}



int main(void) {

	struct nodo * uno = crear_nodo(llenar(1, "hola"));
	struct nodo * dos = crear_nodo(llenar(2, "como"));
	struct nodo * tres = crear_nodo(llenar(2, "estas?"));

	struct nodo * una_lista = malloc(sizeof(struct nodo)); // esta vacia
	una_lista = NULL;

	/*encolar(&uno, &una_lista);
	encolar(&dos, &una_lista);
	encolar(&tres, &una_lista);

	printf("se muestran las listas: \n");

	eliminar(&una_lista, 3);
	eliminar(&una_lista, -1);
	mostrar(&una_lista);

	printf("lista con eliminaciones\n");

	eliminar(&una_lista, 2);


	mostrar(&una_lista);


	struct nodo * aux = busca_contenido_por_indice(&una_lista, 1);

	if(aux != NULL)
		printf("busqueda por indice: %d y %s\n", aux->contenido->un_valor, aux->contenido->un_string);

	int tamanio = list_size(&una_lista);

	printf("\ntamanio de la lista: %d\n", tamanio);



	printf("lista con agregar: ");

	eliminar(&una_lista, 0);
	eliminar(&una_lista, 1);
	eliminar(&una_lista, 2);

*/

	encolar(&uno, &una_lista);
	encolar(&dos, &una_lista);
	encolar(&tres, &una_lista);

	printf("tamanio: %d\n", list_size(&una_lista));

	mostrar(&una_lista);

	int i = 0;
	struct nodo * un_nodo = busca_contenido_por_indice(&una_lista, i);

	if(i <= list_size(&una_lista) && i >= 0)
		printf("buscar por indice: %d con---> %s", devolve_contenido(un_nodo)->un_valor, devolve_contenido(un_nodo)->un_string);

	printf("\nlista desencolar \n\n");

	printf("desencole el numero: %d\n", devolve_contenido(des_encolar(&una_lista))->un_valor);
	printf("desencole el numero: %d\n", devolve_contenido(des_encolar(&una_lista))->un_valor);

	mostrar(&una_lista);

	return 0;
}
