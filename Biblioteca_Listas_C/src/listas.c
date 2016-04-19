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
void encolar(struct nodo ** un_nodo, struct nodo ** lista) {
	struct nodo * aux = *lista;
	if(*lista == NULL) {
		*lista = *un_nodo;
		(*lista)->sig = NULL;
	}
	else {
		while(aux->sig != NULL)
			aux = aux->sig;
		aux->sig = *un_nodo;
	}
}

/* mete un nodo o elemento al principio de la lista como pila */
void apilar(struct nodo ** un_nodo, struct nodo ** lista) {
	if(*lista != NULL) {
		struct nodo * aux = *lista;
		(*un_nodo)->sig = aux;
	}
	*lista = *un_nodo;
}

/* elimina el nodo de acuerdo al indice comenzando de 0 y si se paso de rango, no elimina */
int eliminar(struct nodo ** lista, int indice) {
	struct nodo * post = *lista, *ant = post;
	int count = 0;
	while(post != NULL && indice > count) {
		ant = post;
		post = post->sig;
		count++;
	}
	if(indice >= 0 && post != NULL) {
		if(count == 0)
			*lista = ant->sig;
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
int size(struct nodo ** lista) {
	struct nodo * aux = *lista;
	int cont = 0;
	while(aux != NULL) {
		aux = aux->sig;
		cont++;
	}
	return cont;
}

/* retorna el nodo de acuerdo con un indice que recibe por parametro */
struct nodo * busca_contenido_por_indice(struct nodo ** lista, int indice) {
	struct nodo * aux = *lista;
	int i;
	for(i = 0; i < size(lista) ; i++) {
		if(i == indice)
			break;
		aux = aux->sig;
	}
	if(indice >= 0 && indice <= size(lista))
		return aux;
	else
		return NULL;
}

/* elimina el primer elemento (des_encolar y des_apilar), y lo retorna */
struct nodo * sacar(struct nodo ** lista) {
	if(*lista != NULL) {
		struct nodo * aux = *lista;
		*lista = (*lista)->sig;
		aux->sig = NULL;
		return aux;
	}
	else
		return NULL;
}