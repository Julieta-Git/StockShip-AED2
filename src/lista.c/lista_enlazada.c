#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_enlazada.h"

void inicializarLista(listaProductos* lista) {
    lista->head = NULL;
    lista->tail = NULL; 
}

void insertarProducto(listaProductos* lista, tProducto p) {
    tNodo* nuevoNodo = (tNodo*)malloc(sizeof(tNodo));
    if (nuevoNodo == NULL) {
        printf("Error: No hay memoria suficiente.\n");
        return;
    }
    
    // B. Llenar el nodo con los datos
    nuevoNodo->producto = p;
    nuevoNodo->siguiente = NULL; 

    if (lista->head == NULL) {
        lista->head = nuevoNodo;
        lista->tail = nuevoNodo; 
    } else {
        lista->tail->siguiente = (struct Nodo*)nuevoNodo; 
        lista->tail = nuevoNodo;
    }
}

// 3. Mostrar Lista: Recorre e imprime
void mostrarLista(listaProductos* lista) {
    printf("---- INVENTARIO ----\n");
    tNodo* actual = lista->head;

    if (actual == NULL) {
        printf("  (Lista vacia)\n");
    }

    while (actual != NULL) {
        printf("ID: %d | Nombre: %s | Stock: %d | Precio: %.2f\n", 
               actual->producto.id, 
               actual->producto.nombre, 
               actual->producto.stock,
               actual->producto.precio);
               
        // Avanzar al siguiente nodo
        actual = (tNodo*)actual->siguiente;
    }
    printf("--------------------\n");
}

// 4. Liberar Lista: Limpia la memoria al cerrar el programa
void liberarLista(listaProductos* lista) {
    tNodo* actual = lista->head;
    tNodo* siguienteNodo;

    while (actual != NULL) {
        siguienteNodo = (tNodo*)actual->siguiente;
        free(actual); // Borrar el nodo actual
        actual = siguienteNodo; // Avanzar
    }

    lista->head = NULL;
    lista->tail = NULL;
}