#ifndef FUNCIONARIO_H_
#define FUNCIONARIO_H_


/* structures */
typedef struct
{
    int id;
    char nome[50];
    char genero;
    int idade;
    float vencimento;
    char tipo;
    char clinica;
    boolean active;
}Funcionario;

//code
//menu funcionario detailed
void menuFuncionario();

void consultarMenuFuncionario(int escolha);

//criar funcionario
void criarFuncionario(Funcionario *funcionarios);

//listar funcionario
void listarFuncionario(Funcionario *funcionarios);

//eliminar funcionario
void eliminarFuncionario(Funcionario *funcionarios);

#endif