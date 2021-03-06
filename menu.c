#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "clinica.c"
#include "funcionario.c"
#include "consulta.c"
#include "resultados.c"

//listar menu
void listarMenu(){
    int escolha;

    printf("---------- Vamos todos ficar bem! ----------");
    printf("\n");
    printf("Escreva o numero da opcao desejada ou 0 para sair");
    printf("\n");
    printf("\n1 - Clinicas");
    printf("\n2 - Funcionarios");
    printf("\n3 - Marcar Consulta");
    printf("\n4 - Consultar dados");
    printf("\n");
    printf("\nSelecionar: ");
    scanf("%d", &escolha);

    consultarMenu(escolha);
}

void consultarMenu(int escolha){
    switch (escolha)
    {
    case 1:
        printf("1");
        menuClinica();
        break;
    case 2:
        printf("2");
        menuFuncionario();
        break;
    case 3:
        printf("3");
        menuConsulta();
        break;
    case 4:
        printf("4");
        menuDados();
        break;
    case 0:
        printf("0");
        break;
    
    default:
        printf("A sua selecao nao e valida, volta a escolher!\n");
        listarMenu();
        break;
    }
}


