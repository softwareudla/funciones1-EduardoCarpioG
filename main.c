#include <stdio.h>
#include "funciones.h"

#define MAX_PRODUCTOS 10

int main() {
    char nombres[MAX_PRODUCTOS][50];
    float precios[MAX_PRODUCTOS];
    int numProductos;

    printf("Ingrese el numero de productos (maximo %d): ", MAX_PRODUCTOS);
    scanf("%d", &numProductos);

    // Verificar que el número de productos no exceda el máximo permitido
    if (numProductos > MAX_PRODUCTOS) {
        printf("El numero de productos no puede ser mayor que %d.\n", MAX_PRODUCTOS);
        return 1;
    }
    leerProductos(nombres, precios, numProductos);
    imprimirInventario(nombres, precios, numProductos);
    float total = calcularPrecioTotal(precios, numProductos);
    printf("Precio total del inventario: %.2f\n", total);
    encontrarProductoMasCaro(nombres, precios, numProductos);
    encontrarProductoMasBarato(nombres, precios, numProductos);
    float promedio = calcularPrecioPromedio(precios, numProductos);
    printf("Precio promedio de los productos: %.2f\n", promedio);
    buscarProducto(nombres, precios, numProductos);
    return 0;
}