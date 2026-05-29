

#include <cstdio>
#include <vector>

// 1. Estructura base del producto
struct Producto {
    int codigo;
    char nombre[50];
    int cantidad;
    float precio;
};

//PROTOTIPOS DE FUNCIONES
void mostrarMenu();
int buscarProducto(const std::vector<Producto>& inventario, int codigoBusqueda);
void agregarProducto(std::vector<Producto>& inventario);
void listarInventario(const std::vector<Producto>& inventario);
void actualizarCantidad(std::vector<Producto>& inventario);
void generarReporteBajoInventario(const std::vector<Producto>& inventario);
void simularVenta(std::vector<Producto>& inventario);

//  FUNCIÓN PRINCIPAL 
int main() {
    
    std::vector<Producto> inventario = {
        {101, "Laptop Gamer", 10, 1500.50f},
        {102, "Mouse Inalambrico", 25, 20.00f},
        {103, "Teclado Mecanico", 5, 85.00f}
    };

    int opcion;

    do {
        mostrarMenu();
        
        // Validación de entrada para evitar bucles si se ingresa una letra
        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n'); // Limpia el búfer
            opcion = 0;
        }

        switch (opcion) {
            case 1:
                agregarProducto(inventario);
                break;
            case 2:
                listarInventario(inventario);
                break;
            case 3:
                actualizarCantidad(inventario);
                break;
            case 4:
                generarReporteBajoInventario(inventario);
                break;
            case 5:
                simularVenta(inventario); //funcion de simulacion 
                break;
            case 6:
                printf("\nSaliendo de la Consola Administrativa. ¡Hasta pronto!\n");
                break;
            default:
                printf("\n[ERROR] Opcion invalida. Intente de nuevo.\n");
        }

    } while (opcion != 6);

    return 0;
}

// INTERFAZ DEL MENÚ 
void mostrarMenu() {
    printf("\n=====================================\n");
    printf("  CONSOLA ADMINISTRATIVA GadgetXpress\n");
    printf("=====================================\n");
    printf("1. Agregar producto\n");
    printf("2. Listar inventario\n");
    printf("3. Actualizar cantidad\n");
    printf("4. Reporte de bajo inventario\n");
    printf("5. Simular venta\n");
    printf("6. Salir\n");
    printf("=====================================\n");
    printf("Ingrese una opcion: ");
}

// 2. Función de búsqueda reutilizada evidencia 5
int buscarProducto(const std::vector<Producto>& inventario, int codigoBusqueda) {
    for (size_t i = 0; i < inventario.size(); ++i) {
        if (inventario[i].codigo == codigoBusqueda) {
            return i; // Producto encontrado
        }
    }
    return -1; // Producto no encontrado
}

//  FUNCIONALIDAD 1: AGREGAR PRODUCTO 
void agregarProducto(std::vector<Producto>& inventario) {
    Producto nuevo;
    printf("\n--- AGREGAR NUEVO PRODUCTO ---\n");
    printf("Ingrese el codigo (numerico): ");
    scanf("%d", &nuevo.codigo);

    // Validación modular: verificar si ya existe
    if (buscarProducto(inventario, nuevo.codigo) != -1) {
        printf("[ERROR] Ya existe un producto con el codigo %d.\n", nuevo.codigo);
        return;
    }

    printf("Ingrese el nombre del producto: ");
    scanf(" %[^\n]", nuevo.nombre); // Permite leer nombres con espacios de forma segura

    printf("Ingrese la cantidad inicial: ");
    scanf("%d", &nuevo.cantidad);

    printf("Ingrese el precio: ");
    scanf("%f", &nuevo.precio);

    inventario.push_back(nuevo); // Agrega el producto al final del vector dinámico
    printf("[EXITO] Producto registrado correctamente.\n");
}

//FUNCIONALIDAD 2: LISTAR INVENTARIO 
void listarInventario(const std::vector<Producto>& inventario) {
    printf("\n--- INVENTARIO COMPLETO GADGETXPRESS ---\n");
    if (inventario.empty()) {
        printf("El inventario se encuentra totalmente vacio.\n");
        return;
    }

    for (size_t i = 0; i < inventario.size(); ++i) {
        printf("Codigo: %-5d | %-20s | Stock: %-3d | Precio: $%.2f\n", 
               inventario[i].codigo, inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
    }
}

//  FUNCIONALIDAD 3: ACTUALIZAR CANTIDAD 
void actualizarCantidad(std::vector<Producto>& inventario) {
    int codigoBusqueda, nuevaCantidad;
    printf("\n--- ACTUALIZAR CANTIDAD (REABASTECIMIENTO) ---\n");
    printf("Ingrese el codigo del producto: ");
    scanf("%d", &codigoBusqueda);

    int indice = buscarProducto(inventario, codigoBusqueda);

    if (indice != -1) {
        printf("Producto encontrado: %s (Stock actual: %d)\n", inventario[indice].nombre, inventario[indice].cantidad);
        printf("Ingrese la nueva cantidad total: ");
        scanf("%d", &nuevaCantidad);
        
        inventario[indice].cantidad = nuevaCantidad;
        printf("[EXITO] Stock actualizado con exito.\n");
    } else {
        printf("[ERROR] El producto con codigo %d no existe.\n", codigoBusqueda);
    }
}

// FUNCIONALIDAD 4: REPORTE DE BAJO INVENTARIO 
void generarReporteBajoInventario(const std::vector<Producto>& inventario) {
    const int UMBRAL_MINIMO = 5;
    bool alertas = false;

    printf("\n--- REPORTE DE BAJO INVENTARIO (< %d unidades) ---\n", UMBRAL_MINIMO);
    
    for (size_t i = 0; i < inventario.size(); ++i) {
        if (inventario[i].cantidad < UMBRAL_MINIMO) {
            printf("¡ALERTA! Codigo: %-5d | Producto: %-20s | Stock actual: %d\n", 
                   inventario[i].codigo, inventario[i].nombre, inventario[i].cantidad);
            alertas = true;
        }
    }

    if (!alertas) {
        printf("[OK] Todos los productos cuentan con stock suficiente.\n");
    }
}

// 3.función de simulación de venta 
void simularVenta(std::vector<Producto>& inventario) {
    int codigoVenta, cantidadVenta;

    printf("\n--- SIMULADOR DE VENTAS GADGETXPRESS ---\n");
    printf("Ingrese el codigo del producto a vender: ");
    scanf("%d", &codigoVenta);
    
    printf("Ingrese la cantidad que desea vender: ");
    scanf("%d", &cantidadVenta);

    int indice = buscarProducto(inventario, codigoVenta);

    if (indice != -1) {
        if (cantidadVenta <= inventario[indice].cantidad) {
            inventario[indice].cantidad -= cantidadVenta;
            printf("\n[EXITO] Venta realizada con exito.\n");
            printf("Detalle: Se vendieron %d unidad(es) de '%s'.\n", cantidadVenta, inventario[indice].nombre);
            printf("Nuevo stock disponible: %d\n", inventario[indice].cantidad);
        } else {
            printf("\n[ERROR] No hay suficiente inventario.\n");
            printf("Cantidad solicitada: %d | Cantidad disponible: %d\n", cantidadVenta, inventario[indice].cantidad);
        }
    } else {
        printf("\n[ERROR] El producto con codigo %d no existe en el inventario.\n", codigoVenta);
    }
}
