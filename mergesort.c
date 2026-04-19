#include <stdio.h>
#include <stdlib.h>

void merge(int *vetor, int primeiro, int meio, int ultimo){
    int cont1 = primeiro, cont2 = meio+1, contAux = 0, tam = ultimo-primeiro+1;
    int *vetAux = (int*)malloc(tam * sizeof(int));

    while(cont1 <= meio && cont2 <= ultimo){
        if(vetor[cont1] < vetor[cont2]) {
            vetAux[contAux] = vetor[cont1];
            cont1++;
        } else {
            vetAux[contAux] = vetor[cont2];
            cont2++;
        }
        contAux++;
    }

    while(cont1 <= meio){
        vetAux[contAux] = vetor[cont1];
        contAux++;
        cont1++;
    }

    while(cont2 <= ultimo) {
        vetAux[contAux] = vetor[cont2];
        contAux++;
        cont2++;
    }

    for(contAux = primeiro; contAux <= ultimo; contAux++){
        vetor[contAux] = vetAux[contAux-primeiro];
    }
    
    free(vetAux);

    return;
}

void merge_sort(int *vetor, int primeiro, int ultimo){
    if(primeiro < ultimo){
        int meio = (primeiro + ultimo) / 2;
        merge_sort(vetor, primeiro, meio);
        merge_sort(vetor, meio + 1, ultimo);
        merge(vetor, primeiro, meio, ultimo);
    }
    return;
}

int main(void){
    
    int *vetor_inicial = NULL;
    int capacidade = 10;
    int tamanho = 0;
    vetor_inicial = malloc(capacidade * sizeof(int));
    int num;

    while(scanf("%d", &num) == 1){
        if(tamanho == capacidade){
            capacidade *=2;
            vetor_inicial = realloc(vetor_inicial, capacidade * sizeof(int));
        }
        vetor_inicial[tamanho++] = num;
    }

    for(int i = 0; i < tamanho; i++){
        scanf("%d", &vetor_inicial[i]);
    }

    merge_sort(vetor_inicial, 0, tamanho - 1);

    for(int j = 0; j < tamanho; j++){
        printf("%d", vetor_inicial[j]);
        
        if(j < tamanho - 1){
            printf(" ");
        }
    }
    printf("\n");

    free(vetor_inicial);

    return 0;
}