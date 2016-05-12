#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"



nodo * crear_nodo(void * estructura) {
	nodo * un_nodo = malloc(sizeof(nodo));
	un_nodo->contenido = estructura;
	un_nodo->sig = NULL;
	return un_nodo;
}

/* retorna la cantidad de nodos de la lista */
int size(nodo ** lista) {
	nodo * aux = malloc(sizeof(nodo));
	aux = *lista;
	int longitud = 0;
	while(aux != NULL) {
		aux = aux->sig;
		longitud++;
	}
	return longitud;
}

/* retorna el nodo de acuerdo con un indice que recibe por parametro */
nodo * busca_por_indice(nodo ** lista, int indice) {
	nodo * aux = malloc(sizeof(nodo));
	aux = *lista;
	int longitud = size(lista), i;
	for(i = 0; i < longitud ; i++) {
		if(i == indice) break;
		aux = aux->sig;
	}
	return indice >= 0 && indice <= longitud ? aux : NULL;
}


/* mete un nodo o elemento al final de la lista como cola */
void encolar(nodo ** un_nodo, nodo ** lista) {
	nodo * ultimo = malloc(sizeof(nodo));
	ultimo = busca_por_indice(lista, size(lista) -1);
	(*un_nodo)->sig = NULL;
	ultimo == NULL ? *lista = *un_nodo : (ultimo->sig = *un_nodo);
}


/* mete un nodo o elemento al principio de la lista como pila */
void apilar(nodo ** un_nodo, nodo ** lista) {
	nodo * aux = malloc(sizeof(nodo));
	aux = *lista;
	if (*lista == NULL) {
		(*un_nodo)->sig = NULL;
		*lista = *un_nodo;
	}
	else {
		(*un_nodo)->sig = aux;
		*lista = *un_nodo;
	}
}


/* elimina el nodo de acuerdo al indice comenzando de 0 y si se paso de rango, no elimina */
void eliminar(nodo ** lista, int indice) {
	nodo * post = malloc(sizeof(nodo)), *ant = malloc(sizeof(nodo));
	post = *lista;
	ant = post;
	int count = 0;
	while(post != NULL && indice > count) {
		ant = post;
		post = (post)->sig;
		count++;
	}
	if(indice >= 0 && post != NULL) {
		if (count == 0)
			*lista = ant->sig;
		ant->sig = count == indice && count != 0 && post->sig == NULL ? NULL : post->sig;
	}
}


/* elimina el primer elemento y lo retorna */
nodo * sacar(nodo ** lista) {
	nodo * aux = malloc(sizeof(nodo));
	aux = *lista;
	if(*lista != NULL) {
		*lista = aux->sig;
		return aux;
	}
	else
		return NULL;
}

/* inserta un elemento de acuerdo a una posicion o indice */
void insertar_por_indice(nodo ** lista, nodo ** elemento, int indice) {
	if(indice == 0)
		apilar(elemento, lista);
	else if(indice == size(lista))
		encolar(elemento, lista);
	else {
		nodo *anterior = malloc(sizeof(nodo));
		nodo * siguiente = malloc(sizeof(nodo));
		anterior = busca_por_indice(lista, indice - 1);
		siguiente = anterior->sig;
		anterior->sig = *elemento;
		(*elemento)->sig = siguiente;
	}
}
