#ifndef GESTOR_H_INCLUDED
#define GESTOR_H_INCLUDED

/* Tipo do TAD gestor */
typedef struct _gestor * gestor;


/* Protótipos das funções associadas a um um - TAD gestor */

//GESTOR-----------------------------------------------

/***********************************************
criaGestor - Criação da instancia da estrutura associada a um gestor.
Parametros:
Retorno: apontador para a  instancia criada
Pre-condicoes:  -
***********************************************/
gestor criaGestor();
/***********************************************
destroiGestor - Liberta a memória ocupada pela instancia da estrutura associada e de todas as estruturas adjacentes associadas.

Parametros:
	g - apontador para a instancia a destruir
Retorno: -
Pre-condicoes:  g != NULL
***********************************************/
void destroiGestor(gestor g);

//ATLETA-----------------------------------------------
/***********************************************
daAtleta - Procura um dado elemento atleta no dicionário atleta.
Parametros:
	g - apontador para a instância do dicionário atleta
	idAtleta - id do atleta que estamos a procura (chave)
Retorno: apontador para a instância de um atleta
Pre-condicoes:  g != NULL
***********************************************/
atleta daAtleta(gestor g,int idAtleta);
/***********************************************
novoAtletaGestor - Adiciona um atleta ao dicionário de atletas.
Parametros:
	g - apontador para a instância do dicionário atleta
	id - id do atleta
	sexo - sexo do atleta
    nome - nome do atleta
    data - data de nascimento do atleta
Retorno: Retorna 1 se adicionar, e 0, caso contrário
Pre-condicoes:  g != NULL
***********************************************/
int novoAtletaGestor(gestor g,int id,char sexo,char * nome,int dia, int mes, int ano);
/***********************************************
existeAtletaGestor - Verifica se um dado atleta existe no dicionário atleta.
Parametros:
	g - apontador para a instância do dicionário atleta
	id - id do atleta que estamos a procura (chave)
Retorno: retorna 1 se existir, e 0, caso contrario
Pre-condicoes:  g != NULL
***********************************************/
int existeAtletaGestor(gestor g, int id);
/***********************************************
comparaSexo - Verifica se  dado dois atletas sao do mesmo sexo.
Parametros:
	g - apontador para a instância do dicionário atleta
	idAtleta1 - id do atleta a comparar
	idAtleta2 - id do atleta a comparar
Retorno: retorna 1 se for igual, e 0, caso contrario
Pre-condicoes:  g != NULL
***********************************************/
int comparaSexo(gestor g, int idAtleta1,int idAtleta2);
/***********************************************
daAtletaFaixaEtaria - Encontra o p-esimo atleta de uma dada Faixa Etaria e de um dado Sexo
	g - apontador para a instância do dicionário atleta
	FaixaEtaria - apontador para a Faixa Etaria a encontrar
	sexo - sexo do atleta a encontrar
	p - posição do atleta a ser encontrado
Retorno: retorna o atleta se encontrar, e NULL caso contrário
Pre-condicoes:  g != NULL
***********************************************/
atleta daAtletaFaixaEtaria(gestor g,char * faixaEtaria,char sexo,int p);
/***********************************************
existeTempoAtleta - Indica se um dado atleta tem um tempo guardado
	g - apontador para a instância do dicionário atleta
	a - atleta a encontrar
Retorno: retorna o 1 se encontrar, e 0 caso contrário
Pre-condicoes:  g != NULL
***********************************************/
int existeTempoAtleta(gestor g,atleta a);
/***********************************************
encontraIDMenor Atleta- Encontra o atleta com menor Id do sexo e Faixa Etaria correspondente
	g - apontador para a instância do dicionário atleta
	FaixaEtaria - apontador para a Faixa Etaria a encontrar
	sexo - sexo do atleta a encontrar
	idAntigo - Maior ID existente(999)
Retorno: o ID desse atleta se encontrar, 0 caso contrário
Pre-condicoes:  g != NULL
***********************************************/
int encontraIDMenorAtleta(gestor g,int idAntigo,char sexo,char * faixaEtaria);
/***********************************************
encontraIDMenorAtleta2 - Encontra o atleta com menor Id a seguir a IdAntigo, do sexo e Faixa Etaria correspondente
	g - apontador para a instância do dicionário atleta
	FaixaEtaria - apontador para a Faixa Etaria a encontrar
	sexo - sexo do atleta a encontrar
	idAntigo - ID imediatamente abaixo do ID a ser encontrado
Retorno: o ID desse atleta se encontrar, 0 caso contrário
Pre-condicoes:  g != NULL
***********************************************/
int encontraIDMenorAtleta2(gestor g,int idAntigo,char sexo,char * faixaEtaria);
/***********************************************
existeAtletaEquipaGestor - Indica se existem equipas com o atleta correspondente
	g - apontador para a instância do dicionário atleta
	a - atleta a encontrar
Retorno: 1 se encontrar, 0 caso contrário
Pre-condicoes:  g != NULL
***********************************************/
int existeAtletaEquipaGestor(gestor g,atleta a);
/***********************************************
eliminaAtletaGestor - retira do dicionario de atletas e elimina o atleta correspondente
	g - apontador para a instância do dicionário atleta
	a - atleta a eliminar
Retorno: 1 se eliminar, 0 caso contrário
Pre-condicoes:  g != NULL
***********************************************/
int eliminaAtletaGestor(gestor g, int idAtleta);
/***********************************************
destroiEquipaGestor - retira da sequencia de equipas e destroi a equipa do atleta correspondente
	g - apontador para a instância do dicionário atleta
	a - atleta da equipa a eliminar
Pre-condicoes:  g != NULL
***********************************************/
void destroiEquipaGestor(gestor g,atleta aux);
/***********************************************
destroiEquipaGestor - retira da sequencia de tempos e destroi os tempos do atleta correspondente
	g - apontador para a instância do dicionário atleta
	a - atleta dos tempos a eliminar
Pre-condicoes:  g != NULL
***********************************************/
void destroiTempoGestor(gestor g,atleta aux);

