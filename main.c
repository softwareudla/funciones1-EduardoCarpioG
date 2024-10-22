#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX_NOMBRE 50
#define MAX_PRODUCTOS 100

int main() {
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios[MAX_PRODUCTOS];
    int numProductos;

    do {
        printf("Ingrese el numero de productos (maximo %d): ", MAX_PRODUCTOS);
        scanf("%d", &numProductos);
        while (getchar() != '\n'); // Limpiar el buffer
    } while (numProductos <= 0 || numProductos > MAX_PRODUCTOS);

    leerProductos(nombres, precios, numProductos);
    imprimirInventario(nombres, precios, numProductos);
    float total = calcularPrecioTotal(precios, numProductos);
    printf("Total del inventario: %.2f\n", total);
    encontrarProductoMasCaro(nombres, precios, numProductos);
    encontrarProductoMasBarato(nombres, precios, numProductos);
    float promedio = calcularPrecioPromedio(precios, numProductos);
    printf("Precio promedio de los productos: %.2f\n", promedio);
    buscarProducto(nombres, precios, numProductos);
    
    return 0;
}