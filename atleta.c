#include <stdlib.h>
#include <string.h>

#include "atleta.h"

/* Constantes do TAD atleta */

#define SIZEN 50
#define SIZEF 30

/* Estrutura de dados do TAD atleta */
struct _atleta{
    char sexo;
    char nome[SIZEN];
    int dia,mes,ano;
    int id;
    char faixaEtaria[SIZEF];
};

/* Implementações das funcões do TAD atleta */
atleta criaAtleta(int id,char sexo, char * nome, int dia, int mes, int ano){
    atleta a;
    int auxAnos= 2021 - ano;;
    char faixaEtaria[SIZEF];
    a= (atleta) malloc(sizeof(struct _atleta));
    if (a==NULL)
        return NULL;
    if (auxAnos <= 18)
        strcpy(faixaEtaria,"junior");
    else if (auxAnos > 18 && auxAnos <= 35)
        strcpy(faixaEtaria,"senior");
    else if (auxAnos > 35)
        strcpy(faixaEtaria,"veterano");
    strcpy (a->nome,nome);
    a->dia = dia;
    a->mes = mes;
    a->ano = ano;
    a->sexo = sexo;
    a->id = id;

    strcpy(a->faixaEtaria, faixaEtaria);
    return a;
}

int igualAtleta(atleta a1, atleta a2){
    int igual = 0;
    if (a1->id == a2->id)
        igual = 1;
    return igual;
}

int numeroAtleta(atleta a){
    return a->id;
}

char * daNome(atleta a){
    return a->nome;
}

char * daFaixaEtaria(atleta a){
    return a->faixaEtaria;
}

int daDia(atleta a){
    return a->dia;
}

int daMes(atleta a){
    return a->mes;
}

int daAno(atleta a){
    return a->ano;
}

char daSexo(atleta a){
    return a->sexo;
}

int daId(atleta a){
    return a->id;
}

void destroiAtleta(atleta a){
    free(a);
}

void destroiGenAtleta(void *a){
    destroiAtleta((atleta) a);
}
