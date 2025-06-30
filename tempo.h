#ifndef TEMPO_H_INCLUDED
#define TEMPO_H_INCLUDED

/* Tipo de dados: tempo */
typedef struct _tempo * tempo;

/* Prototipos das funcoes associadas a tempo */

/***********************************************
criaTempo - Criação da instancia da estrutura associada a um tempo.
Parametros:
	minuto - minutos desse tempo
	segundos - segundos desse tempo
	milisegundos - milisegundos desse tempo
	tipoProva - tipo de prova associado a esse tempo
	nome_evento - nome do evento associado a esse tempo

Retorno: apontador para a  instancia criada
Pre-condicoes:  -
***********************************************/
tempo criaTempo(atleta a,int minuto, int segundo, int milisegundo, char * tipoProva,char * nome_evento);

/***********************************************
daAtletaTempo - Indica o atleta associado a esse tempo
Parametros:
    t - tempo
Retorno: atleta associado a esse tempo
Pre-condicoes: t != NULL
***********************************************/
atleta daAtletaTempo(tempo t);

/***********************************************
daTipoProva - Indica o tipo de prova associada a esse tempo
Parametros:
    t - tempo
Retorno: tipo de prova
Pre-condicoes: t != NULL
***********************************************/
char * daTipoProva(tempo t);
/***********************************************
daTempoMinuto - Indica os minutos desse tempo
Parametros:
    t - tempo
Retorno: minutos do tempo
Pre-condicoes: t != NULL
***********************************************/
int daTempoMinuto(tempo t);

/***********************************************
daTempoSegundo - Indica os segundos desse tempo
Parametros:
    t - tempo
Retorno: segundos do tempo
Pre-condicoes: t != NULL
***********************************************/
int daTempoSeg(tempo t);

/***********************************************
daTempoMili - Indica os milisegundos desse tempo
Parametros:
    t - tempo
Retorno: mili do tempo
Pre-condicoes: t != NULL
***********************************************/
int daTempoMili(tempo t);

/***********************************************
daNomeEvento - Indica o nome desse evento
Parametros:
    t - tempo
Retorno: nome do evento associado a esse tempo
Pre-condicoes: t != NULL
***********************************************/
char* daNomeEvento(tempo t);
/***********************************************
calculaTempo - calcula o tempo total
Parametros:
    t - tempo
Retorno: tempo total
Pre-condicoes: t != NULL
***********************************************/
float calculaTempo(tempo t);

/***********************************************
destroiTempo - Liberta a memoria ocupada pela instancia da estrutura associada a um tempo.
Parametros:
    t - tempo a destuir
Retorno:
Pre-condicoes: a != NULL
***********************************************/
void destroiTempo(tempo t);

/***********************************************
destroiGenTempo - destroi instancia de uma estrutura
Parametros:
	t - apontador para a instância de uma tempo
Retorno:
Pre-condicoes:  t != NULL
***********************************************/
void destroiGenTempo(void *t);


#endif // TEMPO_H_INCLUDED
