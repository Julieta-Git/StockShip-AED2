#include <stdio.h>
#include <stdlib.h> 
#include "../lista.h/lista_enlazada.h" 

int main() {
    listaProductos lista;
    inicializarLista(&lista); 

  
    tProducto p1 = {1, "Lapiz", 1000, 50};
    tProducto p2 = {2, "Cuaderno", 3500, 20};

    insertarProducto(&lista, p1);
    insertarProducto(&lista, p2);

    mostrarLista(&lista); 

    liberarLista(&lista);
    return 0;
}
