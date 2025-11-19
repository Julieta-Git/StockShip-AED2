#include <stdio.h>
#include <stdlib.h>
#include "../producto.h/tad_producto.h" 


void ingresarProducto(listaProductos* lista) {
    tProducto p;
    int idExiste = 0;

    printf("\n--- NUEVO PRODUCTO ---\n");


    do {
        printf("Ingrese ID (numerico): ");
        scanf("%d", &p.id);
        
        if (buscarProducto(lista, p.id) != NULL) {
            printf("Error: El ID %d ya existe. Intente otro.\n", p.id);
            idExiste = 1;
        } else {
            idExiste = 0;
        }
    } while (idExiste);

    printf("Ingrese Nombre: ");
    fflush(stdin); 
    scanf(" %[^\n]", p.nombre); 

    printf("Ingrese Precio Venta: ");
    scanf("%f", &p.precio);
    
    printf("Ingrese Precio Costo: ");
    scanf("%f", &p.precioCosto);

    printf("Ingrese Stock inicial: ");
    scanf("%d", &p.stock);

   
    insertarOrdenado(lista, p);
    printf(">> Producto ingresado y ordenado correctamente.\n");
}

int main() {
    listaProductos lista;
    inicializarLista(&lista);
    int opcion;

    tProducto p1 = {10, "Coca Cola", 1500, 1000, 50};
    tProducto p2 = {1, "Caramelo", 100, 50, 200};
    tProducto p3 = {5, "Alfajor", 800, 400, 20};
    tProducto p4 = {20, "Papas Fritas", 2500, 1200, 15};
    tProducto p5 = {3, "Chicle", 50, 10, 500};

    insertarOrdenado(&lista, p1);
    insertarOrdenado(&lista, p2);
    insertarOrdenado(&lista, p3);
    insertarOrdenado(&lista, p4);
    insertarOrdenado(&lista, p5);

    do {
        printf("\n=== GESTION DE STOCK ===\n");
        printf("1. Ingresar Producto (Tu parte)\n");
        printf("2. Mostrar Productos (Tu parte)\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                ingresarProducto(&lista);
                break;
            case 2:
                mostrarLista(&lista);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while(opcion != 3);

    liberarLista(&lista);
    return 0;
}
