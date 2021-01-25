#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clinica.h"

//variavel para o id da clinica
int idBase = 0;
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
    puts("\n");
    
    //como fazer sem utilizar o fflsuh
    fflush(stdin);

    //definir id clinica
    clinica.id = idBase;

    printf("Nome: ");
    fgets(clinica.nome, 50, stdin);
    clinica.nome[strlen(clinica.nome) - 1] = '\0'; //elimina o enter que fica guardado no buffer

    //como fazer sem utilizar o fflsuh
    fflush(stdin);

    clinica.active = true;

    //adicionar clinica ao array Clinicas
    clinicas[idBase] = clinica;

    //incrementa ao idBase para a proximo clinica
    idBase++;

    //voltar ao menu clinica
    menuClinica();
}


void eliminarClinica(Clinica *clinica)
{
    int idEliminar;
    printf("Qual o id da Clinica a eliminar: ");
    scanf("%d", &idEliminar);

    if (idEliminar >= idBase)
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