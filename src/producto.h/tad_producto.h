#indef TAD_PRODUCTO_H
#define TAD_PRODUCTO_H
#include<string.h>

typedef struct{
	int ID;
	char nombre[50];
	float precio;
	int stock;
} Producto;

void inicializarProducto(Producto *p, int id, char *nombre,float precio, int stock){
p.ID= id;
strncpy(p.nombre, nombre, 49);//para q no llegue al ovwrflow
p.nombre[49]='\0';
p.precio=precio;
p.stock=stock;	
}

#endif
