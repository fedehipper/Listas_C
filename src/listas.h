
#ifndef LISTAS_H_
#define LISTAS_H_

struct nodo * crear_nodo(void * estructura);

void encolar(struct nodo ** un_nodo, struct nodo ** lista);

void apilar(struct nodo ** un_nodo, struct nodo ** una_lista);

int eliminar(struct nodo ** una_lista, int indice);

int list_size(struct nodo ** una_lista);

struct nodo * busca_contenido_por_indice(struct nodo ** una_lista, int indice);

struct nodo * des_encolar(struct nodo ** una_lista);


#endif /* LISTAS_H_ */
