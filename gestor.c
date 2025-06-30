#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "iterador.h"
#include "sequencia.h"
#include "dicionario.h"
#include "atleta.h"
#include "equipa.h"
#include "minimo.h"
#include "tempo.h"
#include "gestor.h"

#define MAXATLETAS 999
#define MAXEQUIPAS 999
#define MAXPROVAS 8
#define SIZEP 50
#define IDEQUIPA 20
#define SIZEN 50
#define SIZEF 30

struct _gestor{
    dicionario atleta;
    sequencia equipa;
    sequencia tempos;
    dicionario minimos;
};

gestor criaGestor(){
    gestor g;
    g = (gestor)malloc(sizeof(struct _gestor));
    if(g == NULL){
        return NULL;
    }
    g->atleta = criaDicionario(MAXATLETAS,0);
    if (g->atleta == NULL){
        free(g);
        return NULL;
    }
    g->equipa = criaSequencia(MAXEQUIPAS);
    if(g->equipa == NULL){
        destroiDicionario(g->atleta);
        free(g);
        return NULL;
    }
    g->minimos = criaDicionario(MAXPROVAS,1);
    if(g->minimos == NULL){
        destroiDicionario(g->atleta);
        destroiSequencia(g->equipa);
        free(g);
        return NULL;
    }
    g->tempos = criaSequencia(MAXATLETAS);
    if(g->tempos == NULL){
        destroiDicionario(g->atleta);
        destroiSequencia(g->equipa);
        destroiDicionario(g->minimos);
        free(g);
        return NULL;
    }

    return g;
}
void destroiGestor(gestor g){
    if (g == NULL)
        return;
    destroiDicionario(g->atleta);
    destroiSequencia(g->equipa);
    destroiDicionario(g->minimos);
    destroiSequencia(g->tempos);
    free(g);

}

int existeMinimoGestor(gestor g, char * chave){
    char ch[SIZEP];
    strcpy(ch, chave);
    return existeElemDicionario(g->minimos,(void*)ch);
}

int novoMinimoGestor(gestor g, char * tipoProva, int minuto, int segundo, int miliSegundo){
    minimo m = criaMinimo(tipoProva, minuto, segundo, miliSegundo);
    char ch[SIZEP];
    strcpy(ch, tipoProva);
    int ad = adicionaElemDicionario(g->minimos, (void*) ch, (void*)m);
    if (ad != 1)
        destroiMinimo(m);
    return ad;
}

int tamanhoMinimoGestor(gestor g){
    return tamanhoDicionario(g->minimos);
}

iterador iteradorMinimoGestor(gestor g){
    return iteradorDicionario(g->minimos);
}

void actualizaMinimoGestor(gestor g, char* tipoProva, int minuto, int segundo, int milisegundo){
    minimo m;
    m = (minimo)elementoDicionario(g->minimos,(void*) tipoProva);
    actualizaMinutoMinimo(m,minuto);
    actualizaSegundoMinimo(m,segundo);
    actualizaMiliMinimo(m,milisegundo);
}


int novoAtletaGestor(gestor g,int id,char sexo,char * nome,int dia, int mes, int ano){
    atleta a = (atleta)criaAtleta(id,sexo,nome,dia,mes,ano);
    int ch = id;
    int ad =adicionaElemDicionario(g->atleta,(void* )&ch,(void *)a);
    if(ad != 1)
        destroiAtleta(a);
    return 1;
}

/*char * atribuiFaixaEtaria(int ano){
    int auxAnos;
    char faixaEtaria[SIZEF];
    auxAnos = 2021 - ano;
    if (auxAnos <= 18)
        strcpy(faixaEtaria,"juvenil");
    if (auxAnos > 18 && auxAnos <= 35)
        strcpy(faixaEtaria,"senior");
    if (auxAnos > 35)
        strcpy(faixaEtaria,"veterano");
    return (char *)faixaEtaria;
}*/

