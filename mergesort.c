#include <stdio.h>

int main(void){
    
    int tamanho;
    scanf("%d", &tamanho);
    int vetor_inicial[tamanho];

    for(int i = 0; i < tamanho; i++){
        scanf("%d", vetor_inicial[i]);
    }

    return 0;
}