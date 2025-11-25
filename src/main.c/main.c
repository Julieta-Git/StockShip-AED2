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
    // -----------------------------------

    do {
        printf("\n=== GESTION DE STOCK ===\n");
      printf("1. Ingresar Producto\n");
        printf("2. Mostrar Productos\n");
        printf("3. Buscar producto por ID\n");
        printf("4. Buscar producto por Nombre\n");
        printf("5. Registrar Venta\n");
        printf("6. Eliminar Producto\n");
        printf("7. Salir\n");             
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
                printf("\n--- BUSCAR POR ID ---\n");
                printf("Ingrese el ID que desea buscar: ");
                scanf("%d", &idBuscado); 

                tNodo* nodoEnc = buscarProducto(&lista, idBuscado);
                if(nodoEnc != NULL){ 
                    printf(">> ENCONTRADO: %s (Stock: %d | Precio: $%.2f)\n", 
                           nodoEnc->producto.nombre, 
                           nodoEnc->producto.stock, 
                           nodoEnc->producto.precio);
                } else {
                    printf(">> El producto no se encuentra.\n");
                }
                break;

            case 4:
                printf("\n--- BUSCAR POR NOMBRE ---\n");
                printf("Ingrese el nombre que desea buscar: ");
                fflush(stdin); 
                scanf(" %[^\n]", nombreBuscado); 

                if(buscarProductoPorNombre(&lista, nombreBuscado)){
                    printf(">> El producto '%s' se encuentra en la lista!\n", nombreBuscado);
                } else {
                    printf(">> El producto no se encuentra!\n");
                }
                break;
                
            case 5:
                {
                    int idVenta, cantVenta;
                    printf("\n--- REGISTRAR VENTA ---\n");
                    printf("ID del producto a vender: ");
                    scanf("%d", &idVenta);
                    printf("Cantidad a vender: ");
                    scanf("%d", &cantVenta);
                    
                    registrarVenta(&lista, idVenta, cantVenta);
                }
                break;

           case 6:
            {
                int idEliminar;
                printf("\n--- ELIMINAR PRODUCTO ---\n");
                printf("Ingrese el ID del producto a eliminar: ");
                scanf("%d", &idEliminar);
                eliminarProducto(&lista, idEliminar);
            }
            break;

            case 7:
                printf("Saliendo del sistema...\n");
                break;
                
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while(opcion != 7);

    liberarLista(&lista);
    return 0;
}