#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "pilha.h"
#include "utils.h"

#include <math.h>
#include <conio.h>
// RETIRE APOS CRIAR A TELA DE CONCLUSAO




int game(){
    system("cls");
    int numDiscos;
    Torre torreA, torreB, torreC;
    create_pilha(&torreA);
    create_pilha(&torreB);
    create_pilha(&torreC);


    printf("\tNumero de discos: ");
    scanf("%d", &numDiscos);
    limpar_buffer();

    for (int i = numDiscos; i > 0; i--)
    {
        push(&torreA, i);
    }


    int qtdMovimentosFeitos = 0;
    while (1)
    {
        system("cls");
        // TELA (QUANTIDADE DE MOVIMENTOS, QUANTIDADE MINIMA DE MOVIMENTOS)
        printf("\tQuantidade movimentos: %d\n", qtdMovimentosFeitos);
        imprimir_torres(&torreA, &torreB, &torreC, numDiscos);

        printf("\n");

        char comando[4];
        printf("\tDigite o comando: ");
        scanf("%2s", comando);
    
        Torre* torreOrigem, *torreDestino;
    
        switch (comando[0]) {
            case 'A':
            case 'a': 
                torreOrigem = &torreA;
                break;
            case 'B':
            case 'b': 
                torreOrigem = &torreB;
                break;
            case 'C':
            case 'c': 
                torreOrigem = &torreC;
                break;
        default:
            printf("\tTorre de origem invalida!\n");
            Sleep(3000);
            continue;
        }     
    
        switch (comando[1]) {
            case 'A':
            case 'a': 
                torreDestino = &torreA;
                break;
            case 'B':
            case 'b':  
                torreDestino = &torreB;
                break;
            case 'C':
            case 'c': 
                torreDestino = &torreC;
                break;
        default:
            printf("\tTorre de destino invalida!\n");
            Sleep(3000);
            continue;
        }   
    
        int tamanhoDiscoOrigem;
        if (stackIsEmpty(torreOrigem))
        {
            printf("\tA torre de origem esta vazia!\n");
            Sleep(3000);
            continue;
        }else{
            tamanhoDiscoOrigem = torreOrigem->topo->tamanho;
        }
        
        if (stackIsEmpty(torreDestino) || tamanhoDiscoOrigem < torreDestino->topo->tamanho)
        {
            pop(torreOrigem);
            push(torreDestino, tamanhoDiscoOrigem);
            qtdMovimentosFeitos++;
        }else{
            printf("\tMovimento [%s] invalido!\n", comando);
            Sleep(3000);
            continue;
        }
        
        if (contar_discos_torre(&torreB) == numDiscos || contar_discos_torre(&torreC) == numDiscos) {

            // TELA DE CONCLUSAO (FAÇA UM GETCH())
            system("cls");
            imprimir_torres(&torreA, &torreB, &torreC, numDiscos);
            printf("\n\tParabens! Voce concluiu o jogo em %d movimentos.\n", qtdMovimentosFeitos);
            printf("\tMinimo possivel de movimentos: %d\n\n", (int)(pow(2, 3)) - 1); // 2^n - 1
            printf("\tPressione qualquer tecla para continuar\n");
            getch();
            break;
        }   
    
    }
    free_pilha(&torreA);
    free_pilha(&torreB);
    free_pilha(&torreC);
    
    return 0;
}