//EQUIPA-----------------------------------------------

/***********************************************
daEquipa - Procura um dado elemento equipa na sequencia equipa.
Parametros:
	g - apontador para a instância da sequencia equipa
	idEq - id da equipa que estamos a procura
Retorno: apontador para a instância de uma equipa
Pre-condicoes:  g != NULL
***********************************************/
equipa daEquipa(gestor g,char * idEq);
/***********************************************
existeEquipaGestor - Verifica se uma dada equipa existe na sequencia equipa.
Parametros:
	g - apontador para a instância da sequencia equipa
	idEq - id da equipa que estamos a procura
Retorno: retorna 1 se existir, e 0, caso contrario
Pre-condicoes:  g != NULL
***********************************************/
int existeEquipaGestor(gestor g,char * idEq);
/***********************************************
registaEquipa - Adiciona uma equipa a sequencia de equipas.
Parametros:
	g - apontador para a instância da sequencia equipa
	idEquipa - id da equipa
    idAtleta1 - id do primeiro atleta que compoe na equipa
    idAtleta2 - id do segundo atleta que compoe na equipa
Retorno: Retorna 1 se adicionar, e 0, caso contrário
Pre-condicoes:  g != NULL
***********************************************/
int registaEquipa(gestor g,char * idEquipa,int idAtleta1,int idAtleta2);

//MINIMO-----------------------------------------------

