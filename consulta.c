#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consulta.h"


int idBaseU = 0;
Consulta consultas[50];

//menu marcar consulta detailed
void menuConsulta(){
    int escolha;

    printf("---------- Marcar Consulta ----------");
    printf("\n");
    printf("\n1 - Marcar consulta");
    printf("\n2 - Listar consultas");
    printf("\n3 - Editar funcionario");
    printf("\n4 - Desmarcar consulta");
    printf("\n0 - Voltar");
    printf("\n");
    printf("\nSelecionar: ");
    scanf("%d", &escolha);

    consultarMenuConsulta(escolha);
}

void consultarMenuConsulta(int escolha){
    switch (escolha)
    {
    case 0:
        listarMenu();
        break;
    case 1:
        printf("Criar uma marcacao:");
        criarConsulta(consultas);
        break;
    case 2:
        printf("Listar funcionarios: \n");
        listarConsultas(consultas);
        break; 
    case 3:
        printf("Editar funcionarios");
        break;   
    case 4:
        printf("Eliminar funcionario \n");
        eliminarConsulta(consultas);
        break;   
    
    default:
        break;
    }
}

void criarConsulta(Consulta *consultas){
    Consulta consulta;
    puts("");

    //como fazer sem utilizar o fflsuh
    fflush(stdin);

    consulta.id = idBaseU;

    printf("Nome Utente: ");
    fgets(consulta.nome, 50, stdin);
    consulta.nome[strlen(consulta.nome) - 1] = '\0'; //elimina o enter que fica guardado no buffer

    printf("Numero sns: ");
    scanf("%d", &consulta.sns);

    printf("Funcionario: ");
    scanf("%d", &consulta.idFuncionario);

    //verifica se funcionario existe


    printf("Data Consulta (d/m/a): ");
    scanf("%d/%d/%d", &consulta.dataConsulta.dia, &consulta.dataConsulta.mes, &consulta.dataConsulta.ano);
    
    //verifica se a data está disponivel para aquele funcionario

    consulta.active = true;

    //adiciona ao array de consultas
    consultas[idBaseU] = consulta;

    //incrementa o idBaseU para a proxima consulta
    idBaseU++;

    //volta ao menu consultas
    menuConsulta();
}

//listar consultas
void listarConsultas(Consulta *consultas){
    printf("ID  |  NOME  |  SNS  |   DATA   |  FUNCIONARIO \n");
    for (int i = 0; i < idBaseU; i++)
    {
        if (consultas[i].active)
        {
            printf("%d   ", consultas[i].id);
            printf("  %s  ", consultas[i].nome);
            printf("  %d  ", consultas[i].sns);
            printf("  %d/%d/%d  ", consultas[i].dataConsulta.dia, consultas[i].dataConsulta.mes, consultas[i].dataConsulta.ano);
            printf("   %d  \n", consultas[i].idFuncionario);
        }
    }
    //volta ao menu consultas
    menuConsulta();
}

//eliminar consultas
void eliminarConsulta(Consulta *consultas){
    int idEliminar;
    printf("Qual o id da consulta a eliminar: ");
    scanf("%d", &idEliminar);

    if (idEliminar >= idBaseU)
    {
        printf("Utilizador não encontrado!");
    }
    else{
        //modificar o funcionario.active para false(fica desativado)
        consultas[idEliminar].active = false;
    }

    //volta ao menu consultas
    menuConsulta();
}