int registaEquipa(gestor g,char * idEquipa,int idAtleta1, int idAtleta2){
    atleta a1,a2;
    a1 = (atleta)daAtleta(g, idAtleta1);
    a2 = (atleta)daAtleta(g,idAtleta2);
    equipa e = criaEquipa(idEquipa,a1,a2);
    if(e != NULL){
        adicionaPosSequencia(g->equipa,(void*)e,tamanhoSequencia(g->equipa)+1);
    }
    return 1;
}

void registaTempo(gestor g,atleta a, int min, int seg, int miliSeg, char * tipoProva,char * nome_evento){
    tempo t  = criaTempo(a,min,seg,miliSeg,tipoProva,nome_evento);
    adicionaPosSequencia(g->tempos,t,tamanhoSequencia(g->tempos)+1);
}

int existeAtletaGestor(gestor g,int idAtleta){
    int i,ch = idAtleta;
    i = existeElemDicionario(g->atleta,(void*)&ch);
    return i;
}


int comparaSexo(gestor g,int idAtleta1,int idAtleta2){
    char a,b;
    atleta a1 = (atleta)elementoDicionario(g->atleta,(void*) &idAtleta1);
    a= (char)daSexo(a1);
    atleta a2 = (atleta)elementoDicionario(g->atleta,(void*) &idAtleta2);
    b= (char)daSexo(a2);
    if(a==b){
        return 1;
    }
    return 0;
}

atleta daAtleta(gestor g,int idAtleta){
    atleta a;
    a = (atleta)elementoDicionario(g->atleta,(void*) &idAtleta);
    return (atleta)a;
}

equipa daEquipa(gestor g,char * idEq){
    iterador it;
    equipa e;
    char tmp[IDEQUIPA];
    it = iteradorSequencia(g->equipa);
    while(temSeguinteIterador(it)){
        e = (equipa) seguinteIterador(it);
        strcpy(tmp,daIdEquipa(e));
        if(strcmp(tmp,idEq)==0)
            return (equipa)e;
    }
    return (equipa) e;
}

int posEquipa(gestor g, char *idEq){
    equipa e;
    int pos =-1;
    iterador it = iteradorSequencia( g->equipa);
    while(temSeguinteIterador(it)){
        e=(equipa)seguinteIterador(it);
        if(strcmp(idEq,daIdEquipa(e))==0){
             pos=1;
        }
    }
    destroiIterador(it);
    return pos;
}


void* removeEquipaGestor(gestor g, int pos){
    equipa minhaEquipa;

    minhaEquipa = removePosSequencia(g->equipa,pos);
    destroiGenEquipa(minhaEquipa);
    return minhaEquipa;
}


int existeAtletaEquipaGestor(gestor g,atleta a){
    iterador it = iteradorSequencia(g->equipa);
    equipa eq;
    int resposta = 0;
    while(temSeguinteIterador(it)){
        eq = seguinteIterador(it);
        if((daPrimeiroAtleta(eq)== a)||(daSegundoAtleta(eq)== a)){
            resposta = 1;
        }
    }
    destroiIterador(it);
    return resposta;
}

int eliminaAtletaGestor(gestor g, int idAtleta){
    atleta aux;
    iterador itTempos,itEquipas;
    int controlo = 0;
    itTempos = iteradorSequencia(g->tempos);
    itEquipas = iteradorSequencia(g->equipa);
    aux = removeElemDicionario(g->atleta, &idAtleta);
    if((existeAtletaEquipaGestor(g,aux) == 0)){
        destroiTempoGestor(g,aux);
        destroiAtleta(aux);
        controlo = 1;
    }
    if(existeAtletaEquipaGestor(g,aux) == 1){
        destroiEquipaGestor(g,aux);
        destroiTempoGestor(g,aux);
        destroiAtleta(aux);
        controlo = 1;
    }
    destroiIterador(itEquipas);
    destroiIterador(itTempos);
    return controlo;
}

