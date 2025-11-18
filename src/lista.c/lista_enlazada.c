#include<stdlib.h>
#include"lista_enlazada.h"

void inicializarLista(listaProductos* lista){
	lista.head=NULL;
}

void insertarProducto(listaProductos* lista,tProducto p){
	Nodo* nuevo=(Nodo*)malloc(sizeof(Nodo));
	if(nuevo==NULL)return;
	nuevo.producto=p;
	nuevo.siguiente=lista.head;
	lista.head=nuevo;
}

void liberarLista(listaProductos* lista){
	Nodo* actual=lista.head;
	while(actual!=NULL){
		Nodo* temp=actual;
		actual=actual.siguiente;
		free(temp);
	}
	lista.head=NULL;
}
