#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int particionar(int vetor[], int min, int max){
    int pivo = vetor[max];
    int i = min - 1;

    for (int j = min; j <= max - 1; j++){
        if (vetor[j] < pivo) {
            i++;
            swap(&vetor[i], &vetor[j]);
        }
    }

    swap(&vetor[i+1], &vetor[max]);
    return i + 1;
}

void quickSort(int vetor[], int min, int max){
    if (min < max) {
        int pi = particionar(vetor, min, max);

        quickSort(vetor, min, pi-1);
        quickSort(vetor, pi+1, max);
    }
}

int main(void){
    int tam_vetor;
    scanf("%d", &tam_vetor);
    int vetor[tam_vetor]; 
    
    for (int i = 0; i < tam_vetor; i++) {
        scanf("%d", &vetor[i]);
    }
    
    quickSort(vetor, 0, (tam_vetor / sizeof(vetor[0])) - 1);

    for (int j = 0; j < tam_vetor; j++) {
        printf("%d\n", vetor[j]);
    }

    return 0;
}