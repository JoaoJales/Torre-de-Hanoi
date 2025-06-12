#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "jogo.h"
#include "utils.h"

#include <conio.h>

//CRIE interfaces.c e .h // estatisticas.c e .h // lista_encadeada.c e .h (lista com as estatisticas e funcoes para buscar por data ou por nome)

// CRIE O jogador.c e jogador.h com a struct
typedef struct JogadorInfo
{
    char nome[50];
}JogadorInfo;

// UTILIZE O getch() da biblioteca <conio.h> PARA USAR ESSE TIPO DE FUNCAO NAS TELAS -> ("Pressione qualquer tecla para voltar ao menu...")

int main(){
    int opcao;
    JogadorInfo jogador;
    system("cls");
    //jogador = tela_aprensentacao();
    //criar_jogador(&jogador) -> (DENTRO DE 'tela_aprensentacao()'):
    printf("\tDigite o seu nome: ");
    fgets(jogador.nome, sizeof(jogador.nome), stdin);
    jogador.nome[strcspn(jogador.nome, "\n")] = '\0';

    do{
        //tela_Inicial(jogador);
        printf("\tDigite uma opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();
        
        opcao = 1;
        switch (opcao){
        case 1:
            // game(&jogador);
            game();
            break;
        case 2:
            // estatisticas();
            break;
        case 3:
            //tela_como_jogar();
            break;
        case 4:
            //tela_creditos();
            break;
        case 5:
            opcao = 0;
            break;
        default:
            printf("Escolha invalida!\n");
            break;
        }
        
    } while (opcao);

    system("clear");
    printf("\n\t--------------------------------------------\n");
    printf("\t|            Obrigado por Jogar! 🎮         |\n");
    printf("\t---------------------------------------------\n");
    



    return 0;
}