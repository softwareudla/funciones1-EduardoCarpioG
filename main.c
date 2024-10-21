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
        return 1; // Salir del programa con un código de error
    }

    // Leer los productos
    leerProductos(nombres, precios, numProductos);

    // Imprimir el inventario
    imprimirInventario(nombres, precios, numProductos);

    // Calcular y mostrar el precio total
    float total = calcularPrecioTotal(precios, numProductos);
    printf("Precio total del inventario: %.2f\n", total);

    // Encontrar y mostrar el producto más caro
    encontrarProductoMasCaro(nombres, precios, numProductos);

    // Encontrar y mostrar el producto más barato
    encontrarProductoMasBarato(nombres, precios, numProductos);

    // Calcular y mostrar el precio promedio
    float promedio = calcularPrecioPromedio(precios, numProductos);
    printf("Precio promedio de los productos: %.2f\n", promedio);

    // Buscar un producto por su nombre
    buscarProducto(nombres, precios, numProductos);

    return 0; // Salir del programa con éxito
}