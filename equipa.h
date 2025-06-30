#ifndef EQUIPA_H_INCLUDED
#define EQUIPA_H_INCLUDED

/* Tipo do TAD equipa */
typedef struct _equipa * equipa;

/* Prot�tipos das fun��es associadas a um atleta - TAD atleta */

/**
criaEquipa - Criacao da instancia da estrutura associada a uma equipa.
Parametros:  meter
Retorno: apontador para a  instancia criada.
Pre-condicoes: parametros != NULL
**/
equipa criaEquipa(char * idEquipa,atleta atleta1,atleta atleta2 );


/**
destruirAtleta - Liberta a memoria ocupada pela instancia da estrutura associada a uma equipa.
Parametros:
    e - equipa a destuir
Retorno:
Pre-condicoes: e != NULL
**/
void destroiEquipa(equipa e);

/**
existeEquipa - Indica se duas equipas sao iguais (tem o mesmo numero)
Par�metros:        e - equipa
Retorno: 0 - nao; 1 - sim
Pr�-condi��es: e1 != NULL && e2 != NULL
***/
int existeEquipa(equipa e1, equipa e2);

/**
daIdEquipa - retorna id da equipa
Par�metros:        e - equipa
Retorno: retorna string com id da equipa
Pr�-condi��es: e != NULL
***/
char * daIdEquipa(equipa e);

/**
daPrimeiroAtleta - retorna primeiro atleta da equipa
Par�metros:        e - equipa
Retorno: retorna primeiro atleta da equipa
Pr�-condi��es: e != NULL
***/
atleta daPrimeiroAtleta(equipa e);

/**
daSegundoAtleta - retorna segundo atleta da equipa
Par�metros:        e - equipa
Retorno: retorna segundo atleta da equipa
Pr�-condi��es: e != NULL
***/
atleta daSegundoAtleta(equipa e);

/***********************************************
destroiGenEquipa - destroi instancia de uma estrutura
Parametros:
	e - apontador para a inst�ncia de uma equipa
Retorno:
Pre-condicoes:  e != NULL
***********************************************/
void destroiGenEquipa(void *e);





#endif // EQUIPA_H_INCLUDED

