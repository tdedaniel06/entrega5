#include <stdio.h>

void criarClinica(Clinica *clinica, int id)
{
    int id;
    printf("Insira o Nome da Clinica: ");
    fgets(clinica->id, 50, stdin);
    clinica->id[strlen(clinica->id) - 1] = '\0';

    clinica->id = n + 1;
    clinica->active = true;
}

void removerClinica(Clinica *clinica)
{
    clinica->active = false;
}