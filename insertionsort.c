#include <stdio.h>
#include <stdlib.h>

int insertion_sort(int vetor[], int tamanho){
    int aux, j, cont;
    cont = 0;
    for(int i = 1; i < tamanho; i++){
        aux = vetor[i];
        j = i - 1;
        while(j >= 0 && vetor[j] > aux){
            vetor[j + 1] = vetor[j];
            j = j - 1;
            cont++;
        }
        vetor[j + 1] = aux;
    }
    return cont;
}

int main(void){
    int num_testes, tamanho_vetor;
    scanf("%d", &num_testes);
    
    for(int i = 0; i < num_testes; i++){
        
        scanf("%d", &tamanho_vetor);
        int *vetor_inicial = malloc(tamanho_vetor * sizeof(int));

        for(int j = 0; j < tamanho_vetor; j++){
            scanf("%d", &vetor_inicial[j]);
        }

        int resultado = insertion_sort(vetor_inicial, tamanho_vetor);
        printf("%d\n", resultado);
    }

    return 0;
}