#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clinica.h"

//variavel para o id da clinica
int idBaseC = 0;
Clinica clinicas[50];

//menu Clinica
void menuClinica(){
    int escolha;

    printf("---------- Clinica ----------");
    printf("\n");
    printf("\n1 - Adicionar Clinica");
    printf("\n2 - Listar Clinica");
    printf("\n3 - Editar Clinica");
    printf("\n4 - Eliminar Clinica");
    printf("\n0 - Voltar");
    printf("\n");
    printf("\nSelecionar: ");
    scanf("%d", &escolha);

    consultarMenuClinica(escolha);
}

void consultarMenuClinica(int escolha){
    switch (escolha)
    {
    case 0:
        listarMenu();
        break;
    case 1:
        printf("Criar uma nova Clinica:");
        criarClinica(clinicas);
        break;
    case 2:
        printf("Listar Clinicas: \n");
        listarClinica(clinicas);
        break; 
    case 3:
        printf("Editar Clinica");
        break;   
    case 4:
        printf("Eliminar Clinica \n");
        eliminarClinica(clinicas);
        break;   
    
    default:
        break;
    }
}

//criar funcionario (request dados)
void criarClinica(Clinica *clinicas){
    Clinica clinica;
    puts("");
    
    //como fazer sem utilizar o fflsuh
    fflush(stdin);

    //definir id clinica
    clinica.id = idBaseC;

    printf("Nome: ");
    fgets(clinica.nome, 50, stdin);
    clinica.nome[strlen(clinica.nome) - 1] = '\0'; //elimina o enter que fica guardado no buffer

    //como fazer sem utilizar o fflsuh
    fflush(stdin);

    clinica.active = true;

    //adicionar clinica ao array Clinicas
    clinicas[idBaseC] = clinica;

    //incrementa ao idBaseC para a proximo clinica
    idBaseC++;

    //voltar ao menu clinica
    menuClinica();
}

void listarClinica(Clinica *clinicas){
    printf("ID  |  NOME  \n");
    for (int i = 0; i < idBaseC; i++)
    {
        if (clinicas[i].active)
        {
            printf("%d  ", clinicas[i].id);
            printf("  %s  \n", clinicas[i].nome);
        }
    }

    //voltar ao menu Clinica
    menuClinica();
}

void eliminarClinica(Clinica *clinicas){

    int idEliminar;
    printf("Qual o id da Clinica a eliminar: ");
    scanf("%d", &idEliminar);

    if (idEliminar >= idBaseC)
    {
        printf("Clinica não encontrada!");
    }
    else{
        //modificar a clinica.active para false(fica desativado)
        clinicas[idEliminar].active = false;
    }

    //voltar ao menu funcionario
    menuClinica();
}

