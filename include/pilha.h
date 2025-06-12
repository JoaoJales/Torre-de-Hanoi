#ifndef PILHA_H
#define PILHA_H

typedef struct Disco {
    int tamanho;              
    struct Disco* prox;       
} Disco;


typedef struct {
    Disco* topo;
} Torre;


void create_pilha(Torre* torre);
int stackIsEmpty(Torre* torre);
void push(Torre* torre, int tamanho);
void pop(Torre* torre);
void imprimir_torres(Torre* A, Torre* B, Torre* C, int maxDiscos);
void imprimir_torre_hanoi(int* tamanhos, int qtdDiscos, int linha, int maxDiscos);
void free_pilha(Torre* torre);

#endif