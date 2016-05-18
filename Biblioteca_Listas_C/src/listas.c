#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"

nodo * crear_nodo(void * estructura) {
	nodo * un_nodo = malloc(sizeof(nodo));
	un_nodo->contenido = estructura;
	un_nodo->sig = NULL;
	return un_nodo;
}

int size(nodo ** lista) {
	nodo * aux = *lista;
	int length = 0;
	while(aux != NULL) {
		aux = aux->sig;
		length++;
	}
	return length;
}

nodo * busca_por_indice(nodo ** lista, int indice) {
	nodo * aux = *lista;
	int i, length = size(lista);
	for(i = 0 ; i < length ; i++) {
		if(i == indice)
			break;
		aux = aux->sig;
	}
	return indice >= 0 && indice <= length ? aux : NULL;
}

/* mete un nodo al final de la lista */
void encolar(nodo ** un_nodo, nodo ** lista) {
	nodo * ultimo = busca_por_indice(lista, size(lista) -1);
	(*un_nodo)->sig = NULL;
	ultimo == NULL ? *lista = *un_nodo : (ultimo->sig = *un_nodo);
}

/* mete un nodo al principio de la lista */
void apilar(nodo ** un_nodo, nodo ** lista) {
	nodo * aux = *lista;
	if (*lista == NULL) {
		(*un_nodo)->sig = NULL;
		*lista = *un_nodo;
	}
	else {
		(*un_nodo)->sig = aux;
		*lista = *un_nodo;
	}
}

void eliminar(nodo ** lista, int indice) {
	nodo * post = *lista, *ant = *lista;
	int count = 0;
	while(post != NULL && indice > count) {
		ant = post;
		post = post->sig;
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
	nodo * aux = *lista;
	if(*lista != NULL) {
		*lista = aux->sig;
		return aux;
	}
	else
		return NULL;
}

void insertar_por_indice(nodo ** lista, nodo ** elemento, int indice) {
	if(indice == 0)
		apilar(elemento, lista);
	else if(indice == size(lista))
		encolar(elemento, lista);
	else {
		nodo * anterior = busca_por_indice(lista, indice - 1);
		nodo * siguiente = anterior->sig;
		anterior->sig = *elemento;
		(*elemento)->sig = siguiente;
	}
}

void reverse(nodo ** lista) {
	nodo * list_aux = NULL;
	int length = size(lista), i;
	for(i = 0 ; i < length ; i++) {
		nodo * nodo_aux = crear_nodo(busca_por_indice(lista, i)->contenido);
		apilar(&nodo_aux, &list_aux);
	}
	*lista = list_aux;
}
