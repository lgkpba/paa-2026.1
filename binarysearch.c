#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int vetor[], int num_procurado, int comeco, int fim){
    int meio = (comeco + fim) / 2;
    if(vetor[meio] == num_procurado){
        return meio;
    }
    
    if(comeco >= fim){
        return -1;
    }
    else{
        if(vetor[meio] < num_procurado){
            return busca_binaria(vetor, num_procurado, meio + 1, fim);
        }
        else{
            return busca_binaria(vetor, num_procurado, comeco, meio - 1);
        }
    }
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
        int indice = busca_binaria(vetor, num_procurado, 0, tam_vetor - 1);
        printf("%d\n", indice);
    }
    free(vetor);
    return 0;
}