#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H
#include "tad_producto.h"

typedef struct{
	tProducto producto;
	struct Nodo* siguiente;
}tNodo;

typedef struct{
	tNodo* head;
	tNodo* tail;
}listaProductos;

void inicializarLista(listaProductos* lista);
void insertarProducto(listaProductos* lista,tProducto p);
void liberarLista(listaProductos* lista);
void mostrarLista(listaProductos* lista);

#endif