void destroiTempoGestor(gestor g,atleta aux){
    iterador it;
    it=iteradorSequencia(g->tempos);
    tempo t,aux2;
    int i=1;
    while(temSeguinteIterador(it)){
        t=(tempo)seguinteIterador(it);
        if (daAtletaTempo(t)==aux){
            aux2 = (tempo) removePosSequencia(g->tempos,i-1);
            destroiTempo(aux2);
            i--;
        }
    if(tamanhoSequencia(g->tempos) == i){
            return;
        }
    i++;
    }
}


void destroiEquipaGestor(gestor g,atleta aux){
    iterador it;
    it=iteradorSequencia(g->equipa);
    equipa eq,aux2;
    int p=1;
    while(temSeguinteIterador(it)){
        eq = (equipa)seguinteIterador(it);
        if((daPrimeiroAtleta(eq) == aux)||(daSegundoAtleta(eq) == aux)){
            aux2 = (equipa) removePosSequencia(g->equipa,p);
            destroiEquipa(aux2);
            p--;
        }
        if(tamanhoSequencia(g->equipa) == p){
            return;
        }
        p++;
    }
}

int existeEquipaGestor(gestor g,char * idEq){
    if(posEquipa(g,idEq)==-1){
        return 0;
    }
    return 1;
}

int existeTempoGestor(gestor g, int idAtleta,char *tipoProva){
    int a =0;
    iterador it;
    tempo t;
    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if((daAtleta(g,idAtleta) == daAtletaTempo(t))&&(strcmp(tipoProva,daTipoProva(t))==0)) {
                    a=0;
            }
    }
    destroiIterador(it);
    return a;
}


int daMinutoTemposAtleta(gestor g,int idAtleta,char * tipoProva,int p){
    iterador it;
    int i=0;
    tempo t;
    int hora;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if((i==p)&&(daAtleta(g,idAtleta) == daAtletaTempo(t))&&(strcmp(tipoProva,daTipoProva(t))==0)) {
                hora = daTempoMinuto(t);
                return hora;
            }
        i++;
    }
    destroiIterador(it);
    return -1;
}

int daSegundoTemposAtleta(gestor g,int idAtleta,char * tipoProva,int p){
    iterador it;
    int i=0;
    tempo t;
    int segundo;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if((i==p)&&(daAtleta(g,idAtleta) == daAtletaTempo(t))&&(strcmp(tipoProva,daTipoProva(t))==0)) {
                segundo = daTempoSeg(t);
                return segundo;
            }
        i++;
    }
    destroiIterador(it);
    return -1;
}

int daMiliTemposAtleta(gestor g,int idAtleta,char * tipoProva,int p){
    iterador it;
    int i=0;
    tempo t;
    int mili;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if((i==p)&&(daAtleta(g,idAtleta) == daAtletaTempo(t))&&(strcmp(tipoProva,daTipoProva(t))==0)) {
                mili = daTempoMili(t);
                return mili;
            }
        i++;
    }
    destroiIterador(it);
    return -1;
}


int posAtletaTempoProva(gestor g, int idAtleta, char* tipoProva){
    tempo t;
    int pos = -1;
    iterador it = iteradorSequencia(g->tempos);
    while(temSeguinteIterador(it)){
        t = (tempo)seguinteIterador(it);
        if((daAtleta(g,idAtleta) == daAtletaTempo(t))&&(strcmp(tipoProva,daTipoProva(t))==0)){
            pos = 1;
        }
    }
    destroiIterador(it);
    return pos;
}

int existeAtletaTempoProva(gestor g,int idAtleta,char* tipoProva){
    if(posAtletaTempoProva(g,idAtleta,tipoProva)==-1)
        return 0;
    return 1;
}

