
#ifndef LISTAS_H_
#define LISTAS_H_

struct nodo * crear_nodo(void * estructura);

void encolar(struct nodo ** un_nodo, struct nodo ** lista);

void apilar(struct nodo ** un_nodo, struct nodo ** lista);

int eliminar(struct nodo ** lista, int indice);

int size(struct nodo ** lista);

struct nodo * busca_contenido_por_indice(struct nodo ** lista, int indice);

struct nodo * sacar(struct nodo ** lista);


#endif /* LISTAS_H_ */
