#ifndef MINIMO_H_INCLUDED
#define MINIMO_H_INCLUDED

/* Tipo do TAD minimo */
typedef struct _minimo * minimo;

/* Protótipos das funções associadas a um atleta - TAD atleta */

/***********************************************
criaMinimo - Criacao da instancia da estrutura associada a um minimo.
Parametros:  char* tipo_Prova, int min_Minimo, int seg_Minimo, int mili_Minimo
Retorno: apontador para a  instancia criada.
Pre-condicoes: parametros != NULL
***********************************************/
minimo criaMinimo(char * tipo_Prova, int min_Minimo, int seg_Minimo, int mili_Minimo);

/***********************************************
daMinutoMinimo - Indica os minimos minuto desse minimo
Parametros:
    m - minimo
Retorno: minutos do minimo
Pre-condicoes: m != NULL
***********************************************/
int daMinutoMinimo(minimo m);

/***********************************************
daSegundoMinimo - Indica os minimos segundos desse minimo
Parametros:
    m - minimo
Retorno: minutos do minimo
Pre-condicoes: m != NULL
***********************************************/
int daSegundoMinimo(minimo m);

/***********************************************
daMiliMinimo - Indica os minimos milis desse minimo
Parametros:
    m - minimo
Retorno: milis do minimo
Pre-condicoes: t != NULL
***********************************************/
int daMiliMinimo(minimo m);

/***********************************************
daTipoProvaMinimo - Indica o tipo de prova desse minimo
Parametros:
    m - minimo
Retorno: tipo de prova associado a esse minimo
Pre-condicoes: m != NULL
***********************************************/
char * daTipoProvaMinimo(minimo m);

/***********************************************
actualizaMinutoMinimo - Atualiza o minuto desse minimo
Parametros:
    m - minimo
Retorno: tipo de prova associado a esse minimo
Pre-condicoes: m != NULL
***********************************************/
void actualizaMinutoMinimo(minimo m, int minuto);

/***********************************************
actualizaSegundoMinimo - Atualiza o segundo desse minimo
Parametros:
    m - minimo
Retorno: tipo de prova associado a esse minimo
Pre-condicoes: m != NULL
***********************************************/
void actualizaSegundoMinimo(minimo m, int segundo);


/***********************************************
actualizaMiliMinimo - Atualiza o milisegundo desse minimo
Parametros:
    m - minimo
Retorno: void
Pre-condicoes: m != NULL
***********************************************/
void actualizaMiliMinimo(minimo m, int miliSegundo);


/***********************************************
destroiMinimo - Liberta a memoria ocupada pela instancia da estrutura associada a um minimo.
Parametros:
    m - minimo a destuir
Retorno:
Pre-condicoes: a != NULL
***********************************************/
void destroiMinimo(minimo m);

/***********************************************
destroiGenMinimo - destroi instancia de uma estrutura
Parametros:
	m - apontador para a instância de uma minimo
Retorno:
Pre-condicoes:  m != NULL
***********************************************/
void destroiGenMinimo(void *m);
/**
calculaTempominimo - calcula o tempo total minimo
Parametros:
    m - minimo
Retorno: tempo total minimo
Pre-condicoes: m != NULL
**/
float calculaTempoMinimo(minimo m);




#endif // MINIMO_H_INCLUDED
