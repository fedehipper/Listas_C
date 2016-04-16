#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"



/* crea el nodo de la estructura enlazada */
struct nodo * crear_nodo(void * estructura) {
	struct nodo * un_nodo = malloc(sizeof(struct nodo));
	un_nodo->contenido = estructura;
	un_nodo->sig = NULL;
	return un_nodo;
}

/* mete un nodo o elemento al final de la lista como cola */
void encolar(struct nodo ** un_nodo, struct nodo ** una_lista) {
	struct nodo * aux = *una_lista;
	if(*una_lista == NULL) {
		*una_lista = *un_nodo;
		(*una_lista)->sig = NULL;
	}
	else {
		while(aux->sig != NULL)
			aux = aux->sig;
		aux->sig = *un_nodo;
	}
}

/* mete un nodo o elemento al principio de la lista como pila */
void apilar(struct nodo ** un_nodo, struct nodo ** una_lista) {
	if(*una_lista != NULL) {
		struct nodo * aux = *una_lista;
		(*un_nodo)->sig = aux;
	}
	*una_lista = *un_nodo;
}

/* elimina el nodo de acuerdo a un indice comenzando de 0 y si se paso de rango,
   mas de lo que tiene la lista o pide un indice menor deja la lista como esta */
int eliminar(struct nodo ** una_lista, int indice) {
	struct nodo * post = *una_lista, *ant = post;
	int count = 0;
	while(post != NULL && indice > count) {
		ant = post;
		post = post->sig;
		count++;
	}
	if(indice >= 0 && post != NULL) {
		if(count == 0)
			*una_lista = ant->sig;
		if(count == indice && count != 0 && post->sig == NULL)
			ant->sig = NULL;
		else
			ant->sig = post->sig;
		return 1;
	}
	else
		return 0;
}

/* retorna la cantidad de nodos o elementos de la lista */
int list_size(struct nodo ** una_lista) {
	struct nodo * aux = *una_lista;
	int cont = 0;
	while(aux != NULL) {
		aux = aux->sig;
		cont++;
	}
	return cont;
}

/* retorna el nodo de acuerdo con un indice que recibe por parametro */
struct nodo * busca_contenido_por_indice(struct nodo ** una_lista, int indice) {
	struct nodo * aux = *una_lista;
	int i;
	for(i = 0; i < list_size(una_lista) ; i++) {
		if(i == indice)
			break;
		aux = aux->sig;
	}
	if(indice >= 0 && indice <= list_size(una_lista))
		return aux;
	else
		return NULL;
}

/* elimina el ultimo primer elemento, y lo retorna */
struct nodo * des_encolar(struct nodo ** una_lista) {
	if(*una_lista != NULL) {
		struct nodo * aux = *una_lista;
		*una_lista = (*una_lista)->sig;
		aux->sig = NULL;
		return aux;
	}
	else
		return NULL;
}