char * daNomeEventoGestor(gestor g, int idAtleta, char* tipoProva){
    tempo t;
    iterador it;
    int auxInt = 0;
    it = iteradorSequencia(g->tempos);
    while(temSeguinteIterador(it)){
        t=(tempo)seguinteIterador(it);
        if((daAtleta(g,idAtleta) == daAtletaTempo(t))&&(strcmp(tipoProva,daTipoProva(t))==0)){
            if(auxInt == 0){
                auxInt = daMelhorTempoAtletaProva(g,daId(daAtletaTempo(t)),daTipoProva(t));
            }
            if(auxInt > daMelhorTempoAtletaProva(g,daId(daAtletaTempo(t)),daTipoProva(t))){
                auxInt = daMelhorTempoAtletaProva(g,daId(daAtletaTempo(t)),daTipoProva(t));
            }
        }
    }
    destroiIterador(it);
    return (char*)daNomeEvento(t);
}

int naoTemMinimoProva(gestor g,char* tipoProva){
    return existeElemDicionario(g->minimos,(void*) tipoProva);
}

int provaVazia(gestor g,char* tipoProva){
    iterador it;
    tempo t;
    int aux=0;
    it = iteradorSequencia(g->tempos);
    while(temSeguinteIterador(it)){
        t=(tempo)seguinteIterador(it);
        if(strcmp(tipoProva,daTipoProva(t)) == 0){
            aux = 1;
        }
    }
    destroiIterador(it);
    return aux;
}

int tamanhoTempoGestor(gestor g){
    return tamanhoSequencia(g->tempos);
}
iterador iteradorTempoGestor(gestor g){
    return iteradorSequencia(g->tempos);
}
char* daNomeTempoMinimoAtleta(tempo t){
    return daNome(daAtletaTempo(t));
}

float daTempoTotalMinimo(gestor g, char * tipoProva){
    minimo m;
    float somaAux = 0;
    m = (minimo)elementoDicionario(g->minimos,(void*) tipoProva);
    somaAux = calculaTempoMinimo(m);
    return somaAux;
}

float daMelhorTempoAtletaProva(gestor g,int idAtleta,char * tipoProva){
    float somaAux = 0;
    iterador it;
    tempo t;
    it = iteradorSequencia(g->tempos);
    while(temSeguinteIterador(it)){
        t=(tempo)seguinteIterador(it);
        if (daAtletaTempo(t)==daAtleta(g,idAtleta)){
            if(strcmp(tipoProva,daTipoProva(t))== 0){
                if (somaAux == 0){
                    somaAux = calculaTempo(t);
                }
                if ((somaAux != 0)&&(calculaTempo(t)<somaAux)){
                    if(somaAux > calculaTempo(t)){
                        somaAux = calculaTempo(t);
                    }
                }
            }
        }
    }
    destroiIterador(it);
    return somaAux;
}

int daMelhorTempoMinutoAtletaProva(float n){
    return (int)(n / 60);
}

int daMelhorTempoSegundoAtletaProva(float n){
    return (int)n - (daMelhorTempoMinutoAtletaProva(n)*60);
}
int daMelhorTempoMiliAtletaProva(float n){
    int p = (int)n;
    return round(n*100 - p*100);
}

atleta daAtletaFaixaEtaria(gestor g,char * faixaEtaria,char sexo,int p){
    int idAntigo = 999;
    int idAtleta;
    int i = 0;
    iterador it;
    atleta a;
    it = iteradorSequencia(g->tempos);
    while (encontraIDMenorAtleta(g,idAntigo,sexo,faixaEtaria)!= 0){
        idAtleta = encontraIDMenorAtleta(g,idAntigo,sexo,faixaEtaria);
        a = daAtleta(g,idAtleta);
        if((strcmp(faixaEtaria,daFaixaEtaria(a))== 0)&&(existeTempoAtleta(g,a)==1)&&(sexo == daSexo(a))){
            if(i==p){
                destroiIterador(it);
                return a;
            }
            else{
                i++;
            }
        }
        idAntigo = idAtleta;
    }
    destroiIterador(it);
    return NULL;
}


int existeTempoAtleta(gestor g,atleta a){
    iterador it;
    int auxId=0;
    tempo t;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if(a == daAtletaTempo(t)) {
                if(auxId==0){
                    auxId=daId(daAtletaTempo(t));
                }
                else{
                    if (auxId > daId(daAtletaTempo(t))){
                        auxId = daId(daAtletaTempo(t));
                    }
                }
            }
    }
    destroiIterador(it);
    if(auxId == 0){
        return 0;
    }
    else{
        return 1;
    }
}

