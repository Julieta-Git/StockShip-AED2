#include <stdio.h>
#include <stdlib.h>
#include "../producto.h/tad_producto.h"

void inicializarLista(listaProductos* lista) {
    lista->head = NULL;
}


tNodo* buscarProducto(listaProductos* lista, int id) {
    tNodo* actual = lista->head;
    while (actual != NULL) {
        if (actual->producto.id == id) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return NULL;
}


int insertarOrdenado(listaProductos* lista, tProducto p) {
    tNodo* nuevo = (tNodo*)malloc(sizeof(tNodo));
    if (nuevo == NULL) return 0; 

    nuevo->producto = p;
    nuevo->siguiente = NULL;


    if (lista->head == NULL || p.id < lista->head->producto.id) {
        nuevo->siguiente = lista->head;
        lista->head = nuevo;
    } 
    else {
       
        tNodo* actual = lista->head;
        while (actual->siguiente != NULL && actual->siguiente->producto.id < p.id) {
            actual = actual->siguiente;
        }
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
    }
    return 1; 
}

void mostrarLista(listaProductos* lista) {
    tNodo* actual = lista->head;
    
    if (actual == NULL) {
        printf("Lista vacia.\n");
        return;
    }

    printf("ID \t NOMBRE \t PRECIO \t STOCK\n");
    while (actual != NULL) {
        printf("%d \t %s \t %.2f \t %d\n",
               actual->producto.id, 
               actual->producto.nombre,
               actual->producto.precio, 
               actual->producto.stock);
        actual = actual->siguiente;
    }
}
void liberarLista(listaProductos* lista) {
    tNodo* actual = lista->head;
    while (actual != NULL) {
        tNodo* temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    lista->head = NULL;
}
