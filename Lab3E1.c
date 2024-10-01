#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para ordenar un arreglo
void ordenar(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Función para encontrar la mediana de dos arreglos ordenados
double encontrarMediana(int* nums1, int m, int* nums2, int n) {
    int* merged = (int*)malloc((m + n) * sizeof(int));
    int i = 0, j = 0, k = 0;

    // Fusionar los dos arreglos
    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            merged[k++] = nums1[i++];
        } else {
            merged[k++] = nums2[j++];
        }
    }
    while (i < m) {
        merged[k++] = nums1[i++];
    }
    while (j < n) {
        merged[k++] = nums2[j++];
    }

    // Encontrar la mediana
    double mediana;
    if ((m + n) % 2 == 0) {
        mediana = (merged[(m + n) / 2 - 1] + merged[(m + n) / 2]) / 2.0;
    } else {
        mediana = merged[(m + n) / 2];
    }

    free(merged);
    return mediana;
}

int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};
    int m = sizeof(nums1) / sizeof(nums1[0]);
    int n = sizeof(nums2) / sizeof(nums2[0]);

    clock_t start = clock();
    double mediana = encontrarMediana(nums1, m, nums2, n);
    clock_t end = clock();

    double tiempo_ejecucion = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Mediana: %.5f\n", mediana);
    printf("Tiempo de ejecución: %.5f segundos\n", tiempo_ejecucion);

    return 0;
}
