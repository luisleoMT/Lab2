#include <stdio.h>
#include <time.h>

// Función recursiva para calcular el n-ésimo número de Fibonacci
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 10; // Puedes cambiar este valor para probar diferentes entradas
    clock_t start, end;
    double tiempo_ejecucion;

    for (int i = 1; i <= n; i++) {
        start = clock();
        int resultado = fibonacci(i);
        end = clock();
        tiempo_ejecucion = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Fibonacci(%d) = %d, Tiempo de ejecución: %.5f segundos\n", i, resultado, tiempo_ejecucion);
    }

    return 0;
}
