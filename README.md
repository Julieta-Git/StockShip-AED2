# StockShip - Sistema de Gestión de Stock y Logística

> Trabajo Práctico Integrador - Algoritmos y Estructuras de Datos II

**StockShip** es una aplicación de consola desarrollada en lenguaje C diseñada para la gestión eficiente de inventarios. Utiliza estructuras de datos dinámicas (Listas Enlazadas) y persistencia en archivos binarios para administrar productos, controlar el stock y registrar movimientos.

---

## Integrantes del Grupo

* **Melina Sarli Ochat**
* **Emily Giuliana Scher**
* **Juliana Maillen Riquelme Griffith**
* **Julieta Estefania Romero**

---

## Funcionalidades Principales

El sistema permite realizar las siguientes operaciones a través de un menú interactivo:

* ** Alta de Productos:** Ingreso de nuevos productos manteniendo el ordenamiento automático por ID.
* ** Búsqueda Avanzada:**
    * Búsqueda eficiente por **ID** numérico.
    * Búsqueda por **Nombre** del producto.
* ** Visualización:** Listado completo del inventario con detalles de stock y precios (Costo/Venta).
* ** Persistencia de Datos:**
    * **Guardado automático:** Los datos se exportan a un archivo binario (`stock.dat`) para no perder información.
    * **Carga inteligente:** Al iniciar, el sistema recupera el estado anterior del inventario.

---

## Aspectos Técnicos

El proyecto fue desarrollado siguiendo buenas prácticas de programación estructurada y modularización:

* **Lenguaje:** C (Standard C99).
* **Estructura de Datos:** Lista Enlazada Simple (TAD).
* **Arquitectura:** Separación en capas mediante **TADs** (Tipos Abstractos de Datos):
    * `tad_producto`: Define la estructura y datos del negocio.
    * `lista_enlazada`: Maneja la lógica de punteros y memoria dinámica.
* **Archivos:** Uso de `fwrite` y `fread` para manejo de archivos binarios para mayor eficiencia.

---

## Estructura del Proyecto

```text
STOCKSHIP-AED2/
├── src/
│   ├── main.c/
│   │   └── main.c           # Punto de entrada y menú principal
│   ├── lista.c/
│   │   └── lista_enlazada.c # Implementación de la lista y archivos
│   ├── lista.h/
│   │   └── lista_enlazada.h # Prototipos y definiciones de la lista
│   ├── producto.c/
│   │   └── (Implementaciones auxiliares)
│   └── producto.h/
│       └── tad_producto.h   # Estructura del Producto
├── stock.dat                # Archivo binario de persistencia (generado automáticamente)
└── README.md                # Documentación del proyecto
```

## Instrucciones de Compilación y Ejecución
1. Compilación
   Abre tu terminal en la carpeta raíz del proyecto y ejecuta:
   ```bash
   gcc src/main.c/main.c src/lista.c/lista_enlazada.c -I src/lista.h -I src/producto.h -o stockship
   ```

2. Ejecución
   Una vez compilado, ejecuta el programa con:
   **En Windows:**
   ```bash
   ./stockship.exe
   ```  
  **En Linux/Mac:**
  ```bash
   ./stockship
   ```
