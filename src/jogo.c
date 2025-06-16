#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include "pilha.h"
#include "utils.h"
#include "interfaces.h"  
#include "lista_encadeada.h"
#include "jogo.h"

void game(JogadorInfo* jogador) {
    system("cls");

    int numDiscos;
    Torre torreA, torreB, torreC;
    create_pilha(&torreA);
    create_pilha(&torreB);
    create_pilha(&torreC);

    printf("\tNumero de discos (3-8): ");
    scanf("%d", &numDiscos);
    limpar_buffer();

    // Inicializa torre A
    for (int i = numDiscos; i > 0; i--) {
        push(&torreA, i);
    }

    int qtdMovimentosFeitos = 0;
    int minimoMovimentos = (int)(pow(2, numDiscos) - 1);
    
    while (1) {
        tela_jogo_em_andamento(jogador, numDiscos, qtdMovimentosFeitos, minimoMovimentos, &torreA, &torreB, &torreC);
        
        char comando[4];
        scanf("%2s", comando);
        limpar_buffer();
        
        // Reiniciar jogo
        if (comando[0] == 'R' || comando[0] == 'r') {
            free_pilha(&torreA);
            free_pilha(&torreB);
            free_pilha(&torreC);
            create_pilha(&torreA);
            create_pilha(&torreB);
            create_pilha(&torreC);
            for (int i = numDiscos; i > 0; i--) {
                push(&torreA, i);
            }
            qtdMovimentosFeitos = 0;
            continue;
        }
        
        //Sai do Jogo
        if (comando[0] == 'S' || comando[0] == 's') {
            free_pilha(&torreA);
            free_pilha(&torreB);
            free_pilha(&torreC);
            return;
        }
    
        Torre* torreOrigem, *torreDestino;
    
        // Valida torre de origem
        switch (comando[0]) {
            case 'A': case 'a': torreOrigem = &torreA; break;
            case 'B': case 'b': torreOrigem = &torreB; break;
            case 'C': case 'c': torreOrigem = &torreC; break;
            default:
                printf("\tTorre de origem invalida!\n");
                Sleep(1000);
                continue;
        }     
    
        // Valida torre de destino
        switch (comando[1]) {
            case 'A': case 'a': torreDestino = &torreA; break;
            case 'B': case 'b': torreDestino = &torreB; break;
            case 'C': case 'c': torreDestino = &torreC; break;
            default:
                printf("\tTorre de destino invalida!\n");
                Sleep(1000);
                continue;
        }   
    
        // Verifica se a torre de origem está vazia
        if (stackIsEmpty(torreOrigem)) {
            printf("\tTorre de origem vazia!\n");
            Sleep(1000);
            continue;
        }
        
        // Verifica se o o movimento eh valido
        int tamanhoDiscoOrigem = torreOrigem->topo->tamanho;
        if (stackIsEmpty(torreDestino) || tamanhoDiscoOrigem < torreDestino->topo->tamanho) {
            pop(torreOrigem);
            push(torreDestino, tamanhoDiscoOrigem);
            qtdMovimentosFeitos++;
        } else {
            printf("\tMovimento invalido! Disco maior sobre menor.\n");
            Sleep(1000);
            continue;
        }
        
        // Verifica vitória
        if (contar_discos_torre(&torreB) == numDiscos || contar_discos_torre(&torreC) == numDiscos) {
            
            // Salva estatísticas
            Estatistica* lista = carregar_do_arquivo();
            inserir_estatistica(&lista, jogador->nome, qtdMovimentosFeitos, minimoMovimentos);
            liberar_lista(lista);
            
            tela_conclusao(qtdMovimentosFeitos, numDiscos);
            
            break;
        }
    }
    
    free_pilha(&torreA);
    free_pilha(&torreB);
    free_pilha(&torreC);
}