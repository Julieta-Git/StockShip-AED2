#ifndef TAD_PRODUCTO_H
#define TAD_PRODUCTO_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int id;
    char nombre[50];
    float precio;
    float precioCosto;
    int stock;
} tProducto;


#endif