int encontraIDMenorAtleta(gestor g,int idAntigo,char sexo,char * faixaEtaria){
iterador it;
    int auxId=0;
    tempo t;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if((daId(daAtletaTempo(t)) < idAntigo)&&(daSexo(daAtletaTempo(t))== sexo)&&(strcmp(faixaEtaria,daFaixaEtaria(daAtletaTempo(t)))==0)) {
                if(auxId==0){
                    auxId=daId(daAtletaTempo(t));
                }
                else{
                    if (auxId > daId(daAtletaTempo(t))){
                        auxId = daId(daAtletaTempo(t));
                    }
                }
            }
    }
    destroiIterador(it);
    return auxId;
}

int encontraIDMenorAtleta2(gestor g,int idAntigo,char sexo,char * faixaEtaria){
    iterador it;
    int auxId=0;
    tempo t;
    atleta a;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            a = daAtletaTempo(t);
            if((daId(a) > idAntigo)&&(daSexo(a) == sexo)&&(strcmp(faixaEtaria,daFaixaEtaria(a))== 0)) {
                if(auxId==0){
                    auxId=daId(a);
                }
                else{
                    if (auxId > daId(a)){
                        auxId = daId(a);
                    }
                }
            }
    }
    destroiIterador(it);
    return auxId;
}


int daMinutoTemposAtletaOrdemID(gestor g,char * tipoProva,int idAntigo){
    iterador it;
    int auxId=0;
    tempo t;
    int min;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if((strcmp(tipoProva,daTipoProva(t))==0)&&(daId(daAtletaTempo(t)) < idAntigo)) {
                if(auxId==0){
                    auxId=daId(daAtletaTempo(t));
                }
                else{
                    if (auxId > daId(daAtletaTempo(t))){
                        auxId = daId(daAtletaTempo(t));
                    }
                }
            }
    }
    destroiIterador(it);
    if(auxId == 0){
        return -1;
    }
    min =  daMelhorTempoMinutoAtletaProva(daMelhorTempoAtletaProva(g,auxId,tipoProva));
    return min;
}

int daSegundoTemposAtletaOrdemID(gestor g,char * tipoProva,int idAntigo){
    iterador it;
    int auxId=0;
    tempo t;
    int seg;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if((strcmp(tipoProva,daTipoProva(t))==0)&&(daId(daAtletaTempo(t))<idAntigo)) {
                if(auxId==0){
                    auxId=daId(daAtletaTempo(t));
                }
                else{
                    if (auxId > daId(daAtletaTempo(t))){
                        auxId = daId(daAtletaTempo(t));
                    }
                }
            }
    }
    destroiIterador(it);
    if(auxId == 0){
        return -1;
    }
    seg = daMelhorTempoSegundoAtletaProva(daMelhorTempoAtletaProva(g,auxId,tipoProva));
    return seg;
}

int daMiliTemposAtletaOrdemID(gestor g,char * tipoProva,int idAntigo){
    iterador it;
    int auxId=0;
    tempo t;
    int mili;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if((strcmp(tipoProva,daTipoProva(t))==0)&&(daId(daAtletaTempo(t))<idAntigo)) {
                if(auxId==0){
                    auxId=daId(daAtletaTempo(t));
                }
                else{
                    if (auxId > daId(daAtletaTempo(t))){
                        auxId = daId(daAtletaTempo(t));
                    }
                }
            }
    }
    destroiIterador(it);
    if(auxId == 0){
        return -1;
    }
    mili = daMelhorTempoMiliAtletaProva(daMelhorTempoAtletaProva(g,auxId,tipoProva));
    return mili;
}

