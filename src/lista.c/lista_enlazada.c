#include "lista_enlazada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarLista(listaProductos* lista) {
    lista->head = NULL;
    lista->tail = NULL;
}

tNodo* buscarProducto(listaProductos* lista, int id) {
    tNodo* actual = lista->head;
    while(actual != NULL) {
        if(actual->producto.id == id) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return NULL;
}

void insertarOrdenado(listaProductos* lista, tProducto p) {
    tNodo* nuevo = (tNodo*)malloc(sizeof(tNodo));
    nuevo->producto = p;
    nuevo->siguiente = NULL;

    if (lista->head == NULL || p.id < lista->head->producto.id) {
        nuevo->siguiente = lista->head;
        lista->head = nuevo;
        if (lista->tail == NULL) { 
            lista->tail = nuevo;
        }
    } 
    else {
        tNodo* actual = lista->head;
        while (actual->siguiente != NULL && actual->siguiente->producto.id < p.id) {
            actual = actual->siguiente;
        }
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
        
        if (nuevo->siguiente == NULL) {
            lista->tail = nuevo;
        }
    }
}

void mostrarLista(listaProductos* lista) {
    printf("---- INVENTARIO ----\n");
    tNodo* actual = lista->head;
    if (actual == NULL) printf("  (Vacio)\n");

    while (actual != NULL) {
        printf("ID: %d | Nombre: %s | Stock: %d\n", 
               actual->producto.id, actual->producto.nombre, actual->producto.stock);
        actual = actual->siguiente;
    }
    printf("--------------------\n");
}

void liberarLista(listaProductos* lista) {
    tNodo* actual = lista->head;
    tNodo* sig;
    while (actual != NULL) {
        sig = actual->siguiente;
        free(actual);
        actual = sig;
    }
    lista->head = NULL;
    lista->tail = NULL;
}

int buscarProductoPorNombre(listaProductos* lista, char* nombre) {
    tNodo* actual = lista->head;
    while(actual != NULL) {
        if(strcmp(actual->producto.nombre, nombre) == 0) {
            return 1; 
        }
        actual = actual->siguiente;
    }
    return 0; 
}