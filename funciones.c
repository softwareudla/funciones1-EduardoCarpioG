#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX_NOMBRE 50
#define MAX_PRODUCTOS 10

void leerProductos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[], int numProductos) {
    for (int i = 0; i < numProductos; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        fgets(nombres[i], MAX_NOMBRE, stdin);
        nombres[i][strcspn(nombres[i], "\n")] = '\0'; 
        
        int entradaValida = 0; 
        while (!entradaValida) {
            printf("Ingrese el precio del producto %d: ", i + 1);
            if (scanf("%f", &precios[i]) == 1 && precios[i] > 0) {
                entradaValida = 1;
            } else {
                printf("Entrada invalida. ");
                while (getchar() != '\n'); 
            }
        }
        getchar();
    }
}

void imprimirInventario(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos) {
    printf("Inventario:\n");
    for (int i = 0; i < numProductos; i++) {
        printf("%s - %.2f\n", nombres[i], precios[i]);
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
    int index = 0;
    for (int i = 1; i < numProductos; i++) {
        if (precios[i] > precios[index]) {
            index = i;
        }
    }
    printf("Producto mas caro: %s - %.2f\n", nombres[index], precios[index]);
}

void encontrarProductoMasBarato(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos) {
    int index = 0;
    for (int i = 1; i < numProductos; i++) {
        if (precios[i] < precios[index]) {
            index = i;
        }
    }
    printf("Producto mas barato: %s - %.2f\n", nombres[index], precios[index]);
}

float calcularPrecioPromedio(float precios[MAX_PRODUCTOS], int numProductos) {
    if (numProductos == 0) {
        return 0;
    }
    float total = calcularPrecioTotal(precios, numProductos);
    return total / numProductos;
}

void buscarProducto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos) {
    char producto[MAX_NOMBRE];
    char respuesta;

    do {
        int encontrado = 0; // Variable para verificar si se encontró el producto
        printf("Ingrese el nombre del producto a buscar: ");
        fgets(producto, MAX_NOMBRE, stdin);
        producto[strcspn(producto, "\n")] = '\0'; // Eliminar el salto de línea

        for (int i = 0; i < numProductos; i++) {
            if (strcmp(nombres[i], producto) == 0) {
                printf("Producto encontrado: %s - %.2f\n", nombres[i], precios[i]);
                encontrado = 1; // Marcar que se encontró el producto
                break; // Salir del bucle una vez encontrado
            }
        }

        if (!encontrado) {
            printf("Producto no encontrado.\n");
        }

        printf("Desea buscar otro producto (s/n) ");
        scanf(" %c", &respuesta);
        getchar(); // Limpiar el buffer
    } while (respuesta == 's' || respuesta == 'S');

    printf("Finalizando busqueda.\n");
}