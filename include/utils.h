#ifndef UTILS_H
#define UTILS_H

#include "pilha.h"

void limpar_buffer();
void imprimir_torres(Torre* A, Torre* B, Torre* C, int maxDiscos);
void imprimir_torre_hanoi(int* tamanhos, int qtdDiscos, int linha, int maxDiscos);
void imprimir_base_torres(int maxDiscos);
int contar_discos_torre(Torre* torre);

#endif