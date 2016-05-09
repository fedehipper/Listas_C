#ifndef LISTAS_H_
#define LISTAS_H_

nodo * crear_nodo(void * estructura);

int size(nodo ** lista);

nodo * busca_por_indice(nodo ** lista, int indice);

void encolar(nodo ** un_nodo, nodo ** lista);

void apilar(nodo ** un_nodo, nodo ** lista);

void eliminar(nodo ** lista, int indice);

nodo * sacar(nodo ** lista);

void insertar_por_indice(nodo ** lista, nodo ** elemento, int indice);


#endif /* LISTAS_H_ */
