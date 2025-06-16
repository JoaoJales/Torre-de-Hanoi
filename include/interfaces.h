#ifndef INTERFACES_H
#define INTERFACES_H

#include "jogador.h"
#include "pilha.h"


JogadorInfo tela_apresentacao();
void tela_inicial(JogadorInfo jogador);
void tela_como_jogar();
void tela_creditos();
void tela_conclusao(int movimentos, int numDiscos);
void tela_jogo_em_andamento(JogadorInfo* jogador, int numDiscos, int movimentos, int minimoMovimentos, Torre* torreA, Torre* torreB, Torre* torreC);

#endif