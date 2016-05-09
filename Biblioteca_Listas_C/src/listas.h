
#ifndef LISTAS_H_
#define LISTAS_H_

nodo * crear_nodo(void * estructura);

void encolar(nodo ** un_nodo, nodo ** lista);

void apilar(nodo ** un_nodo, nodo ** lista);

int eliminar(nodo ** lista, int indice);

int size(nodo ** lista);

nodo * busca_contenido_por_indice(nodo ** lista, int indice);

nodo * sacar(nodo ** lista);


#endif /* LISTAS_H_ */