/***********************************************
novoMinimoGestor - Adiciona um minimo ao dicionario de minimos.
Parametros:
	g - apontador para a instância do dicionario minimos
	tipoProva - tipo de prova associdada a esse minimo
    minuto - minuto desse minimo
    segundo - segundo desse minimo
    miliSegundo - miliSegundo desse minimo
Retorno: Retorna 1 se adicionar, e 0, caso contrário
Pre-condicoes:  g != NULL
***********************************************/
int novoMinimoGestor(gestor g, char * tipoProva, int minuto, int segundo, int miliSegundo);
/***********************************************
existeMinimoGestor - Verifica se um dado minimo existe no dicionário minimos.
Parametros:
	g - apontador para a instância do dicionário minimos
	chave - tipo de prova que estamos a procura (chave)
Retorno: retorna 1 se existir, e 0, caso contrario
Pre-condicoes:  g != NULL
***********************************************/
int existeMinimoGestor(gestor g, char * chave);
/***********************************************
tamanhoMinimoGestor - Retorna o total de minimos existentes no minimos.
Parametros:
	g - apontador para a instância do dicionário minimos
Retorno: inteiro com o total de minimos no minimo
Pre-condicoes:  g != NULL
***********************************************/
int tamanhoMinimoGestor(gestor g);
/***********************************************
naoTemMinimoProva - Verifica se uma prova possui um tempo minimo definido.
Parametros:
	g - apontador para a instância do dicionário minimos
	tipoProva - tipo de prova que queremos verificar se tem um tempo minimo definido
Retorno: Retorna 1 se adicionar, e 0, caso contrário
Pre-condicoes:  g != NULL
***********************************************/
int naoTemMinimoProva(gestor g,char* tipoProva);
/***********************************************
daNomeTempoMinimoAtleta - Retorna o nome do atleta associado ao respetivo tempo .
Parametros:
	g - apontador para a instância de um gestor
Retorno: retorna nome do atleta com respetiva tempo
Pre-condicoes:  g != NULL
***********************************************/
char* daNomeTempoMinimoAtleta(tempo t);
/***********************************************
actualizaMinimoGestor - Atualiza um minimo do dicionario de minimos.
Parametros:
	g - apontador para a instância do dicionario minimos
	tipoProva - tipo de prova associdada a esse minimo
    minuto - minuto desse minimo
    segundo - segundo desse minimo
    miliSegundo - miliSegundo desse minimo
Retorno:
Pre-condicoes:  g != NULL
***********************************************/
void actualizaMinimoGestor(gestor g, char* tipoProva, int minuto, int segundo, int milisegundo);
/**
daTempoTotalMinimo - Calcula o total do melhor tempo.
Parametros:
    g - apontador para a instância do dicionario minimos
    tipoProva - tipo de prova associado a esse tempo
Retorno: a soma total
Pre-condicoes:  g != NULL
**/
float daTempoTotalMinimo(gestor g, char * tipoProva);

//TEMPO-----------------------------------------------

