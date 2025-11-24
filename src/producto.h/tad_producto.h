#ifndef TAD_PRODUCTO_H
#define TAD_PRODUCTO_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;          
    char nombre[50];
    float precio;
    float precioCosto;
    int stock;
} tProducto;

typedef struct nodo {
    tProducto producto;
    struct nodo* siguiente;
} tNodo;

typedef struct {
    tNodo* head;
} listaProductos;

tProducto producto;

void inicializarLista(listaProductos* lista);
void liberarLista(listaProductos* lista);
int insertarOrdenado(listaProductos* lista, tProducto p); 
tNodo* buscarProducto(listaProductos* lista, int id); 
void mostrarLista(listaProductos* lista);

#endif