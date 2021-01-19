#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

//listar menu
void listarMenu(){
    int escolha;

    printf("---------- Vamos todos ficar bem! ----------");
    printf("\n");
    printf("Escreva o numero da opção desejada ou 0 para sair");
    printf("\n");
    printf("\n");
    printf("1 - Clinicas");
    printf("2 - Funcionarios");
    printf("3 - Marcar Consulta");
    printf("4 - Consultar dados");
    printf("\n");
    printf("Selecionar: ");
    scanf("%d", &escolha);

    consultarMenu(escolha);
}

void consultarMenu(int escolha){
    switch (escolha)
    {
    case 1:
        printf("1");
        break;
    case 2:
        printf("2");
        break;
    case 3:
        printf("3");
        break;
    case 4:
        printf("4");
        break;
    case 0:
        printf("0");
        break;
    
    default:
        printf("A sua seleção não é valida, volta a escolher!");
        listarMenu();
        break;
    }
}


