#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "resultados.h"
#include "funcionario.h"

int somaMM = 0, somaME = 0, somaMA = 0, somaFM = 0, somaFE = 0, somaFA = 0, idClinica, idFunc;

void menuDados(){
    int escolha;

    printf("---------- Funcionarios ----------");
    printf("\n");
    printf("\n1 - Informacao de funcionarios por clinica.");
    printf("\n2 - Listar vencimento dos medicos por clinica.");
    printf("\n3 - Numero de consultas dos enfermeiros de uma clinica.");
    printf("\n4 - Apresentar lista de consultas de um funcionario.");
    printf("\n0 - Voltar");
    printf("\n");
    printf("\nSelecionar: ");
    scanf("%d", &escolha);

    consultarMenuResuntados(escolha);
}

void consultarMenuResuntados(int escolha){
    switch (escolha)
    {
    case 0:
        listarMenu();
        break;
    case 1:
        printf("Quantidade e Media de Idades, por Clinica, dos Funcionarios: \n");
        idadeFuncionarios();
        break;
    case 2:
        printf("Soma dos Vencimentos, por Genero: \n");
        listarMedicosVencimento();
        break; 
    case 3:
        printf("Marcacoes dos funcionarios de uma clinica: \n");
        printf("Qual clinica deseja pesquisar: ");
        scanf("%d", &idClinica);
        marcacoesPorEnfermeiro(idClinica);
        break;   
    case 4:
        printf("Listar agenda do medico/enfermeiro: \n");
        printf("Qual o medico a pesquisar: ");
        scanf("%d", &idFunc);
        listarAgendaFuncionario(idFunc);
        break;   
    
    default:
        break;
    }
}

void idadeFuncionarios(){
    //variaveis
    int somaMedicos = 0, somaEnf = 0, somaAux = 0, contMedicos = 0, contEnf = 0, contAux = 0;

   //por cada clinica, procura funcionarios 
    for (int i = 0; i < idBaseC; i++)
    {
        for (int j = 0; j < idBase; j++)
        {
            if (funcionarios[j].clinica == i)
            {
                if (funcionarios[j].tipo == 'M')
                {
                    somaMedicos += funcionarios[j].idade;
                    contMedicos++;
                }
                else if (funcionarios[j].tipo == 'E')
                {
                    somaEnf += funcionarios[j].idade;
                    contEnf++;
                }
                else
                {
                    somaAux += funcionarios[j].idade;
                    contAux++;
                }
            }
        }
        //Apresentar Resultados
        printf("Clinica: %d - %s\n", clinicas[i].id, clinicas[i].nome);
        printf("     Medicos:  %d   -  media: %d\n", contMedicos, (somaMedicos/contMedicos));
        printf("     Enfermeiros:  %d   -  media: %d\n", contEnf, (somaEnf/contEnf));
        printf("     Auxiliares:  %d   -  media: %d\n", contAux, (somaAux/contAux)); 
    }

    somaVencimentos();
}

int somaVencimentos(){

    int somaMM = 0, somaME = 0, somaMA = 0, somaFM = 0, somaFE = 0, somaFA = 0;

    for (int i = 0; i < idBase; i++)
    {
        //saber se e masculino
        if(funcionarios[i].genero == 'M')
        {
            //Saber se e medico 
            if (funcionarios[i].tipo == 'M')
            {
                somaMM += funcionarios[i].vencimento;
            }
            //Saber se e enfermeiro
            else if(funcionarios[i].tipo == 'E')
            {
                somaME += funcionarios[i].vencimento;
                
            }
            //e auxiliar
            else
            {
                somaMA += funcionarios[i].vencimento;
                
            }
        }
        //ja sabemos que e feminino
        else
        {
            //Saber se e medica
            if (funcionarios[i].tipo == 'M')
            {
                somaFM += funcionarios[i].vencimento;
                
            }
            //Saber se e enfermeira
            else if(funcionarios[i].tipo == 'E')
            {
                somaFE += funcionarios[i].vencimento;
                
            }
            //e auxiliar
            else
            {
                somaFA += funcionarios[i].vencimento;
                
            }
        }
    }
    printf("Masculino:\n");
    printf("Vencimentos de Medicos: %d\n", somaMM);
    printf("Vencimentos de Enfermeiros: %d\n", somaME);
    printf("Vencimentos de Auxiliares: %d\n", somaMA);
    printf("Feminino:\n");
    printf("Vencimentos de Medicas: %d\n", somaFM);
    printf("Vencimentos de Enfermeiras: %d\n", somaFE);
    printf("Vencimentos de Auxiliares Femininas: %d\n", somaFA);

    menuDados();
}

void listarMedicosVencimento(){
    //variaveis
    int somaVencMedicos = 0;
    
    for (int j = 0; j < idBaseC; j++)
    {
        printf("Clinica: %d - %s", clinicas[j].id, clinicas[j].nome);
        for (int i = 0; i < idBase; i++)
        {
            if (funcionarios[i].tipo == 'M')
            {
                printf("%s   -   %d", funcionarios[i].clinica, funcionarios[i].nome, funcionarios[i].vencimento);
                somaVencMedicos += funcionarios[i].vencimento;
            }
        }
    }
    printf("Total de Vencimentos de Medicos: %d", somaVencMedicos);
    menuDados();
}

//marcacoes por enfermeiro de uma clinica
void marcacoesPorEnfermeiro(int idClinica){
    int nMarcacoes = 0;

    for (int i = 0; i < idBaseC; i++)
    {
        for (int j = 0; j < idBase; j++)
        {
            printf("Clinica: %d  -  %s", clinicas[i].id, clinicas[i].nome); // info da clinica
            if (funcionarios[j].clinica == i && funcionarios[j].tipo == 'E')
            {
                for (int k = 0; k < idBaseU; k++)
                {
                    if(consultas[k].idFuncionario == j){
                        nMarcacoes++;
                    }
                }
                printf("  Enfermeiro: %d  -  %s, tem %d marcacoes.", funcionarios[j].id, funcionarios[j].nome, nMarcacoes);
                nMarcacoes = 0;
            }
        }
    }    
    menuDados();
}

//listar agenda do medico/enfermeiro
void listarAgendaFuncionario(int id){

    for (int i = 0; i < idBaseU; i++)
    {
        if (consultas[i].idFuncionario == id)
        {
            printf(" Utente: %s \n", consultas[i].nome);
        }
    }
    menuDados();
}
