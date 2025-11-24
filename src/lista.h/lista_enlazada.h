#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H
#include "tad_producto.h" 

typedef struct nodo_tag {
    tProducto producto;
    struct nodo_tag* siguiente;
} tNodo;

typedef struct {
    tNodo* head;
    tNodo* tail;
} listaProductos;

void inicializarLista(listaProductos* lista);
void insertarOrdenado(listaProductos* lista, tProducto p); 
tNodo* buscarProducto(listaProductos* lista, int id);    
int buscarProductoPorNombre(listaProductos* lista, char* nombre); 
void mostrarLista(listaProductos* lista);
void liberarLista(listaProductos* lista);

#endif