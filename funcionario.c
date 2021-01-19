#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"

//variavel para o id do funcionario
int idBase = 0;

//menu funcionario detailed
void menuFuncionario(){
    int escolha;

    printf("---------- Funcionarios ----------");
    printf("\n");
    printf("\n1 - Listar funcionarios");
    printf("\n2 - Editar funcionario");
    printf("\n3 - Eliminar funcionario");
    printf("\n0 - Voltar");
    printf("\n");
    printf("\nSelecionar: ");
    scanf("%d", &escolha);

    consultarMenuFuncionario(escolha);
}

void consultarMenuFuncionario(int escolha){
    switch (escolha)
    {
    case 0:
        listarMenu();
        break;
    case 1:
        printf("Listar func");
        listarFuncionario();
        break; 
    case 2:
        printf("Editar func");
        break;   
    
    default:
        break;
    }
}

//criar funcionario (request dados)
void criarFuncionario(){
    Funcionario funcionario;
    printf("Criar um novo funcionario:");
    printf("\n");

    //definir id funcionario
    funcionario.id = idBase;

    printf("Nome: ");
    fgets(funcionario.nome, 50, stdin);
    funcionario.nome[strlen(funcionario.nome) - 1] = '\0'; //elimina o enter que fica guardado no buffer

    printf("Genero (M/F): ");
    scanf("%c", &funcionario.genero);

    printf("Idade: ");
    scanf("%d", &funcionario.idade);

    printf("Vencimento: ");
    scanf("%d", &funcionario.vencimento);

    printf("Cargo (M - medico / E - enfermeiro / A - auxiliar): ");
    scanf("%c", &funcionario.tipo);

    funcionario.active = true;

    //incrementa ao idBase para o proximo funcionario
    idBase++;
}


