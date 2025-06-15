#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>  
#include <conio.h>
#include "lista_encadeada.h"

void inserir_estatistica(Estatistica** lista, char* nome, int movimentos, int minimo) {
    Estatistica* novo = (Estatistica*)malloc(sizeof(Estatistica));
    strcpy(novo->nome, nome);
    novo->movimentos = movimentos;
    novo->minimo_movimentos = minimo;
    novo->data_hora = time(NULL);
    novo->proximo = *lista;
    *lista = novo;
    
    salvar_em_arquivo(*lista);
}

void salvar_em_arquivo(Estatistica* lista) {
    FILE* arquivo = fopen("historico.txt", "w");
    if (!arquivo) return;
    
    Estatistica* atual = lista;
    while (atual) {
        fprintf(arquivo, "%s;%d;%d;%ld\n", 
                atual->nome, 
                atual->movimentos, 
                atual->minimo_movimentos, 
                atual->data_hora);
        atual = atual->proximo;
    }
    
    fclose(arquivo);
}

Estatistica* carregar_do_arquivo() {
    FILE* arquivo = fopen("historico.txt", "r");
    if (!arquivo) return NULL;
    
    Estatistica* lista = NULL;
    char linha[256];
    
    while (fgets(linha, sizeof(linha), arquivo)) {
        Estatistica* novo = (Estatistica*)malloc(sizeof(Estatistica));
        char* token = strtok(linha, ";");
        strcpy(novo->nome, token);
        
        token = strtok(NULL, ";");
        novo->movimentos = atoi(token);
        
        token = strtok(NULL, ";");
        novo->minimo_movimentos = atoi(token);
        
        token = strtok(NULL, "\n");
        novo->data_hora = atol(token);
        
        novo->proximo = lista;
        lista = novo;
    }
    
    fclose(arquivo);
    return lista;
}

void liberar_lista(Estatistica* lista) {
    Estatistica* atual = lista;
    while (atual) {
        Estatistica* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

void mostrar_todas_estatisticas(Estatistica* lista) {
    system("cls");
    printf("\n\t=== TODAS AS ESTATISTICAS ===\n");
    
    Estatistica* atual = lista;
    while (atual) {
        char data_str[50];
        strftime(data_str, sizeof(data_str), "%d/%m/%Y %H:%M:%S", localtime(&atual->data_hora));
        
        printf("\n\tNome: %s", atual->nome);
        printf("\n\tMovimentos: %d", atual->movimentos);
        printf("\n\tMinimo necessario: %d", atual->minimo_movimentos);
        printf("\n\tData: %s", data_str);
        printf("\n\t----------------------------");
        atual = atual->proximo;
    }
    
    printf("\n\n\tPressione qualquer tecla para voltar...");
    _getch();
}

void buscar_por_nome(Estatistica* lista, char* nome) {
    system("cls");
    printf("\n\t=== BUSCA POR NOME: %s ===\n", nome);
    
    Estatistica* atual = lista;
    int encontrou = 0;
    
    while (atual) {
        if (strcmp(atual->nome, nome) == 0) {
            char data_str[50];
            strftime(data_str, sizeof(data_str), "%d/%m/%Y %H:%M:%S", localtime(&atual->data_hora));
            
            printf("\n\tNome: %s", atual->nome);
            printf("\n\tMovimentos: %d", atual->movimentos);
            printf("\n\tMinimo necessario: %d", atual->minimo_movimentos);
            printf("\n\tData: %s", data_str);
            printf("\n\t----------------------------");
            encontrou = 1;
        }
        atual = atual->proximo;
    }
    
    if (!encontrou) {
        printf("\n\tNenhum resultado encontrado para '%s'", nome);
    }
    
    printf("\n\n\tPressione qualquer tecla para voltar...");
    _getch();
}

void buscar_por_data(Estatistica* lista, time_t data) {
    system("cls");
    char data_str[50];
    struct tm* tm_data = localtime(&data);
    strftime(data_str, sizeof(data_str), "%d/%m/%Y", tm_data);
    printf("\n\t=== BUSCA POR DATA: %s ===\n", data_str);
    
    Estatistica* atual = lista;
    int encontrou = 0;
    
    struct tm tm_busca = *tm_data;
    tm_busca.tm_hour = 0;
    tm_busca.tm_min = 0;
    tm_busca.tm_sec = 0;
    time_t data_busca = mktime(&tm_busca);
    
    while (atual != NULL) {
        struct tm tm_registro = *localtime(&atual->data_hora);
        tm_registro.tm_hour = 0;
        tm_registro.tm_min = 0;
        tm_registro.tm_sec = 0;
        time_t data_registro = mktime(&tm_registro);
        
        if (data_registro == data_busca) {
            char registro_str[50];
            strftime(registro_str, sizeof(registro_str), "%d/%m/%Y %H:%M:%S", localtime(&atual->data_hora));
            
            printf("\n\tNome: %s", atual->nome);
            printf("\n\tMovimentos: %d", atual->movimentos);
            printf("\n\tMinimo necessario: %d", atual->minimo_movimentos);
            printf("\n\tData: %s", registro_str);
            printf("\n\t----------------------------");
            encontrou = 1;
        }
        atual = atual->proximo;
    }
    
    if (!encontrou) {
        printf("\n\tNenhum resultado encontrado para a data %s", data_str);
    }
    
    printf("\n\n\tPressione qualquer tecla para voltar...");
    _getch();
}