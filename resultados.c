#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "resultados.h"
#include "funcionario.h"

int somaMM = 0, somaME = 0, somaMA = 0, somaFM = 0, somaFE = 0, somaFA = 0;

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
        printf("Quantidade e Média de Idades, por Clinica, dos Funcionarios:");
        idadeFuncionarios();
        menuDados();
        break;
    case 2:
        printf("Soma dos Vencimentos, por Genero: \n");
        somaVencimentos();
        break; 
    case 3:
        printf("Marcacoes dos funcionarios de uma clinica: \n");
        printf("Qual clinica deseja pesquisar: ");
        scanf("%d", &idClinica);
        marcacoesPorEnfermeiro(idClinica);
        break;   
    case 4:
        printf("Eliminar funcionario \n");
        //eliminarFuncionario(funcionarios);
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
        printf("Clinica: %d - %s", clinicas[i].id, clinicas[i].nome);
        printf("     Medicos:  %d   -  media: %d", contMedicos, (somaMedicos/contMedicos));
        printf("     Enfermeiros:  %d   -  media: %d", contEnf, (somaEnf/contEnf));
        printf("     Auxiliares:  %d   -  media: %d", contAux, (somaAux/contAux)); 
    }
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
    printf("Vencimentos de Medicos: %d", somaMM);
    printf("Vencimentos de Enfermeiros: %d", somaME);
    printf("Vencimentos de Auxiliares: %d", somaMA);
    printf("Feminino:\n");
    printf("Vencimentos de Medicas: %d", somaFM);
    printf("Vencimentos de Enfermeiras: %d", somaFE);
    printf("Vencimentos de Auxiliares Femininas: %d", somaFA);
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
}
