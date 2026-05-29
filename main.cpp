#include <cstdio>
#include <vector>

// 1. Estructura base del producto 
struct Producto {
    int codigo;
    char nombre[50];
    int cantidad;
    float precio;
};

// 2. Función de búsqueda reutilizada de la Evidencia5
// Retorna el índice del producto si existe, o -1 si no se encuentra.
int buscarProducto(const std::vector<Producto>& inventario, int codigoBusqueda) {
    for (size_t i = 0; i < inventario.size(); ++i) {
        if (inventario[i].codigo == codigoBusqueda) {
            return i; // Producto encontrado
        }
    }
    return -1; // Producto no encontrado
}

// 3. Paso 1: Implementación de la función de simulación de venta
// Nota: Pasamos el vector por referencia (&) para que los cambios en la cantidad se guarden.
void simularVenta(std::vector<Producto>& inventario) {
    int codigoVenta, cantidadVenta;

    // a y b. Solicitar al usuario el código y la cantidad
    printf("\n--- SIMULADOR DE VENTAS GADGETXPRESS ---\n");
    printf("Ingrese el codigo del producto a vender: ");
    scanf("%d", &codigoVenta);
    
    printf("Ingrese la cantidad que desea vender: ");
    scanf("%d", &cantidadVenta);

    // c. Validación 1: Verificar que el producto exista
    int indice = buscarProducto(inventario, codigoVenta);

    if (indice != -1) {
        // Validación 2: Verificar que haya suficiente inventario
        if (cantidadVenta <= inventario[indice].cantidad) {
            // d. Lógica de venta exitosa
            inventario[indice].cantidad -= cantidadVenta;
            printf("\n[EXITO] Venta realizada con exito.\n");
            printf("Detalle: Se vendieron %d unidad(es) de '%s'.\n", cantidadVenta, inventario[indice].nombre);
            printf("Nuevo stock disponible: %d\n", inventario[indice].cantidad);
        } else {
            // Lógica de error: Inventario insuficiente
            printf("\n[ERROR] No hay suficiente inventario.\n");
            printf("Cantidad solicitada: %d | Cantidad disponible: %d\n", cantidadVenta, inventario[indice].cantidad);
        }
    } else {
        // Producto no existe
        printf("\n[ERROR] El producto con codigo %d no existe en el inventario.\n", codigoVenta);
    }
}

// 4. Función main para probar la simulación
int main() {
    // Inicializamos un inventario de prueba para GadgetXpress
    std::vector<Producto> inventario = {
        {101, "Laptop Gamer", 10, 1500.50},
        {102, "Mouse Inalambrico", 25, 20.00},
        {103, "Teclado Mecanico", 5, 85.00}
    };

    // Mostramos el inventario inicial
    printf("Inventario inicial:\n");
    for (size_t i = 0; i < inventario.size(); ++i) {
        printf("Codigo: %d | %s | Stock: %d\n", inventario[i].codigo, inventario[i].nombre, inventario[i].cantidad);
    }

    // Ejecutamos la simulación de venta
    simularVenta(inventario);

    

    return 0;
}