#ifndef ATLETA_H_INCLUDED
#define ATLETA_H_INCLUDED

/* Tipo do TAD atleta */
typedef struct _atleta * atleta;

/* Protótipos das funções associadas a um atleta - TAD atleta */

/***********************************************
criaAtleta - Criacao da instancia da estrutura associada a um atleta.
Parametros:  int id, char sexo, char* nome, char* data
Retorno: apontador para a  instancia criada.
Pre-condicoes: parametros != NULL
***********************************************/
atleta criaAtleta(int id,char sexo, char * nome, int dia, int mes, int ano);

/***********************************************
daSexo - Indica o sexo do atleta
Parametros:
    a - atleta
Retorno: sexo do atleta
Pre-condicoes: a != NULL
***********************************************/
char daSexo(atleta a);

/***********************************************
daNome - Indica o nome do atleta
Parametros:
    a - atleta
Retorno: nome do atleta
Pre-condicoes: a != NULL
***********************************************/
char * daNome(atleta a);

/***********************************************
daFaixaEtaria - Indica a faixa etária do atleta
Parametros:
    a - atleta
Retorno: faixa etaria do atleta
Pre-condicoes: a != NULL
***********************************************/
char * daFaixaEtaria(atleta a);


/***********************************************
daDia - Indica o dia de nascimento do atleta
Parametros:
    a - atleta
Retorno: dia de nascimento do atleta
Pre-condicoes: a != NULL
***********************************************/
int daDia(atleta a);

/***********************************************
daMes - Indica o mes de nascimento do atleta
Parametros:
    a - atleta
Retorno: mes de nascimento do atleta
Pre-condicoes: a != NULL
***********************************************/
int daMes(atleta a);

/***********************************************
daAno - Indica o ano de nascimento do atleta
Parametros:
    a - atleta
Retorno: ano de nascimento do atleta
Pre-condicoes: a != NULL
***********************************************/
int daAno(atleta a);



/***********************************************
daTempo - Indica o tempo do atleta
Parametros:
    a - atleta
Retorno: tempo do atleta
Pre-condicoes: a != NULL
***********************************************/
char * daTempo(atleta a);


/***********************************************
igualAtleta - Indica se dois atletas sao iguais (tem o mesmo numero)
Parâmetros:		a - atleta
Retorno: 0 - nao; 1 - sim
Pré-condições: a1 != NULL && a2 != NULL
***********************************************/
int igualAtleta(atleta a1, atleta a2);

/***********************************************
numeroAtleto - Consulta o número do atleta.
Parâmetros:		a - atleta
Retorno: número do atleta
Pré-condições: a != NULL
***********************************************/
int numeroAtleta(atleta a);


/***********************************************
daId - retorna numero do atleta
Parametros:
	a - apontador para a instância de um atleta
Retorno: inteiro com o numero de playlists
Pre-condicoes:  a != NULL
***********************************************/
int daId(atleta a);

/***********************************************
incrementaNumVezesTocadaMusic - incrementa numero de vezes que um atleta fez um tempo
Parametros:
	a - apontador para a instância de um atleta
Retorno:
Pre-condicoes:  a != NULL
***********************************************/
void incrementaNumVezesTempos(atleta a);


/***********************************************
destroiAtleta - Liberta a memoria ocupada pela instancia da estrutura associada a um atleta.
Parametros:
    a - atleta a destuir
Retorno:
Pre-condicoes: a != NULL
***********************************************/
void destroiAtleta(atleta a);

/***********************************************
destroiGenAtleta - destroi instancia de uma estrutura
Parametros:
	a - apontador para a instância de uma atleta
Retorno:
Pre-condicoes:  a != NULL
***********************************************/
void destroiGenAtleta(void *a);


#endif // ATLETA_H_INCLUDED