/***********************************************
registaTempo - Adiciona um tempo a sequencia de tempos.
Parametros:
	g - apontador para a instância da sequencia tempos
	atleta - atleta associado a esse tempo
    min - minuto desse tempo
    seg - segundo desse tempo
    miliSeg - miliSegundo desse tempo
    tipoProva - tipo de prova cujo esse tempo esta associado
    nome_evento - nome do evento associado a esse tempo
Retorno:
Pre-condicoes:  g != NULL
***********************************************/
void registaTempo(gestor g,atleta a, int min, int seg, int miliSeg, char * tipoProva,char * nome_evento);
/***********************************************
tamanhoTempoGestor - Retorna o total de tempos existentes no tempos.
Parametros:
	g - apontador para a instância da sequencia tempos
Retorno: inteiro com o total de temoos no tempos
Pre-condicoes:  g != NULL
***********************************************/
int tamanhoTempoGestor(gestor g);
/***********************************************
existeAtletaTempoProva - Verifica se um dado atleta existe na sequencia tempos.
Parametros:
	g - apontador para a instância da sequencia tempos
    idAtleta - id do atleta
    tipoProva - tipo de prova
Retorno: retorna 1 se existir, e 0, caso contrario
Pre-condicoes:  g != NULL
***********************************************/
int existeAtletaTempoProva(gestor g,int idAtleta,char* tipoProva);
/***********************************************
ProvaVazia - Verifica se uma prova nao possui um unico tempo.
Parametros:
	g - apontador para a instância da sequencia tempos
	tipoProva - tipo de prova que queremos verificar se tem um tempo
Retorno: Retorna 1 se existir, e 0, caso contrário
Pre-condicoes:  g != NULL
***********************************************/
int provaVazia(gestor g,char* tipoProva);
/***********************************************
datamanhoSequenciaTempos - Retorna o tamanho da sequencia tempos.
Parametros:
	g - apontador para a instância da sequencia tempos
Retorno: inteiro com o tamanho da sequencia tempos
Pre-condicoes:  g != NULL
***********************************************/
int daTamanhoSequenciaTempos(gestor g);
/***********************************************
existeTempoGestor - Verifica se um dado tempo existe na sequencia tempos.
Parametros:
	g - apontador para a instância da sequencia tempos
    tipoProva - tipo de prova
Retorno: retorna 1 se existir, e 0, caso contrario
Pre-condicoes:  g != NULL
***********************************************/
int existeTempoGestor(gestor g, int idAtleta,char *tipoProva);
/***********************************************
daTempoAlfabetico2 - Procura um dado elemento tempo na sequencia tempos.
Parametros:
	g - apontador para a instância da sequencia tempos
	tipoProva - tipo de prova associado a esse tempo
	nomeAntigo - nome associado a esse tempo
Retorno: apontador para a instância de um tempo
Pre-condicoes:  g != NULL
***********************************************/
tempo daTempoAlfabetico2(gestor g,char* tipoProva,char * nomeAntigo);
/***********************************************
daMinutoTemposAtleta - Indica os minutos desse tempo desse atleta dessa prova
Parametros:
	g - apontador para a instância da sequencia tempos
	idAtleta - id do atleta
	tipoProva - tipo de prova
	p - ordem do tempo a encontrar
Retorno: minutos do tempo
Pre-condicoes: g != NULL
***********************************************/
int daMinutoTemposAtleta(gestor g,int idAtleta,char * tipoProva,int p);
/***********************************************
daSegundoTemposAtleta - Indica os segundos desse tempo desse atleta dessa prova
Parametros:
	g - apontador para a instância da sequencia tempos
	idAtleta - id do atleta
	tipoProva - tipo de prova
	p - ordem do tempo a encontrar
Retorno: segundos do tempo
Pre-condicoes: g != NULL
***********************************************/
int daSegundoTemposAtleta(gestor g,int idAtleta,char * tipoProva,int p);
/***********************************************
daMiliTemposAtleta - Indica os milisegundos desse tempo desse atleta dessa prova
Parametros:
	g - apontador para a instância da sequencia tempos
	idAtleta - id do atleta
	tipoProva - tipo de prova
	p - ordem do tempo a encontrar
Retorno: milisegundos do tempo
Pre-condicoes: g != NULL
***********************************************/
int daMiliTemposAtleta(gestor g,int idAtleta,char * tipoProva,int p);
/***********************************************
daMelhorTempoMinutoAtletaProva - Indica os melhores minutos desse tempo desse atleta dessa prova
Parametros:
	n - total do tempo
Retorno: minutos do tempo
Pre-condicoes:
***********************************************/
int daMelhorTempoMinutoAtletaProva(float n);
/***********************************************
daMelhorTempoSegundoAtletaProva - Indica os melhores segundos desse tempo desse atleta dessa prova
Parametros:
	n - total do tempo
Retorno: segundos do tempo
Pre-condicoes:
***********************************************/
int daMelhorTempoSegundoAtletaProva(float n);
/***********************************************
daMelhorTempoMiliAtletaProva - Indica os melhores mili desse tempo desse atleta dessa prova
Parametros:
	n - total do tempo
Retorno: milis do tempo
Pre-condicoes:
***********************************************/
int daMelhorTempoMiliAtletaProva(float n);
/***********************************************
daNomeEventoGestor - Indica o nome desse evento
Parametros:
	g - apontador para a instância da sequencia tempos
	idAtlta - id do atleta
	tipoProava - tipo de prova
Retorno: nome do evento associado a esse tempo atleta e tipo de prova
Pre-condicoes: g != NULL
***********************************************/
char * daNomeEventoGestor(gestor g, int idAtleta, char* tipoProva);
/***********************************************
daMlehorTempoAtletaProva - Calcula o total do melhor tempo.
Parametros:
	g - apontador para a instância da sequencia tempos
	idAtleta - id do atleta associado a esse tempo
	tipoProva - tipo de prova associado a esse tempo
Retorno: a soma total
Pre-condicoes:  g != NULL
***********************************************/
float daMelhorTempoAtletaProva(gestor g,int idAtleta,char * tipoProva);
/***********************************************
daMinutoTemposAtletaOrdemID - Indica os melhores minutos desse tempo desse atleta dessa prova por ordem de id
Parametros:
	g - apontador para a instância da sequencia tempos
	tipoProva - tipo de prova
	idAntigo - id a comparar
Retorno: minutos do tempo
Pre-condicoes:  g != NULL
***********************************************/
int daMinutoTemposAtletaOrdemID(gestor g,char * tipoProva,int idAntigo);
/***********************************************
daSegundoTemposAtletaOrdemID - Indica os melhores segundos desse tempo desse atleta dessa prova por ordem de id
Parametros:
	g - apontador para a instância da sequencia tempos
	tipoProva - tipo de prova
	idAntigo - id a comparar
Retorno: segundos do tempo
Pre-condicoes:  g != NULL
***********************************************/
int daSegundoTemposAtletaOrdemID(gestor g,char * tipoProva,int idAntigo);
/***********************************************
daMiliTemposAtletaOrdemID - Indica os melhores mili desse tempo desse atleta dessa prova por ordem de id
Parametros:
	g - apontador para a instância da sequencia tempos
	tipoProva - tipo de prova
	idAntigo - id a comparar
Retorno: mili do tempo
Pre-condicoes:  g != NULL
***********************************************/
int daMiliTemposAtletaOrdemID(gestor g,char * tipoProva,int idAntigo);
/***********************************************
daIdOrdenado - Procura os ids por ordem numerica.
Parametros:
	g - apontador para a instância da sequencia tempos
	tipoProva - tipo de prova
	idAntigo - id a comparar
Retorno: apontador para a instância de um tempo
Pre-condicoes:  g != NULL
***********************************************/
int daIdOrdenado(gestor g,char * tipoProva,int idAntigo);
/***********************************************
daMinutoTemposAtletaOrdemID2 - Indica os melhores minutos desse tempo desse atleta dessa prova por ordem de ID
Parametros:
	g - apontador para a instância da sequencia tempos
	tipoProva - tipo de prova
	idAntigo - ID a comparar
Retorno: minutos do tempo
Pre-condicoes:  g != NULL
***********************************************/
int daMinutoTemposAtletaOrdemID2(gestor g,char * tipoProva,int idAntigo);
/***********************************************
daSegundoTemposAtletaOrdemID2 - Indica os melhores segundos desse tempo desse atleta dessa prova por ordem de id
Parametros:
	g - apontador para a instância da sequencia tempos
	tipoProva - tipo de prova
	idAntigo - id a comparar
Retorno: segundos do tempo
Pre-condicoes:  g != NULL
***********************************************/
int daSegundoTemposAtletaOrdemID2(gestor g,char * tipoProva,int idAntigo);
/***********************************************
daMiliTemposAtletaOrdemID2 - Indica os melhores mili desse tempo desse atleta dessa prova por ordem de id
Parametros:
	g - apontador para a instância da sequencia tempos
	tipoProva - tipo de prova
	idAntigo - id a comparar
Retorno: mili do tempo
Pre-condicoes:  g != NULL
***********************************************/
int daMiliTemposAtletaOrdemID2(gestor g,char * tipoProva,int idAntigo);
/***********************************************
daIdOrdenado2 - Procura os ids por ordem numerica.
Parametros:
	g - apontador para a instância da sequencia tempos
	tipoProva - tipo de prova
	idAntigo - id a comparar
Retorno: apontador para a instância de um tempo
Pre-condicoes:  g != NULL
***********************************************/
int daIdOrdenado2(gestor g,char * tipoProva,int idAntigo);
/***********************************************
daMinutoTemposAtletaOrdemNome2 - Indica os melhores minutos desse tempo desse atleta dessa prova por ordem de nome
Parametros:
	g - apontador para a instância da sequencia tempos
	tipoProva - tipo de prova
	nomeAnterior - nome a comparar
Retorno: minutos do tempo
Pre-condicoes:  g != NULL
***********************************************/
int daMinutoTemposAtletaOrdemNome2(gestor g,char *tipoProva,char *nomeAnterior);
/***********************************************
daSegundoTemposAtletaOrdemNome2 - Indica os melhores segundos desse tempo desse atleta dessa prova por ordem de nome
Parametros:
	g - apontador para a instância da sequencia tempos
	tipoProva - tipo de prova
	nomeAnterior - nome a comparar
Retorno: segundos do tempo
Pre-condicoes:  g != NULL
***********************************************/
int daSegundoTemposAtletaOrdemNome2(gestor g,char *tipoProva,char *nomeAnterior);
/***********************************************
daMiliTemposAtletaOrdemNome2 - Indica os melhores mili desse tempo desse atleta dessa prova por ordem de nome
Parametros:
	g - apontador para a instância da sequencia tempos
	tipoProva - tipo de prova
	nomeAnterior - nome a comparar
Retorno: mili do tempo
Pre-condicoes:  g != NULL
***********************************************/
int daMiliTemposAtletaOrdemNome2(gestor g,char *tipoProva,char *nomeAnterior);
/***********************************************
daMinutoTemposAtletaOrdemNome - Indica os melhores minutos desse tempo desse atleta dessa prova por ordem de nome
Parametros:
	g - apontador para a instância da sequencia tempos
	tipoProva - tipo de prova
	nomeAnterior - nome a comparar
Retorno: minutos do tempo
Pre-condicoes:  g != NULL
***********************************************/
int daMinutoTemposAtletaOrdemNome(gestor g,char* tipoProva,char * nomeAntigo);
/***********************************************
daSegundoTemposAtletaOrdemNome - Indica os melhores segundos desse tempo desse atleta dessa prova por ordem de nome
Parametros:
	g - apontador para a instância da sequencia tempos
	tipoProva - tipo de prova
	nomeAnterior - nome a comparar
Retorno: segundos do tempo
Pre-condicoes:  g != NULL
***********************************************/
int daSegundoTemposAtletaOrdemNome(gestor g,char * tipoProva,char * nomeAntigo);
/***********************************************
daMiliTemposAtletaOrdemNome - Indica os melhores mili desse tempo desse atleta dessa prova por ordem de nome
Parametros:
	g - apontador para a instância da sequencia tempos
	tipoProva - tipo de prova
	nomeAnterior - nome a comparar
Retorno: mili do tempo
Pre-condicoes:  g != NULL
***********************************************/
int daMiliTemposAtletaOrdemNome(gestor g,char * tipoProva,char * nomeAntigo);
/***********************************************
daTempoAlfabetico - Procura um dado elemento tempo na sequencia tempos.
Parametros:
	g - apontador para a instância da sequencia tempos
	tipoProva - tipo de prova associado a esse tempo
	nomeAnterior - nome a comparar
Retorno: apontador para a instância de um tempo
Pre-condicoes:  g != NULL
***********************************************/
tempo daTempoAlfabetico(gestor g,char* tipoProva,char * nomeAntigo);
//ITERADOR-----------------------------------------------

