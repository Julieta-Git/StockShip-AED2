#include <stdbool.h>
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
        printf("ID: %d | Nombre: %s | Stock: %d | Precio: %.2f\n", 
               actual->producto.id, 
               actual->producto.nombre, 
               actual->producto.stock,
               actual->producto.precio);
               
        actual = (tNodo*)actual->siguiente;
    }
    printf("--------------------\n");
}

void liberarLista(listaProductos* lista) {
    tNodo* actual = lista->head;
    tNodo* siguienteNodo;
    while (actual != NULL) {
        siguienteNodo = (tNodo*)actual->siguiente;
        free(actual);
        actual = siguienteNodo;
    }
    lista->head = NULL;
    lista->tail = NULL;
}

int registrarVenta(listaProductos* lista, int id, int cantidadVendida) {
    if (lista == NULL || cantidadVendida <= 0) {
        printf("Error: datos invalidos para la venta.\n");
        return 0;
    }

    tNodo* encontrado = buscarProducto(lista, id);

    if (encontrado == NULL) {
        printf("ERROR: No existe producto con ID %d\n", id);
        return 0;
    }

    if (encontrado->producto.stock < cantidadVendida) {
        printf("ERROR: Stock insuficiente!\n");
        printf("   Disponible: %d | Solicitado: %d\n", 
               encontrado->producto.stock, cantidadVendida);
        return 0;
    }

    encontrado->producto.stock -= cantidadVendida;

    float ganancia = (encontrado->producto.precio - encontrado->producto.precioCosto) * cantidadVendida;

    printf("\n--- VENTA EXITOSA! ---\n");
    printf("   Producto      : %s\n", encontrado->producto.nombre);
    printf("   Cantidad      : %d\n", cantidadVendida);
    printf("   Precio Unit.  : $%.2f\n", encontrado->producto.precio);
    printf("   Total Venta   : $%.2f\n", encontrado->producto.precio * cantidadVendida);
    printf("   Ganancia Neta : $%.2f\n", ganancia);
    printf("   Stock restante: %d\n\n", encontrado->producto.stock);

    return 1;
}
int eliminarProducto(listaProductos* lista, int id) {
    if (!lista || !lista->head) {
        printf("Error: Lista vacia o invalida.\n");
        return 0;
    }

    tNodo* actual = lista->head;
    tNodo* anterior = NULL;

    if (actual->producto.id == id) {
        lista->head = actual->siguiente;
        
        if (lista->head == NULL) {
            lista->tail = NULL;
        }
        
        free(actual);
        printf(">> Producto ID %d eliminado correctamente.\n", id);
        return 1;
    }

    while (actual != NULL && actual->producto.id != id) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf(">> Error: Producto ID %d no encontrado.\n", id);
        return 0;
    }

    anterior->siguiente = actual->siguiente;

    if (anterior->siguiente == NULL) {
        lista->tail = anterior;
    }

    free(actual);
    printf(">> Producto ID %d eliminado correctamente.\n", id);
    return 1;
}

 int buscarProductoPorNombre(listaProductos *lista, char* nombre) {
    tNodo* actual = lista->head;
    while(actual != NULL) {
        if(strcmp(actual->producto.nombre, nombre) == 0) {
            return 1;
        }
        actual = actual->siguiente;
    }
    return 0; 
}