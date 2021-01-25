#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"


//variavel para o id do funcionario
int idBase = 0;
Funcionario funcionarios[50];

//menu funcionario detailed
void menuFuncionario(){
    int escolha;

    printf("---------- Funcionarios ----------");
    printf("\n");
    printf("\n1 - Adicionar funcionario");
    printf("\n2 - Listar funcionarios");
    printf("\n3 - Editar funcionario");
    printf("\n4 - Eliminar funcionario");
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
        printf("Criar um novo funcionario:");
        criarFuncionario(funcionarios);
        break;
    case 2:
        printf("Listar funcionarios: \n");
        listarFuncionario(funcionarios);
        break; 
    case 3:
        printf("Editar func");
        break;   
    case 4:
        printf("Eliminar funcionario \n");
        eliminarFuncionario(funcionarios);
        break;   
    
    default:
        break;
    }
}

//criar funcionario (request dados)
void criarFuncionario(Funcionario *funcionarios){
    Funcionario funcionario;
    puts("\n");
    
    //como fazer sem utilizar o fflsuh
    fflush(stdin);


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
    //como fazer sem utilizar o fflsuh
    fflush(stdin);

    printf("Cargo (M - medico / E - enfermeiro / A - auxiliar): ");
    scanf("%c", &funcionario.tipo);

    funcionario.active = true;

    //adicionar funcionario ao array funcionarios
    funcionarios[idBase] = funcionario;

    //incrementa ao idBase para o proximo funcionario
    idBase++;

    //voltar ao menu funcionario
    menuFuncionario();
}

//listar funcionarios
void listarFuncionario(Funcionario *funcionarios){
    printf("ID  |  NOME  |  GENERO  |  IDADE  |  VENCIMENTO  |  TIPO \n");
    for (int i = 0; i < idBase; i++)
    {
        if (funcionarios[i].active)
        {
            printf("%d  ", funcionarios[i].id);
            printf("  %s  ", funcionarios[i].nome);
            printf("  %c  ", funcionarios[i].genero);
            printf("  %d  ", funcionarios[i].idade);
            printf("  %d  ", funcionarios[i].vencimento);
            printf("  %c  ", funcionarios[i].tipo);
            printf("  %c  \n", funcionarios[i].active);
        }
    }

    //voltar ao menu funcionario
    menuFuncionario();
}

void eliminarFuncionario(Funcionario *funcionarios){
    int idEliminar;
    printf("Qual o id do funcionario a eliminar: ");
    scanf("%d", &idEliminar);

    if (idEliminar >= idBase)
    {
        printf("Utilizador não encontrado!");
    }
    else{
        //modificar o funcionario.active para false(fica desativado)
        funcionarios[idEliminar].active = false;
    }

    //voltar ao menu funcionario
    menuFuncionario();
}


