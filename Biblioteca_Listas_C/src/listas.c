#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"



nodo * crear_nodo(void * estructura) {
	nodo * un_nodo = malloc(sizeof(nodo));
	un_nodo->contenido = estructura;
	un_nodo->sig = NULL;
	return un_nodo;
}


/* mete un nodo o elemento al final de la lista como cola */
void encolar(nodo ** un_nodo, nodo ** lista) {
	nodo * aux = *lista;
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
void apilar(nodo ** un_nodo, nodo ** lista) {
	if(*lista != NULL) {
		nodo * aux = *lista;
		(*un_nodo)->sig = aux;
	}
	*lista = *un_nodo;
}


/* elimina el nodo de acuerdo al indice comenzando de 0 y si se paso de rango, no elimina */
int eliminar(nodo ** lista, int indice) {
	nodo * post = *lista, *ant = post;
	int count = 0;
	while(post != NULL && indice > count) {
		ant = post;
		post = post->sig;
		count++;
	}
	if(indice >= 0 && post != NULL) {
		*lista = count == 0 ? ant->sig : NULL;
		ant->sig = count == indice && count != 0 && post->sig == NULL ? NULL : post->sig;
		return 1;
	}
	else
		return 0;
}


int size(nodo ** lista) {
	nodo * aux = *lista;
	int longitud = 0;
	while(aux != NULL) {
		aux = aux->sig;
		longitud++;
	}
	return longitud;
}


/* retorna el nodo de acuerdo con un indice que recibe por parametro */
nodo * busca_contenido_por_indice(nodo ** lista, int indice) {
	nodo * aux = *lista;
	int i;
	for(i = 0; i < size(lista) ; i++) {
		if(i == indice) break;
		aux = aux->sig;
	}
	return indice >= 0 && indice <= size(lista) ? aux : NULL;
}


/* elimina el primer elemento (des_encolar y des_apilar), y lo retorna */
nodo * sacar(nodo ** lista) {

	if(*lista != NULL) {
		nodo * aux = *lista;
		*lista = (*lista)->sig;
		aux->sig = NULL;
		return aux;
	}
	else
		return NULL;
}