/***********************************************
iteradorEquipaGestor - Devolve um iterador para os elementos guardados na sequencia equipa.
Parametros:
    g - apontador para a instância da sequencia equipa
Retorno: iterador dos elementos da sequencia
Pre-condicoes: g != NULL && vaziaSequencia(g)!=1
***********************************************/
iterador iteradorEquipaGestor(gestor g);
/***********************************************
iteradorDAtletaGestor - Devolve um iterador para os elementos guardados no dicionário atleta.
Parametros:
    j - apontador para a instância do dicionário atleta
Retorno: iterador dos elementos do dicionario
Pre-condicoes: g != NULL && vazioDicionario(g)!=1
***********************************************/
iterador iteradorAtletaGestor(gestor g);
/***********************************************
iteradorMinimoGestor - Devolve um iterador para os elementos guardados no dicionário minimos.
Parametros:
    g - apontador para a instância do dicionário minimos
Retorno: iterador dos elementos do dicionario
Pre-condicoes: g != NULL && vazioDicionario(g)!=1
***********************************************/
iterador iteradorMinimoGestor(gestor g);
/***********************************************
iteradorTempoGestor - Devolve um iterador para os elementos guardados na sequecnia tempos.
Parametros:
    g - apontador para a instância da sequencia tempos
Retorno: iterador dos elementos da sequencia
Pre-condicoes: g != NULL && vaziaSequencia(g)!=1
***********************************************/
iterador iteradorTempoGestor(gestor g);

//FZR

void * removeEquipaGestor(gestor g, int pos);

#endif // GESTOR_H_INCLUDED