int daMinutoTemposAtletaOrdemID2(gestor g,char * tipoProva,int idAntigo){
    iterador it;
    int auxId=0;
    tempo t;
    int min;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if((strcmp(tipoProva,daTipoProva(t))==0)&&(daId(daAtletaTempo(t)) > idAntigo)) {
                if(auxId==0){
                    auxId=daId(daAtletaTempo(t));
                }
                else{
                    if (auxId > daId(daAtletaTempo(t))){
                        auxId = daId(daAtletaTempo(t));
                    }
                }
            }
    }
    destroiIterador(it);
    if(auxId == 0){
        return -1;
    }
    min = daMelhorTempoMinutoAtletaProva(daMelhorTempoAtletaProva(g,auxId,tipoProva));
    return min;
}

int daSegundoTemposAtletaOrdemID2(gestor g,char * tipoProva,int idAntigo){
    iterador it;
    int auxId=0;
    tempo t;
    int seg;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if((strcmp(tipoProva,daTipoProva(t))==0)&&(daId(daAtletaTempo(t))>idAntigo)) {
                if(auxId==0){
                    auxId=daId(daAtletaTempo(t));
                }
                else{
                    if (auxId > daId(daAtletaTempo(t))){
                        auxId = daId(daAtletaTempo(t));
                    }
                }
            }
    }
    destroiIterador(it);
    if(auxId == 0){
        return -1;
    }
    seg = daMelhorTempoSegundoAtletaProva(daMelhorTempoAtletaProva(g,auxId,tipoProva));
    return seg;
}

int daMiliTemposAtletaOrdemID2(gestor g,char * tipoProva,int idAntigo){
    iterador it;
    int auxId=0;
    tempo t;
    int mili;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if((strcmp(tipoProva,daTipoProva(t))==0)&&(daId(daAtletaTempo(t)) > idAntigo)) {
                if(auxId==0){
                    auxId=daId(daAtletaTempo(t));
                }
                else{
                    if (auxId > daId(daAtletaTempo(t))){
                        auxId = daId(daAtletaTempo(t));
                    }
                }
            }
    }
    destroiIterador(it);
    if(auxId == 0){
        return -1;
    }
    mili = daMelhorTempoMiliAtletaProva(daMelhorTempoAtletaProva(g,auxId,tipoProva));
    return mili;
}

int daIdOrdenado(gestor g,char * tipoProva,int idAntigo){
    iterador it;
    int auxId=0;
    tempo t;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if((strcmp(tipoProva,daTipoProva(t))==0)&& (daId(daAtletaTempo(t)) < idAntigo)) {
                if(auxId==0){
                    auxId=daId(daAtletaTempo(t));
                }
                else{
                    if (auxId > daId(daAtletaTempo(t)))
                        auxId = daId(daAtletaTempo(t));
                }
            }
    }
    destroiIterador(it);
    return auxId;
}

int daIdOrdenado2(gestor g,char * tipoProva,int idAntigo){
    iterador it;
    int auxId=0;
    tempo t;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if((strcmp(tipoProva,daTipoProva(t))==0)&& (daId(daAtletaTempo(t)) > idAntigo)) {
                if(auxId==0){
                    auxId=daId(daAtletaTempo(t));
                }
                else{
                    if (auxId > daId(daAtletaTempo(t)))
                        auxId = daId(daAtletaTempo(t));
                }
            }
    }
    destroiIterador(it);
    return auxId;
}

tempo daTempoAlfabetico(gestor g,char* tipoProva,char * nomeAntigo){
    iterador it;
    char auxNome[SIZEN]={};
    tempo t,auxt;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if((strcmp(tipoProva,daTipoProva(t))==0)&&(strcmp((char*)daNome(daAtletaTempo(t)),nomeAntigo)< 0)) {
                if(strlen(auxNome)==0){
                    strcpy(auxNome,(char*)daNome(daAtletaTempo(t)));
                    auxt = t;
                }
                else{
                    if (strcmp(auxNome,(char*)daNome(daAtletaTempo(t))) > 0){
                        strcpy(auxNome,(char*)daNome(daAtletaTempo(t)));
                        auxt =  t;
                    }
                }
            }
    }
    destroiIterador(it);
    return (tempo)auxt;
}

