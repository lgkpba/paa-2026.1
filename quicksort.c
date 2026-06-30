#include <stdio.h>

#define LIMIAR 16

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insertionSort(int v[], int ini, int fim) {
    for (int i = ini + 1; i <= fim; i++) {
        int chave = v[i];
        int j = i - 1;

        while (j >= ini && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = chave;
    }
}

int medianaDeTres(int v[], int a, int b, int c) {
    if (v[a] > v[b]) swap(&v[a], &v[b]);
    if (v[a] > v[c]) swap(&v[a], &v[c]);
    if (v[b] > v[c]) swap(&v[b], &v[c]);

    // A mediana fica em b
    return v[b];
}

int particionar(int v[], int ini, int fim) {

    int meio = ini + (fim - ini) / 2;
    int pivo = medianaDeTres(v, ini, meio, fim);

    int i = ini - 1;
    int j = fim + 1;

    while (1) {

        do {
            i++;
        } while (v[i] < pivo);

        do {
            j--;
        } while (v[j] > pivo);

        if (i >= j)
            return j;

        swap(&v[i], &v[j]);
    }
}

void quickSort(int v[], int ini, int fim) {

    while (ini < fim) {

        if (fim - ini < LIMIAR) {
            insertionSort(v, ini, fim);
            return;
        }

        int p = particionar(v, ini, fim);

        // Ordena primeiro o menor lado
        if (p - ini < fim - p) {
            quickSort(v, ini, p);
            ini = p + 1;
        } else {
            quickSort(v, p + 1, fim);
            fim = p;
        }
    }
}

int main() {

    int n;
    scanf("%d", &n);

    int v[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    quickSort(v, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d\n", v[i]);

    return 0;
}
