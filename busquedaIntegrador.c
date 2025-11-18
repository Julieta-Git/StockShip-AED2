#include<stdio.h>
#include<stdbool.h>
#include "producto.h"
#include "lista_enlazada.h"

typedef struct{
	int ID;
	char nombre[50];
	float precio;
	int stock;
} tProducto;

typedef struct nodo{
	tProducto producto;
	struct nodo * siguiente;
}tLista;

bool busquedaSecuencialID(tLista*, int);
bool busquedaSecuencialNombre(tLista*, char);


int main(){
	
	return 0;
}

bool buscarProductoPorID(tLista* lista, int elem){
	//algoritmo implementado: busqueda secuencial
	int result = false;
	tLista* listaAux = lista; //variable aux para recorrer
	
	while(listaAux != NULL && listaAux->producto.ID != elem){
		listaAux = listaAux->siguiente;
	}
	if(listaAux->producto.ID == elem){
		return true;
	}
	
	return result;
}

bool buscarProductoPorNombre(tLista* lista, char elem[50]){
	//algoritmo implementado: busqueda secuencial
	bool result = false;
	tLista* listaAux = lista;
	
	while(listaAux != NULL && strcmp(listaAux->producto.nombre, elem) != 0){
		listaAux = listaAux->siguiente;
	}
	if(strcmp(listaAux->producto.nombre, elem) == 0){
		return true;
	}
	
	return result;
}

