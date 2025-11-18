#define TAD_PRODUCTO_H
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int ID;
	char nombre[50];
	float precio;
	float precioCosto;
	int stock;
} tProducto;

typedef struct nodo{
    tProducto producto;
    struct nodo* siguiente;
}tNodo;

typedef tNodo * listaProductos;

FILE *archivo;

void inicializarProducto(tProducto *p, int id, char *nombre,float precio, int stock, float precioCosto){
	p->ID= id;
	strncpy(p->nombre, nombre, 49);//para q no llegue al ovwrflow
	p->nombre[49] ='\0';
	p->precio = precio;
	p->stock = stock;
	p->precioCosto = precioCosto;
}

// codigo de meli para abajo
void insertarProducto(tProducto producto, tNodo *pLista){
    tNodo* nuevoNodo = (tNodo*) malloc (sizeof(tNodo));
    nuevoNodo->producto = producto;
    nuevoNodo->siguiente = pLista;
    pLista = nuevoNodo;
}


void mostrarLista(tNodo* pLista){
    printf("---- INVENTARIO ACTUAL ----\n");
    tNodo* actual = pLista;
    if(actual == NULL){
        printf("El inventario esta vacio\n");
    }
    while(actual != NULL){
        printf("ID: %d \t| Nombre: %s \t| Stock: %d \t| Precio Venta: %.2f \t| Precio Costo: %.2f\n",
               actual->producto.ID,
               actual->producto.nombre,
               actual->producto.stock,
               actual->producto.precio,
               actual->producto.precioCosto);
        actual = actual->siguiente;
    }
    printf("--------------------------------\n");
}

void liberarLista(tNodo *pLista){
    tNodo* actual = pLista;
    tNodo* aux;
    while(actual != NULL){
        aux = actual;
        actual = actual->siguiente;
        free(aux);
    }
    pLista = NULL;
}

void registrarVenta(listaProductos lista, int idProducto, int cantidad){
    printf("---- REGISTRAR VENTA ----\n");
    printf("ID: %d \t| Cantidad: %d\n", idProducto, cantidad);
    
    tProducto* productoAVender = buscarProducto(lista, idProducto);

    if(productoAVender == NULL){
        printf("ERROR! Producto con ID %d no encontrado\n", idProducto);
        return;
    }

    if(productoAVender->stock >= cantidad){
        productoAVender->stock -= cantidad;
        float ganancia = (productoAVender->precio - productoAVender->precioCosto) * cantidad;
        printf("VENTA EXITOSA! Producto: %s | Ganancia: %.2f | Nuevo Stock: %d\n",
               productoAVender->nombre,
               ganancia,
               productoAVender->stock);
    } else {
        printf("ERROR! Stock insuficiente para %s, Stock actual: %d, Pedido: %d\n",
               productoAVender->nombre,
               productoAVender->stock,
               cantidad);
    }
}


void guardarProductos(tNodo* lista, const char* nombreArchivo){
    archivo = fopen(nombreArchivo, "wb");
    if(archivo == NULL){
        perror("Error al abrir el archivo para guardar productos");
        return;
    }

    tNodo* actual = lista;
    while(actual != NULL){
        fwrite(&actual->producto, sizeof(tProducto), 1, archivo);
        actual = actual->siguiente;
    }
    fclose(archivo);
    printf("Productos guardados exitosamente en %s\n", nombreArchivo);
}

void cargarProductos(tNodo* lista, const char* nombreArchivo){
    archivo = fopen(nombreArchivo, "rb");
    if(archivo == NULL){
        printf("Archivo %s no encontrado\n", nombreArchivo);
        return;
    }
    
    tProducto prodLeido;
    
    while (fread(&prodLeido, sizeof(tProducto), 1, archivo) == 1) { 
        insertarProducto(lista, prodLeido); 
    }

    fclose(archivo);
    printf("Productos cargados exitosamente desde %s\n", nombreArchivo);
}