tempo daTempoAlfabetico2(gestor g,char* tipoProva,char * nomeAntigo){
    iterador it;
    char auxNome[SIZEN]={};
    tempo t,auxt;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if((strcmp(tipoProva,daTipoProva(t))==0)&&(strcmp((char*)daNome(daAtletaTempo(t)),nomeAntigo)> 0)) {
                if(strlen(auxNome)==0){
                    strcpy(auxNome,(char*)daNome(daAtletaTempo(t)));
                    auxt = t;
                }
                else{
                    if (strcmp(auxNome,(char*)daNome(daAtletaTempo(t))) > 0){
                        strcpy(auxNome,(char*)daNome(daAtletaTempo(t)));
                        auxt =  t;
                    }
                }
            }
    }
    destroiIterador(it);
    return auxt;
}

int daMinutoTemposAtletaOrdemNome(gestor g,char* tipoProva,char * nomeAntigo){
    iterador it;
    char auxnome[SIZEN]= {};
    tempo t;
    int min;
    int auxId=0;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if((strcmp(tipoProva,daTipoProva(t))==0)&&(strcmp((char*)daNome(daAtletaTempo(t)),nomeAntigo)< 0)) {
                if(strlen(auxnome)==0){
                    strcpy(auxnome,(char*)daNome(daAtletaTempo(t)));
                    auxId=daId(daAtletaTempo(t));
                }
                else{
                    if (strcmp(auxnome,(char*)daNome(daAtletaTempo(t))) > 0){
                        strcpy(auxnome,(char*)daNome(daAtletaTempo(t)));
                        auxId=daId(daAtletaTempo(t));
                    }
                }
            }
    }
    destroiIterador(it);
    if(strlen(auxnome) == 0){
        return -1;
    }
    min =  daMelhorTempoMinutoAtletaProva(daMelhorTempoAtletaProva(g,auxId,tipoProva));

    return min;
}


int daSegundoTemposAtletaOrdemNome(gestor g,char* tipoProva,char * nomeAntigo){
        iterador it;
    char auxnome[SIZEN]= {};
    int i=0;
    tempo t;
    int seg;
    int auxId=0;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if((strcmp(tipoProva,daTipoProva(t))==0)&&(strcmp((char*)daNome(daAtletaTempo(t)),nomeAntigo)< 0)) {
                if(strlen(auxnome)==0){
                    strcpy(auxnome,(char*)daNome(daAtletaTempo(t)));
                    auxId=daId(daAtletaTempo(t));
                }
                else{
                    if (strcmp(auxnome,(char*)daNome(daAtletaTempo(t))) > 0){
                        strcpy(auxnome,(char*)daNome(daAtletaTempo(t)));
                        auxId=daId(daAtletaTempo(t));
                    }
                }
            }
        i++;
    }
    destroiIterador(it);
    if(strlen(auxnome) == 0){
        return -1;
    }
    seg =  daMelhorTempoSegundoAtletaProva(daMelhorTempoAtletaProva(g,auxId,tipoProva));
    return seg;
}

int daMiliTemposAtletaOrdemNome(gestor g,char* tipoProva,char * nomeAntigo){
    iterador it;
    char auxnome[SIZEN]= {};
    int i=0;
    tempo t;
    int mili;
    int auxId=0;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if((strcmp(tipoProva,daTipoProva(t))==0)&&(strcmp((char*)daNome(daAtletaTempo(t)),nomeAntigo)< 0)) {
                if(strlen(auxnome)==0){
                    strcpy(auxnome,(char*)daNome(daAtletaTempo(t)));
                    auxId=daId(daAtletaTempo(t));
                }
                else{
                    if (strcmp(auxnome,(char*)daNome(daAtletaTempo(t))) > 0){
                        strcpy(auxnome,(char*)daNome(daAtletaTempo(t)));
                        auxId=daId(daAtletaTempo(t));
                    }
                }
            }
        i++;
    }
    destroiIterador(it);
    if(strlen(auxnome) == 0){
        return -1;
    }
    mili =  daMelhorTempoMiliAtletaProva(daMelhorTempoAtletaProva(g,auxId,tipoProva));
    return mili;
}

