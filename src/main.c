#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "interfaces.h"
#include "jogo.h"
#include "jogador.h"
#include "estatisticas.h"
#include "utils.h"

int main() {
    int opcao;
    JogadorInfo jogador = tela_apresentacao();

    do {
        tela_inicial(jogador);
        scanf("%d", &opcao);
        limpar_buffer();
        
        switch (opcao) {
            case 1:
                game(&jogador);
                break;
            case 2:
                estatisticas();
                break;
            case 3:
                tela_como_jogar();
                break;
            case 4:
                tela_creditos();
                break;
            case 5:
                opcao = 0;
                break;
            default:
                printf("\tEscolha invalida!\n");
                Sleep(1000);
                break;
        }
    } while (opcao);

    system("cls");
    printf("\n\t--------------------------------------------\n");
    printf("\t|            Obrigado por Jogar!           |\n");
    printf("\t--------------------------------------------\n");
    Sleep(2000);

    return 0;
}