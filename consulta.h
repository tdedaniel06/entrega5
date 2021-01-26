#ifndef CONSULTA_H_
#define CONSULTA_H_

//struct data
typedef struct
{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct
{
    int id;
    char nome[50];
    int sns;
    Data dataConsulta;
    int idFuncionario;
    boolean active;
}Consulta;


//menu consultas
void menuConsulta();

//consultar menu
void consultarMenuConsulta(int escolha);

//criar marcacao de  consulta
void criarConsulta(Consulta *consultas);

//listar consultas
void listarConsultas(Consulta *consultas);

//eliminar consulta
void eliminarConsulta(Consulta *consultas);


#endif