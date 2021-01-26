#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "resultados.h"

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
        printf("Criar um novo funcionario:");
        //criarFuncionario(funcionarios);
        break;
    case 2:
        printf("Listar funcionarios: \n");
        //listarFuncionario(funcionarios);
        break; 
    case 3:
        printf("Editar func");
        break;   
    case 4:
        printf("Eliminar funcionario \n");
        //eliminarFuncionario(funcionarios);
        break;   
    
    default:
        break;
    }
}