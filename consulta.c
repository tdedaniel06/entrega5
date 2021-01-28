#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consulta.h"

int idBaseU = 0, verificarF, verificarA;
Consulta consultas[50];

//menu marcar consulta detailed
void menuConsulta()
{
    int escolha;

    printf("---------- Marcar Consulta ----------");
    printf("\n");
    printf("\n1 - Marcar consulta");
    printf("\n2 - Listar consultas");
    printf("\n3 - Desmarcar consulta");
    printf("\n0 - Voltar");
    printf("\n");
    printf("\nSelecionar: ");
    scanf("%d", &escolha);

    consultarMenuConsulta(escolha);
}

void consultarMenuConsulta(int escolha)
{
    switch (escolha)
    {
    case 0:
        listarMenu();
        break;
    case 1:
    if (idBase == 0)
        {
            printf("Nao existem funcionarios!");
            menuConsulta();
        }
        else{
            printf("Criar uma marcacao:");
            criarConsulta(consultas);
        }
        break;
    case 2:
        printf("Listar Marcacoes: \n");
        listarConsultas(consultas);
        break;
    case 3:
        if (idBaseU == 0)
        {
            printf("Nao existem consultas agendadas!");
            menuConsulta();
        }
        else{
            printf("Eliminar Consulta \n");
            eliminarConsulta(consultas);
        }
        break;

    default:
        break;
    }
}

void criarConsulta(Consulta *consultas)
{
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
    verificarF = verificaFuncionario(consulta.idFuncionario);
    while (verificarF < 0)
    {
        printf("Funcionario nao encontrado!\n");
        printf("Funcionario: ");
        scanf("%d", &consulta.idFuncionario);

        //verifica se funcionario existe
        verificarF = verificaFuncionario(consulta.idFuncionario);
    }

    printf("Data Consulta (d/m/a): ");
    scanf("%d/%d/%d", &consulta.dataConsulta.dia, &consulta.dataConsulta.mes, &consulta.dataConsulta.ano);

    //verifica se a data está disponivel para aquele funcionario
    verificarA = verificaAgendaFuncionario(consulta.idFuncionario, consulta.dataConsulta);
    while (verificarA == 0)
    {
        printf("Funcionario com agenda cheia, escolha outra data!\n");
        printf("Data Consulta (d/m/a): ");
        scanf("%d/%d/%d", &consulta.dataConsulta.dia, &consulta.dataConsulta.mes, &consulta.dataConsulta.ano);

        //verifica se funcionario existe
        verificarA = verificaAgendaFuncionario(consulta.idFuncionario, consulta.dataConsulta);
    }

    consulta.active = true;

    //adiciona ao array de consultas
    consultas[idBaseU] = consulta;

    //incrementa o idBaseU para a proxima consulta
    idBaseU++;

    //volta ao menu consultas
    menuConsulta();
}

//listar consultas
void listarConsultas(Consulta *consultas)
{
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
void eliminarConsulta(Consulta *consultas)
{
    int idEliminar;
    printf("Qual o id da consulta a eliminar: ");
    scanf("%d", &idEliminar);

    if (idEliminar >= idBaseU)
    {
        printf("Utilizador não encontrado!");
    }
    else
    {
        //modificar o funcionario.active para false(fica desativado)
        consultas[idEliminar].active = false;
    }

    //volta ao menu consultas
    menuConsulta();
}

//verifica existencia do funcionario selecionado
int verificaFuncionario(int id)
{
    int verifica = -1;

    //percorre os funcionarios (idBase e o id dos func, ou seja, a sua posicao no array)
    for (int i = 0; i < idBase; i++)
    {
        //verificar que apenas medicos e enfermeiros possam atender a consultas e se estao ativos
        if (funcionarios[i].tipo == 'M' || funcionarios[i].tipo == 'E' && funcionarios[i].active)
        {
            //verifica se o id enviado tem correspondencia
            if (id == i)
            {
                verifica = i;
            }
        }
    }

    return verifica;
}

int verificaAgendaFuncionario(int id, Data data){
    int nConsultas = 0;

    //percorre todas as consultas
    for (int i = 0; i < idBaseU; i++)
    {        
        //procurar o funcionario correspondente
        if (consultas[i].idFuncionario == id)
        {
            //verificar se as datas sao iguais
            if (consultas->dataConsulta.dia == data.dia && consultas->dataConsulta.mes == data.mes && consultas->dataConsulta.ano == data.ano)
            {
                nConsultas++; //se forem, increment
            }
        }
    }

    //apenas duas consultas por dia
    if (nConsultas >= 2)
    {
        return 0;
    }
    else
    {
        return 1;
    }   
}