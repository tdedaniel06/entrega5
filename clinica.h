#ifndef CLINICA_H_
#define CLINICA_H_

//struct bool
typedef enum{
    false,
    true
}boolean;

/*Structures*/
typedef struct 
{
    int id;
    char nome[50];
    boolean active;
}Clinica;

//code
//menu clinica detailed
void menuClinica();

void consultarMenuClinica(int escolha);

void criarClinica(Clinica *clinicas);

void listarClinica(Clinica *clinicas);

void eliminarClinica(Clinica *clinicas);

#endif