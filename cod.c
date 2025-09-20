#include <stdio.h>

// Definición de estructura Estudiante
typedef struct {
    int codigo;
    float nota;
} Estudiante;

// Lista predefinida de estudiantes (NO ingresada por teclado)
Estudiante estudiantes[] = {
    {2024101, 4.5},
    {2024102, 3.2},
    {2024103, 2.8},
    {2024104, 3.9},
    {2024105, 4.7}
};
int n = sizeof(estudiantes) / sizeof(estudiantes[0]);

// --- FUNCIONES RECURSIVAS ---

// Buscar nota máxima
float notaMaxima(Estudiante arr[], int size, int index) {
    if (index == size - 1)
        return arr[index].nota;

    float maxRestante = notaMaxima(arr, size, index + 1);
    return (arr[index].nota > maxRestante) ? arr[index].nota : maxRestante;
}

// Calcular promedio
float promedioRecursivo(Estudiante arr[], int size, int index) {
    if (index == size - 1)
        return arr[index].nota;
    return arr[index].nota + promedioRecursivo(arr, size, index + 1);
}

// Encontrar índice del mínimo (para selection sort recursivo)
int indiceMin(Estudiante arr[], int inicio, int size) {
    if (inicio == size - 1) return inicio;
    int minResto = indiceMin(arr, inicio + 1, size);
    return (arr[inicio].codigo < arr[minResto].codigo) ? inicio : minResto;
}

// Selection Sort recursivo
void selectionSortRec(Estudiante arr[], int inicio, int size) {
    if (inicio >= size - 1) return;

    int minIndex = indiceMin(arr, inicio, size);
    if (minIndex != inicio) {
        Estudiante temp = arr[inicio];
        arr[inicio] = arr[minIndex];
        arr[minIndex] = temp;
    }
    selectionSortRec(arr, inicio + 1, size);
}

// Mostrar estudiantes
void mostrarEstudiantes(Estudiante arr[], int size) {
    printf("\nLista de estudiantes:\n");
    for (int i = 0; i < size; i++) {
        printf("Codigo: %d - Nota: %.2f\n", arr[i].codigo, arr[i].nota);
    }
    printf("\n");
}

// --- MAIN ---
int main() {
    int opcion;
    do {
        printf("==== MENU ====\n");
        printf("1. Buscar nota maxima del curso\n");
        printf("2. Calcular promedio del curso\n");
        printf("3. Ordenar estudiantes por codigo (Selection Sort Recursivo)\n");
        printf("4. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\nLa nota maxima es: %.2f\n\n", notaMaxima(estudiantes, n, 0));
                break;
            case 2:
                printf("\nEl promedio del curso es: %.2f\n\n", promedioRecursivo(estudiantes, n, 0) / n);
                break;
            case 3:
                selectionSortRec(estudiantes, 0, n);
                printf("\nEstudiantes ordenados por codigo:\n");
                mostrarEstudiantes(estudiantes, n);
                break;
            case 4:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("\nOpcion invalida, intenta de nuevo.\n\n");
        }
    } while (opcion != 4);

    return 0;
}
