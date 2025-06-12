#include <stdio.h>
#include <windows.h>
#include "utils.h"


void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void imprimir_torre_hanoi(int* tamanhos, int qtdDiscos, int linha, int maxDiscos){
    int indiceArray = qtdDiscos - 1 - linha;
    int tamanhoDisco;
    int possuiDisco = 1;
    if (indiceArray >= 0 && indiceArray < qtdDiscos)
    {
        tamanhoDisco = tamanhos[indiceArray];
    }else{
        tamanhoDisco = 0;
        possuiDisco = 0;
    }


    int espacos = maxDiscos - tamanhoDisco;
    


    if (possuiDisco)
    {
        for (int i = 0; i < espacos; i++){
            printf(" ");
        }
    
        if (tamanhoDisco > 0)
        {
            for (int i = 0; i < 2 * tamanhoDisco - 1; i++){
                printf("#");
            }
        }
        
    
        for (int i = 0; i < espacos; i++){
            printf(" ");
        }

    }else{
        for (int i = 0; i < (2 * maxDiscos) - 1; i++)
        {
            printf(" ");
        }
        
    }
    

    for (int i = 0; i < maxDiscos; i++)
    {
        printf(" ");
    }
    
}

void imprimir_torres(Torre* A, Torre* B, Torre* C, int maxDiscos) {
    int discosA[maxDiscos], discosB[maxDiscos], discosC[maxDiscos];
    int qtdA = 0, qtdB = 0, qtdC = 0;

    // Preenchendo os vetores com os discos de cada torre
    Disco* atual;

    atual = A->topo;
    while (atual && qtdA < maxDiscos) {
        discosA[qtdA] = atual->tamanho;
        qtdA++;
        atual = atual->prox;
    }

    atual = B->topo;
    while (atual && qtdB < maxDiscos) {
        discosB[qtdB] = atual->tamanho;
        qtdB++;
        atual = atual->prox;
    }

    atual = C->topo;
    while (atual && qtdC < maxDiscos) {
        discosC[qtdC] = atual->tamanho;
        qtdC++;
        atual = atual->prox;
    }
    for (int i = maxDiscos - 1; i >= 0; i--) {
        printf("\t");
        imprimir_torre_hanoi(discosA, qtdA, i, maxDiscos);
        imprimir_torre_hanoi(discosB, qtdB, i, maxDiscos);
        imprimir_torre_hanoi(discosC, qtdC, i, maxDiscos);
        printf("\n");
    }

    imprimir_base_torres(maxDiscos);
}

void imprimir_base_torres(int maxDiscos){
    int larguraMaxBase = (maxDiscos * 2) -1;
    printf("\t");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < larguraMaxBase; j++)
        {
            printf("=");
        }

        for (int j = 0; j < maxDiscos; j++)
        {
            printf(" ");
        }

    }
    printf("\n");
    printf("\t");
    char letrasTorres[4] = {'A','B','C'};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < larguraMaxBase; j++)
        {
            if (j != (maxDiscos-1))
            {
                printf(" ");
            }else{
                printf("%c", letrasTorres[i]);
            }
            
        }

        for (int j = 0; j < maxDiscos; j++)
        {
            printf(" ");
        }

    }

}

int contar_discos_torre(Torre* torre) {
    int count = 0;
    Disco* atual = torre->topo;
    while (atual) {
        count++;
        atual = atual->prox;
    }
    return count;
}