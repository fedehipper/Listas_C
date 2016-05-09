#ifndef ESTRUCTURAS_H_
#define ESTRUCTURAS_H_


/* t_contenido depende el programa */
typedef struct estructura {
	struct t_contenido * contenido;
	struct estructura * sig;
} nodo;




#endif /* ESTRUCTURAS_H_ */