int daMinutoTemposAtletaOrdemNome2(gestor g,char* tipoProva,char * nomeAntigo){
    iterador it;
    char auxnome[SIZEN]= {};
    tempo t;
    int min;
    int auxId=0;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if((strcmp(tipoProva,daTipoProva(t))==0)&&(strcmp((char*)daNome(daAtletaTempo(t)),nomeAntigo)> 0)) {
                if(strlen(auxnome)==0){
                    strcpy(auxnome,(char*)daNome(daAtletaTempo(t)));
                    auxId=daId(daAtletaTempo(t));
                }
                else{
                    if (strcmp(auxnome,(char*)daNome(daAtletaTempo(t))) > 0){
                        strcpy(auxnome,(char*)daNome(daAtletaTempo(t)));
                        auxId=daId(daAtletaTempo(t));
                    }
                }
            }
    }
    destroiIterador(it);
    if(strlen(auxnome) == 0){
        return -1;
    }
    min =  daMelhorTempoMinutoAtletaProva(daMelhorTempoAtletaProva(g,auxId,tipoProva));
    return min;
}

int daSegundoTemposAtletaOrdemNome2(gestor g,char* tipoProva,char * nomeAntigo){
    iterador it;
    char auxnome[SIZEN]= {};
    tempo t;
    int seg;
    int auxId=0;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if((strcmp(tipoProva,daTipoProva(t))==0)&&(strcmp((char*)daNome(daAtletaTempo(t)),nomeAntigo)> 0)) {
                if(strlen(auxnome)==0){
                    strcpy(auxnome,(char*)daNome(daAtletaTempo(t)));
                    auxId=daId(daAtletaTempo(t));
                }
                else{
                    if (strcmp(auxnome,(char*)daNome(daAtletaTempo(t))) > 0){
                        strcpy(auxnome,(char*)daNome(daAtletaTempo(t)));
                        auxId=daId(daAtletaTempo(t));
                    }
                }
            }
    }
    destroiIterador(it);
    if(strlen(auxnome) == 0){
        return -1;
    }
    seg =  daMelhorTempoSegundoAtletaProva(daMelhorTempoAtletaProva(g,auxId,tipoProva));
    return seg;
}

int daMiliTemposAtletaOrdemNome2(gestor g,char* tipoProva,char * nomeAntigo){
    iterador it;
    char auxnome[SIZEN]= {};
    tempo t;
    int mili;
    int auxId=0;

    it = iteradorSequencia(g->tempos);
    while (temSeguinteIterador(it)){
            t=(tempo)seguinteIterador(it);
            if((strcmp(tipoProva,daTipoProva(t))==0)&&(strcmp((char*)daNome(daAtletaTempo(t)),nomeAntigo)> 0)) {
                if(strlen(auxnome)==0){
                    strcpy(auxnome,(char*)daNome(daAtletaTempo(t)));
                    auxId=daId(daAtletaTempo(t));
                }
                else{
                    if (strcmp(auxnome,(char*)daNome(daAtletaTempo(t))) > 0){
                        strcpy(auxnome,(char*)daNome(daAtletaTempo(t)));
                        auxId=daId(daAtletaTempo(t));
                    }
                }
            }
    }
    destroiIterador(it);
    if(strlen(auxnome) == 0){
        return -1;
    }
    mili =  daMelhorTempoMiliAtletaProva(daMelhorTempoAtletaProva(g,auxId,tipoProva));
    return mili;
}

int daTamanhoSequenciaTempos(gestor g){
    return tamanhoSequencia(g->tempos);
}

iterador iteradorAtletaGestor(gestor g){
    return iteradorDicionario(g->atleta);
}
iterador iteradorEquipaGestor(gestor g){
    return iteradorSequencia(g->equipa);
}

