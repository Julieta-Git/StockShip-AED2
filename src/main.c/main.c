#include<stdio.h>
#include "lista_enlazada.h"

int main(){
	listaProductos lista;
	inicializarLista(&lista);
	
	Producto p1={1, "Lápiz", 1000.00, 50};
	Producto p2={2, "Cuaderno", 3500.00, 20};
	
	insertarProducto(&lista, p1);
	insertarProducto(&lista, p2);

Nodo* actual = lista.cabeza;
    while (actual != NULL) {
        printf("ID: %d, Nombre: %s, Precio: %.2f, Stock: %d\n",
               actual->producto.id, actual->producto.nombre,
               actual->producto.precio, actual->producto.stock);
        actual = actual->siguiente;
    }

    liberarLista(&lista);
    return 0;
}

