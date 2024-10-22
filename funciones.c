#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX_NOMBRE 50
#define MAX_PRODUCTOS 100

void leerProductos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[], int numProductos) {
    int cantidadProductos; // Declaración de la variable cantidadProductos

    do {
        printf("Ingrese el número de productos (1 a %d): ", MAX_PRODUCTOS);
        scanf("%d", &cantidadProductos);
        while (getchar() != '\n');
    } while (cantidadProductos <= 0 || cantidadProductos > MAX_PRODUCTOS);

    for (int i = 0; i < cantidadProductos; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        fgets(nombres[i], sizeof(nombres[i]), stdin);
        size_t len = strlen(nombres[i]);
        if (len > 0 && nombres[i][len - 1] == '\n') {
            nombres[i][len - 1] = '\0';
        }
    }

    for (int i = 0; i < cantidadProductos; i++) {
        while (1) {
            printf("Ingrese el precio del producto %d: ", i + 1);
            if (scanf("%f", &precios[i]) == 1 && precios[i] > 0) {
                break;
            } else {
                printf("Entrada invalida. Ingrese el precio del producto %d: ", i + 1);
                while (getchar() != '\n');
            }
        }
    }
    while (getchar() != '\n');
}

void imprimirInventario(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos) {
    printf("\nInventario de productos:\n");
    for (int i = 0; i < numProductos; i++) {
        printf("Producto: %s, Precio: %.2f\n", nombres[i], precios[i]);
    }
}

float calcularPrecioTotal(float precios[MAX_PRODUCTOS], int numProductos) {
    float total = 0;
    for (int i = 0; i < numProductos; i++) {
        total += precios[i];
    }
    return total;
}

void encontrarProductoMasCaro(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos) {
    float maxPrecio = precios[0];
    char nombreProducto[MAX_NOMBRE];
    strcpy(nombreProducto, nombres[0]);

    for (int i = 1; i < numProductos; i++) {
        if (precios[i] > maxPrecio) {
            maxPrecio = precios[i];
            strcpy(nombreProducto, nombres[i]);
        }
    }
    printf("Producto más caro: %s, Precio: %.2f\n", nombreProducto, maxPrecio);
}

void encontrarProductoMasBarato(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos) {
    float minPrecio = precios[0];
    char nombreProducto[MAX_NOMBRE];
    strcpy(nombreProducto, nombres[0]);

    for (int i = 1; i < numProductos; i++) {
        if (precios[i] < minPrecio) {
            minPrecio = precios[i];
            strcpy(nombreProducto, nombres[i]);
        }
    }
    printf("Producto más barato: %s, Precio: %.2f\n", nombreProducto, minPrecio);
}

float calcularPrecioPromedio(float precios[MAX_PRODUCTOS], int numProductos) {
    if (numProductos == 0) {
        return 0;
    }
    float total = calcularPrecioTotal(precios, numProductos);
    return total / numProductos;
}

void buscarProducto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos) {
    char productoABuscar[MAX_NOMBRE];
    char respuesta;
    do {
        printf("Ingrese el nombre del producto a buscar: ");
        scanf("%49s", productoABuscar);
        int encontrado = 0;
        for (int i = 0; i < numProductos; i++) {
            if (strcmp(nombres[i], productoABuscar) == 0) {
                printf("Producto encontrado: %s - Precio: %.2f\n", nombres[i], precios[i]);
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            printf("Producto no encontrado.\n");
        }
        printf("¿Desea buscar otro producto (s/n)? ");
        scanf(" %c", &respuesta);
    } while (respuesta == 's' || respuesta == 'S');
    printf("Finalizando busqueda.\n");
}