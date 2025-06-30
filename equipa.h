#ifndef EQUIPA_H_INCLUDED
#define EQUIPA_H_INCLUDED

/* Tipo do TAD equipa */
typedef struct _equipa * equipa;

/* Protótipos das funções associadas a um atleta - TAD atleta */

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
Parâmetros:        e - equipa
Retorno: 0 - nao; 1 - sim
Pré-condições: e1 != NULL && e2 != NULL
***/
int existeEquipa(equipa e1, equipa e2);

/**
daIdEquipa - retorna id da equipa
Parâmetros:        e - equipa
Retorno: retorna string com id da equipa
Pré-condições: e != NULL
***/
char * daIdEquipa(equipa e);

/**
daPrimeiroAtleta - retorna primeiro atleta da equipa
Parâmetros:        e - equipa
Retorno: retorna primeiro atleta da equipa
Pré-condições: e != NULL
***/
atleta daPrimeiroAtleta(equipa e);

/**
daSegundoAtleta - retorna segundo atleta da equipa
Parâmetros:        e - equipa
Retorno: retorna segundo atleta da equipa
Pré-condições: e != NULL
***/
atleta daSegundoAtleta(equipa e);

/***********************************************
destroiGenEquipa - destroi instancia de uma estrutura
Parametros:
	e - apontador para a instância de uma equipa
Retorno:
Pre-condicoes:  e != NULL
***********************************************/
void destroiGenEquipa(void *e);





#endif // EQUIPA_H_INCLUDED

