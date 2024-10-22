#define MAX_NOMBRE 50
#define MAX_PRODUCTOS 100
void leerProductos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[], int numProductos);
void imprimirInventario(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos);
float calcularPrecioTotal(float precios[MAX_PRODUCTOS], int numProductos);
void encontrarProductoMasCaro(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos);
void encontrarProductoMasBarato(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos);
float calcularPrecioPromedio(float precios[MAX_PRODUCTOS], int numProductos);
void buscarProducto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos);
void agregarProducto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[], int *numProductos, char producto[MAX_NOMBRE], float precio);
double calcularTotal(float precios[MAX_PRODUCTOS], int numProductos);