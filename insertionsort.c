/*Acho importante esclarecer que a questão NÂO exige que seja usado o algoritmo Insertion Sort,
o que se pede é apenas que sejam contadas as inversões que ocorrem no vetor, por esse motivo apenas 
adaptei o código usado para responder a questão do Merge Sort para que ele conte as inversões
e ser aprovado pelo limite de tempo de 3 segundos, que se demonstrou muito pouco quando usando
Insertion Sort*/

#include <stdio.h>
#include <stdlib.h>

int merge(int *vetor, int primeiro, int meio, int ultimo){
    int cont1 = primeiro, cont2 = meio+1, contAux = 0, tam = ultimo-primeiro+1, inversoes = 0;
    int *vetAux = malloc(tam * sizeof(int));

    while(cont1 <= meio && cont2 <= ultimo){
        if(vetor[cont1] <= vetor[cont2]) {
            vetAux[contAux] = vetor[cont1];
            cont1++;
        } else {
            vetAux[contAux] = vetor[cont2];
            cont2++;
            inversoes += (meio - cont1 + 1);
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

    return inversoes;
}

int merge_sort(int *vetor, int primeiro, int ultimo){
    int inversoes = 0;
    if(primeiro < ultimo){
        int meio = (primeiro + ultimo) / 2;
        inversoes += merge_sort(vetor, primeiro, meio);
        inversoes += merge_sort(vetor, meio + 1, ultimo);
        inversoes += merge(vetor, primeiro, meio, ultimo);
    }
    return inversoes;
}

int main(void){
    
    int num, num_casos, tam_vetor;
    int *vetor_inicial = malloc(100000 * sizeof(int));
    scanf("%d", &num_casos);
    
    for(int i = 0; i < num_casos; i++){
        scanf("%d", &tam_vetor);
        
        for(int j = 0; j < tam_vetor; j++){
            scanf("%d", &vetor_inicial[j]);
        }

        int resultado = merge_sort(vetor_inicial, 0, tam_vetor - 1);
        printf("%d\n", resultado);
    }

    return 0;
}
