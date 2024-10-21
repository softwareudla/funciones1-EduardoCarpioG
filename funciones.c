#include <stdio.h>
#include <string.h>
#include "funciones.h"

void leerProductos(char nombres[10][50], float precios[10], int numProductos) {
    for (int i = 0; i < numProductos; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        scanf("%s", nombres[i]);
        printf("Ingrese el precio del producto %d: ", i + 1);
        scanf("%f", &precios[i]);
    }}
void imprimirInventario(char nombres[10][50], float precios[10], int numProductos) {
    printf("\nInventario de productos:\n");
    for (int i = 0; i < numProductos; i++) {
        printf("Producto: %s, Precio: %.2f\n", nombres[i], precios[i]);
    }}
float calcularPrecioTotal(float precios[10], int numProductos) {
    float total = 0;
    for (int i = 0; i < numProductos; i++) {
        total += precios[i];
    }
    return total;
}
void encontrarProductoMasCaro(char nombres[10][50], float precios[10], int numProductos) {
    float maxPrecio = precios[0];
    char nombreProducto[50];
    strcpy(nombreProducto, nombres[0]);

    for (int i = 1; i < numProductos; i++) {
        if (precios[i] > maxPrecio) {
            maxPrecio = precios[i];
            strcpy(nombreProducto, nombres[i]);
        }
    }
    printf("Producto mas caro: %s, Precio: %.2f\n", nombreProducto, maxPrecio);
}
void encontrarProductoMasBarato(char nombres[10][50], float precios[10], int numProductos) {
    float minPrecio = precios[0];
    char nombreProducto[50];
    strcpy(nombreProducto, nombres[0]);

    for (int i = 1; i < numProductos; i++) {
        if (precios[i] < minPrecio) {
            minPrecio = precios[i];
            strcpy(nombreProducto, nombres[i]);
        }
    }
    printf("Producto mas barato: %s, Precio: %.2f\n", nombreProducto, minPrecio);
}
float calcularPrecioPromedio(float precios[10], int numProductos) {
    float total = calcularPrecioTotal(precios, numProductos);
    return total / numProductos;
}
void buscarProducto(char nombres[10][50], float precios[10], int numProductos) {
    char productoABuscar[50];
    char respuesta;
    do {
        printf("Ingrese el nombre del producto a buscar: ");
        scanf("%s", productoABuscar);
        int encontrado = 0;
        for (int i = 0; i < numProductos; i++) {
            if (strcmp(nombres[i], productoABuscar) == 0) {
                printf("Producto encontrado: %s - Precio: %.2f\n", nombres[i], precios[i]);
                encontrado = 1;
                break;
            }}
        if (!encontrado) {
            printf("Producto no encontrado.\n");
        }
        printf("Desea buscar otro producto (s/n): ");
        scanf(" %c", &respuesta);
    } while (respuesta == 's' || respuesta == 'S');
    printf("Finalizando busqueda.\n");
}