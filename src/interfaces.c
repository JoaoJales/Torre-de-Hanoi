#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <math.h>  
#include "utils.h"
#include "jogo.h"
#include "estatisticas.h"
#include "interfaces.h"


JogadorInfo tela_apresentacao() {
    JogadorInfo jogador;
    system("cls");
    printf("\n\t============================================\n");
    printf("\t|          BEM-VINDO A TORRE DE HANOI      |\n");
    printf("\t============================================\n\n");
    
    printf("\tDigite o seu nome: ");
    fgets(jogador.nome, sizeof(jogador.nome), stdin);
    jogador.nome[strcspn(jogador.nome, "\n")] = '\0';
    
    return jogador;
}

void tela_inicial(JogadorInfo jogador) {
    system("cls");
    printf("\n\t============================================\n");
    printf("\t|               MENU PRINCIPAL             |\n");
    printf("\t============================================\n");
    printf("\t|  Jogador: %s \n", jogador.nome);
    printf("\t============================================\n");
    printf("\t|                                          |\n");
    printf("\t|  1. Iniciar Jogo                         |\n");
    printf("\t|  2. Estatisticas                         |\n");
    printf("\t|  3. Como Jogar                           |\n");
    printf("\t|  4. Creditos                             |\n");
    printf("\t|  5. Sair                                 |\n");
    printf("\t|                                          |\n");
    printf("\t============================================\n");
    printf("\tEscolha uma opcao: ");
}

void tela_como_jogar() {
    system("cls");
    printf("\n\t============================================\n");
    printf("\t|              COMO JOGAR                  |\n");
    printf("\t============================================\n");
    printf("\t|                                          |\n");
    printf("\t|  Objetivo: Mover todos os discos para    |\n");
    printf("\t|  outra torre seguindo as regras:         |\n");
    printf("\t|                                          |\n");
    printf("\t|  1. Apenas um disco pode ser movido      |\n");
    printf("\t|     por vez                              |\n");
    printf("\t|  2. So pode mover o disco do topo        |\n");
    printf("\t|  3. Nao pode colocar disco maior sobre   |\n");
    printf("\t|     um menor                             |\n");
    printf("\t|                                          |\n");
    printf("\t|  Comandos: Digite a combinacao de torres |\n");
    printf("\t|  (ex: AB para mover da torre A para B)   |\n");
    printf("\t|                                          |\n");
    printf("\t============================================\n");
    printf("\n\tPressione qualquer tecla para voltar...");
    getch();
}
void tela_jogo_em_andamento(JogadorInfo* jogador, int numDiscos, int movimentos, int minimoMovimentos, Torre* torreA, Torre* torreB, Torre* torreC) {
    system("cls");
    
    printf("\n\t+--------------------------------------------+\n");
    printf("\t|            TORRE DE HANOI - JOGO           |\n");
    printf("\t+--------------------------------------------+\n");
    printf("\t| Jogador: %s \n", jogador->nome);
    printf("\t| Discos: %d  Movimentos: %d (Minimo: %d)    |\n", 
           numDiscos, movimentos, minimoMovimentos);
    printf("\t+--------------------------------------------+\n\n");
    
    imprimir_torres(torreA, torreB, torreC, numDiscos);
    
    printf("\n\t+--------------------------------------------+\n");
    printf("\t| COMANDOS: AB, AC, BA, BC, CA, CB           |\n");
    printf("\t| R - Reiniciar   S - Sair                   |\n");
    printf("\t+--------------------------------------------+\n");
    printf("\tDigite o comando: ");
}
void tela_creditos() {
    system("cls");
    printf("\n\t============================================\n");
    printf("\t|                CREDITOS                  |\n");
    printf("\t============================================\n");
    printf("\t|                                          |\n");
    printf("\t|  Projeto final da disciplina de          |\n");
    printf("\t|  Estrutura de Dados                      |\n");
    printf("\t|                                          |\n");
    printf("\t|  Engenharia de Software                  |\n");
    printf("\t|  Universidade Catolica de Brasilia       |\n");
    printf("\t|                                          |\n");
    printf("\t|  Desenvolvido por:                       |\n");
    printf("\t|  - Joao Ricardo Jales Cirino             |\n");
    printf("\t|  - Felipe Lima Duarte                    |\n");
    printf("\t|                                          |\n");
    printf("\t============================================\n");
    printf("\n\tPressione qualquer tecla para voltar...");
    getch();
}

void tela_conclusao(int movimentos, int numDiscos) {
    system("cls");
    int minimo = (int)(pow(2, numDiscos) - 1);
    
    printf("\n\t+--------------------------------------------+\n");
    printf("\t|            PARABENS! VOCE VENCEU!          |\n");
    printf("\t+---------------------------------------------+\n");
    printf("\t|                                            |\n");
    printf("\t|  Voce concluiu o jogo em %d movimentos    \n", movimentos);
    printf("\t|  Minimo possivel: %d movimentos           \n", minimo);
    printf("\t|                                            |\n");
    
    if (movimentos == minimo) {
        printf("\n\tPERFEITO! Voce atingiu o minimo de movimentos!\n");
    }
    
    printf("\t+--------------------------------------------+\n");
    printf("\n\tPressione qualquer tecla para continuar...");
    getch();
}