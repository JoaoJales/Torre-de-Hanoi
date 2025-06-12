#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void create_pilha(Torre* torre){
    torre->topo = NULL;
}

int stackIsEmpty(Torre* torre){
    if (torre->topo == NULL)
    {
        return 1;
    }
    
    return 0;
}

void push(Torre* torre, int tamanho){
    Disco* discoNovo = (Disco*)malloc(sizeof(Disco));
    if (discoNovo == NULL)
    {
        printf("Erro ao alocar!\n");
        return;
    }

    discoNovo->tamanho = tamanho;
    discoNovo->prox = torre->topo;
    torre->topo = discoNovo;
}

void pop(Torre* torre){
    Disco* newTop = torre->topo->prox;
    free(torre->topo);
    torre->topo = newTop;

}


void free_pilha(Torre* torre) {
    while (!stackIsEmpty(torre)) {
        pop(torre);
    }
}