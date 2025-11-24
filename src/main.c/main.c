#include <stdio.h>
#include <stdlib.h>
#include "tad_producto.h"
#include "lista_enlazada.h"


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
    int idBuscado;
    char nombreBuscado[50];

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
        printf("3. Buscar producto por ID.\n");
        printf("4. Buscar producto por nombre\n");
        printf("5. Salir\n");
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
                printf("Ingrese el ID que desea buscar: ");
                scanf("%d", &idBuscado); 

                if(buscarProducto(&lista, idBuscado) != NULL){ 
                    printf("El producto con ID %d se encuentra en la lista!\n", idBuscado);
                } else {
                    printf("El producto no se encuentra.\n");
            }
            break;

            case 4:
                printf("Ingrese el nombre que desea buscar: ");
                fflush(stdin); 
                scanf("%[^\n]", nombreBuscado); 

                if(buscarProductoPorNombre(&lista, nombreBuscado)){
                    printf("El producto %s se encuentra en la lista!\n", nombreBuscado);
                } else {
                    printf("El producto no se encuentra!\n");
                }
                break;
                
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while(opcion != 5);

    liberarLista(&lista);
    return 0;
}
