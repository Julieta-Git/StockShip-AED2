#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H
#include "tad_producto.h"

typedef struct{
	Producto producto;
	struct Nodo* siguiente;
}Nodo;

typedef struct{
	Nodo* head;
	Nodo* tail;
}listaProductos;

void inicializarLista(listaProductos* lista);
void insertarProducto(listaProductos* lista,tProducto p);
void liberarLista(listaProductos* lista);

#endif
