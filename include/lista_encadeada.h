#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include <time.h>
#include "pilha.h"

typedef struct Estatistica {
    char nome[50];
    int movimentos;
    int minimo_movimentos;
    time_t data_hora;
    struct Estatistica* proximo;
} Estatistica;

void inserir_estatistica(Estatistica** lista, char* nome, int movimentos, int minimo);
void salvar_em_arquivo(Estatistica* lista);
Estatistica* carregar_do_arquivo();
void liberar_lista(Estatistica* lista);
void mostrar_todas_estatisticas(Estatistica* lista);
void buscar_por_nome(Estatistica* lista, char* nome);
void buscar_por_data(Estatistica* lista, time_t data);

                          
#endif