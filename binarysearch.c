#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int vetor[], int num_procurado, int tamanho){
    int comeco = 0;
    int fim = tamanho - 1;
    int meio;
    
    while(comeco <= fim){
        meio = (comeco + fim) / 2;
        if(vetor[meio] == num_procurado){
            while(meio > 0 && vetor[meio - 1] == num_procurado){
                meio--;
            }
            return meio;
        }
        if(vetor[meio] > num_procurado){
            fim = meio - 1;
        } else{
            comeco = meio + 1;
        }
    }
    return -1;
}

int main(void){
    int tam_vetor, num_buscas, num_procurado;
    scanf("%d %d", &tam_vetor, &num_buscas);
    
    int *vetor = malloc(tam_vetor * sizeof(int));
    for(int i = 0; i < tam_vetor; i++){
        scanf("%d", &vetor[i]);
    }
    
    for(int j = 0; j < num_buscas; j++){
        scanf("%d", &num_procurado);
        int indice = busca_binaria(vetor, num_procurado, tam_vetor);
        printf("%d\n", indice);
    }
    
    free(vetor);
    return 0;
}