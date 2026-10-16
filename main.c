#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Compara algoritmos de ordenacao (Bubble, Selection e Insertion Sort)
 * contando comparacoes e trocas, e demonstra a busca binaria.
 */

long comparacoes;
long trocas;

void trocar(int v[], int i, int j) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
    trocas++;
}

void bubbleSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            comparacoes++;
            if (v[j] > v[j + 1]) {
                trocar(v, j, j + 1);
            }
        }
    }
}

void selectionSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        if (menor != i) {
            trocar(v, i, menor);
        }
    }
}

void insertionSort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;
        while (j >= 0) {
            comparacoes++;
            if (v[j] > chave) {
                v[j + 1] = v[j];
                trocas++;
                j--;
            } else {
                break;
            }
        }
        v[j + 1] = chave;
    }
}

/* Retorna a posicao do valor no vetor ORDENADO, ou -1 se nao existir. */
int buscaBinaria(int v[], int n, int valor) {
    int esq = 0, dir = n - 1;
    while (esq <= dir) {
        int meio = (esq + dir) / 2;
        if (v[meio] == valor) return meio;
        if (v[meio] < valor) esq = meio + 1;
        else dir = meio - 1;
    }
    return -1;
}

void gerarVetor(int v[], int n, unsigned int semente) {
    srand(semente);
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 10000;
    }
}

void executar(const char *nome, int original[], int n, int algoritmo) {
    int *v = malloc(n * sizeof(int));
    if (v == NULL) {
        printf("Erro de memoria\n");
        return;
    }
    for (int i = 0; i < n; i++) v[i] = original[i];

    comparacoes = 0;
    trocas = 0;
    clock_t inicio = clock();

    if (algoritmo == 1) bubbleSort(v, n);
    else if (algoritmo == 2) selectionSort(v, n);
    else insertionSort(v, n);

    double ms = (double)(clock() - inicio) * 1000.0 / CLOCKS_PER_SEC;
    printf("%-15s comparacoes: %-10ld trocas: %-10ld tempo: %.2f ms\n",
           nome, comparacoes, trocas, ms);
    free(v);
}

int main(void) {
    int tamanhos[] = {100, 1000, 5000};

    for (int t = 0; t < 3; t++) {
        int n = tamanhos[t];
        printf("\n=== Vetor com %d elementos ===\n", n);

        int *base = malloc(n * sizeof(int));
        if (base == NULL) {
            printf("Erro de memoria\n");
            return 1;
        }
        gerarVetor(base, n, 42);

        executar("Bubble Sort", base, n, 1);
        executar("Selection Sort", base, n, 2);
        executar("Insertion Sort", base, n, 3);
        free(base);
    }

    /* Demonstracao da busca binaria */
    int v[20];
    gerarVetor(v, 20, 7);
    insertionSort(v, 20);

    printf("\n=== Busca binaria ===\n");
    printf("Vetor ordenado:");
    for (int i = 0; i < 20; i++) printf(" %d", v[i]);
    printf("\n");

    int alvo = v[12];
    printf("Procurando %d: posicao %d\n", alvo, buscaBinaria(v, 20, alvo));
    printf("Procurando -5: posicao %d\n", buscaBinaria(v, 20, -5));

    return 0;
}
