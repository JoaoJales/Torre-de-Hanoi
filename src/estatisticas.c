#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>  
#include "estatisticas.h"
#include "lista_encadeada.h"

void menu_busca(Estatistica* lista) {
    int opcao;
    do {
        system("cls");
        printf("\n\t=== MENU DE BUSCA ===\n");
        printf("\t1. Buscar por nome\n");
        printf("\t2. Buscar por data\n");
        printf("\t3. Voltar\n");
        printf("\tEscolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: {
                char nome[50];
                printf("\tDigite o nome: ");
                scanf("%s", nome);
                buscar_por_nome(lista, nome);
                break;
            }
            case 2: {
                int dia, mes, ano;
                printf("\tDigite a data (dd mm aaaa): ");
                scanf("%d %d %d", &dia, &mes, &ano);
                
                struct tm tm = {0};
                tm.tm_year = ano - 1900;
                tm.tm_mon = mes - 1;
                tm.tm_mday = dia;
                time_t data = mktime(&tm);
                
                buscar_por_data(lista, data);
                break;
            }
            case 3:
                return;
            default:
                printf("\tOpcao invalida!\n");
                Sleep(1000);
        }
    } while (1);
}

void estatisticas() {
    Estatistica* lista = carregar_do_arquivo();
    
    int opcao;
    do {
        system("cls");
        printf("\n\t=== ESTATISTICAS ===\n");
        printf("\t1. Mostrar todas\n");
        printf("\t2. Buscar\n");
        printf("\t3. Voltar\n");
        printf("\tEscolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                mostrar_todas_estatisticas(lista);
                break;
            case 2:
                menu_busca(lista);
                break;
            case 3:
                liberar_lista(lista);
                return;
            default:
                printf("\tOpcao invalida!\n");
                Sleep(1000);
        }
    } while (1);
}