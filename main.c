#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX_NOMBRE 50
#define MAX_PRODUCTOS 10

int main() {
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios[MAX_PRODUCTOS];
    int numProductos = 0;

    do {
        printf("Ingrese el numero de productos (maximo %d): ", MAX_PRODUCTOS);
        if (scanf("%d", &numProductos) != 1) {
            printf("Entrada invalida. Por favor, ingrese un numero entero.\n");
            while (getchar() != '\n');
        } else if (numProductos <= 0 || numProductos > MAX_PRODUCTOS) {
            printf("Entrada invalida. Por favor, ingrese un numero entre 1 y %d.\n", MAX_PRODUCTOS);
        }
    } while (numProductos <= 0 || numProductos > MAX_PRODUCTOS);

    getchar();

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