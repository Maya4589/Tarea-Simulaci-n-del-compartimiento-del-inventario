#include <cstdio>

// ===== PROTOTIPOS =====
void problema1();
void problema2();
void problema3();
void problema4();
void problema5();
void problema6();
void problema7();

int main() {
    int opcion;

    do {
        printf("\n=====================================\n");
        printf("  CONSOLA ADMINISTRATIVA GadgetXpress\n");
        printf("=====================================\n");
        printf("1. Promedio de 10 numeros\n");
        printf("2. Promedio con centinela\n");
        printf("3. Calificacion en letra\n");
        printf("4. Primeras 20 potencias de 4\n");
        printf("5. Numero mayor y menor de 100 numeros\n");
        printf("6. Conversion de minutos\n");
        printf("7. Analisis de numeros pares entre 20 y 400\n");
        printf("8. Salir\n");
        printf("=====================================\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        // Validar opcion
        if(opcion < 1 || opcion > 8) {
            printf("ERROR: Opcion invalida.\n");
            continue;
        }

        switch(opcion) {

            case 1:
                problema1();
                break;

            case 2:
                problema2();
                break;

            case 3:
                problema3();
                break;

            case 4:
                problema4();
                break;

            case 5:
                problema5();
                break;

            case 6:
                problema6();
                break;

            case 7:
                problema7();
                break;

            case 8:
                printf("Saliendo del programa...\n");
                break;
        }

    } while(opcion != 8);

    return 0;
}

// ===== PROBLEMA 1 =====
void problema1() {
    int numero;
    int suma = 0;
    int contador = 0;

    printf("\n--- PROMEDIO DE 10 NUMEROS ---\n");

    while(contador < 10) {
        printf("Ingrese el numero %d: ", contador + 1);
        scanf("%d", &numero);

        suma += numero;
        contador++;
    }

    float promedio = (float)suma / 10;

    printf("El promedio es: %.2f\n", promedio);
}

// ===== PROBLEMA 2 =====
void problema2() {
    int numero;
    int suma = 0;
    int contador = 0;

    printf("\n--- PROMEDIO CON CENTINELA ---\n");
    printf("Ingrese numeros positivos (-1 para finalizar)\n");

    do {
        printf("Numero: ");
        scanf("%d", &numero);

        if(numero != -1) {
            suma += numero;
            contador++;
        }

    } while(numero != -1);

    if(contador > 0) {
        float promedio = (float)suma / contador;
        printf("El promedio es: %.2f\n", promedio);
    } else {
        printf("No se ingresaron numeros.\n");
    }
}

// ===== PROBLEMA 3 =====
void problema3() {
    int nota;

    printf("\n--- CALIFICACION EN LETRA ---\n");
    printf("Ingrese una nota entre 0 y 100: ");
    scanf("%d", &nota);

    switch(nota / 10) {

        case 10:
        case 9:
            printf("Calificacion: A\n");
            break;

        case 8:
            printf("Calificacion: B\n");
            break;

        case 7:
            printf("Calificacion: C\n");
            break;

        case 6:
            printf("Calificacion: D\n");
            break;

        default:
            printf("Calificacion: F\n");
    }
}

// ===== PROBLEMA 4 =====
void problema4() {
    long long potencia = 4;

    printf("\n--- PRIMERAS 20 POTENCIAS DE 4 ---\n");

    for(int i = 1; i <= 20; i++) {
        printf("4^%d = %lld\n", i, potencia);
        potencia *= 4;
    }
}

// ===== PROBLEMA 5 =====
void problema5() {
    int numero;
    int mayor = 0;
    int menor = 0;

    printf("\n--- MAYOR Y MENOR DE 100 NUMEROS ---\n");

    for(int i = 1; i <= 100; i++) {

        printf("Ingrese el numero %d: ", i);
        scanf("%d", &numero);

        if(i == 1) {
            mayor = numero;
            menor = numero;
        }

        if(numero > mayor) {
            mayor = numero;
        }

        if(numero < menor) {
            menor = numero;
        }
    }

    printf("Numero mayor: %d\n", mayor);
    printf("Numero menor: %d\n", menor);
}

// ===== PROBLEMA 6 =====
void problema6() {
    int minutos;
    int dias;
    int horas;
    int minutosRestantes;

    printf("\n--- CONVERSION DE MINUTOS ---\n");
    printf("Ingrese la cantidad de minutos: ");
    scanf("%d", &minutos);

    dias = minutos / 1440;
    minutos = minutos % 1440;

    horas = minutos / 60;
    minutosRestantes = minutos % 60;

    printf("Equivale a:\n");
    printf("%d dias, %d horas y %d minutos\n",
           dias, horas, minutosRestantes);
}

// ===== PROBLEMA 7 =====
void problema7() {

    long long suma = 0;
    long double producto = 1;
    int contador = 0;

    printf("\n--- ANALISIS DE NUMEROS PARES ENTRE 20 Y 400 ---\n");

    for(int i = 20; i <= 400; i += 2) {

        suma += i;
        producto *= i;
        contador++;
    }

    double promedio = (double)suma / contador;

    int mayoresPromedio = 0;

    for(int i = 20; i <= 400; i += 2) {

        if(i > promedio) {
            mayoresPromedio++;
        }
    }

    printf("Suma: %lld\n", suma);
    printf("Producto: %.2Lf\n", producto);
    printf("Promedio: %.2f\n", promedio);
    printf("Cantidad mayores al promedio: %d\n",
           mayoresPromedio);
}