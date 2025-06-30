 /*
 * mainApuramento.c
 *
 *  Created on:  18/05/2021
 *  Last Change: 02/06/2021
 *
 *      Authors: Antonio Alves
 *               Joao Jorge
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "iterador.h"
#include "dicionario.h"
#include "atleta.h"
#include "equipa.h"
#include "minimo.h"
#include "tempo.h"
#include "gestor.h"


#define LINHA 150
#define COMANDO 100
#define SIZEN 50
#define MAXATLETAS 999
#define IDEQUIPA 20
#define SIZEP 50
#define SIZEF 30

/**********************  Protótipos **************************/
void interpretador(gestor g);
void funcAtleta(gestor g,char * linha);
void funcEquipa(gestor g,char * linha);
void funcEvento(gestor g,char * linha);
void funcMelhor(gestor g,char * linha);
void funcTempos(gestor g,char * linha);
void funcMinimo(gestor g,char * linha);
void funcMinimos(gestor g,char * linha);
void funcApurados(gestor g, char * linha);
void funcProva(gestor g, char * linha);
int provaValida(char * tipoProva);
void funcFaixa(gestor g, char * linha);
void funcElimina(gestor g, char * linha);

/************************************************************/


void funcAtleta(gestor g,char * linha){
    char sexo;
    char cmd[COMANDO];
    char nome[SIZEN];
    int dia;
    int mes;
    int ano;
    int id;
    if (sscanf(linha, "%s %d %c",cmd,&id, &sexo) != 3){
        printf("Comando errado\n");
        return;
    }
    if ((sexo != 'M') && (sexo !='F')){
             printf("Comando errado\n");
        return;
    }

    fgets(linha,LINHA,stdin);
    sscanf(linha,"%[^\n]", nome);
    fgets(linha,LINHA,stdin);
    sscanf(linha,"%d/%d/%d", &dia, &mes, &ano);
    if (existeAtletaGestor(g,id) == 1){
        printf("Atleta ja existente\n");
        return;
    }
    /*strcpy(faixaEtaria,(char *) atribuiFaixaEtaria(ano));
    printf("%s",faixaEtaria);*/
    if(novoAtletaGestor(g,id,sexo,nome,dia,mes,ano)==1){
            printf("Atleta registado\n");
    }
}

void funcEquipa(gestor g,char * linha){
    char idEquipa[IDEQUIPA];
    char cmd[COMANDO];
    int idAtleta1;
    int idAtleta2;
    if (sscanf(linha, "%s %s %d %d",cmd,idEquipa,&idAtleta1,&idAtleta2)!= 4){
        printf("Comando errado\n");
        return;
    }
    if ((int)existeEquipaGestor(g,idEquipa) == 1){
        printf("Equipa ja existente\n");
        return;
    }
    if ((int)existeAtletaGestor(g,idAtleta1) == 0){
        printf("Atleta nao registado\n");
        return;
    }
    if ((int)existeAtletaGestor(g,idAtleta2) == 0){
        printf("Atleta nao registado\n");
        return;
    }
    if((int)comparaSexo(g,idAtleta1,idAtleta2) == 0){
        printf("Equipa invalida\n");
        return;
    }
    if((int)registaEquipa(g,idEquipa,idAtleta1,idAtleta2)== 1){
        printf("Equipa registada\n");
        return;
    }
}

void funcEvento(gestor g,char * linha){
    char cmd[LINHA];
    atleta a;
    equipa e;
    int i=0,j=0;
    int erroAtleta = 0;
    int erroEquipa = 0;
    int idAtleta;
    int nProvas;
    char nomeEvento[SIZEN];
    char tipoProva[SIZEP];
    int nParticipantes;
    int min;
    int seg;
    int miliSeg;
    char idEq[IDEQUIPA];

    if (sscanf(linha, "%s %[^\n]",cmd,nomeEvento)!= 2){
        printf("Comando errado\n");
        return;
    }
    fgets(linha,LINHA,stdin);
    sscanf(linha,"%d",&nProvas);
    while(j<nProvas){
        fgets(linha,LINHA,stdin);
        sscanf(linha, "%[^\n]",tipoProva);
        fgets(linha,LINHA,stdin);
        sscanf(linha,"%d",&nParticipantes);
        for(i=0;i<nParticipantes;i++){
            if (tipoProva[1] == '1'){
                fgets(linha,LINHA,stdin);
                sscanf(linha,"%d",&idAtleta);
                fgets(linha,LINHA,stdin);
                sscanf(linha,"%d:%d.%d",&min,&seg,&miliSeg);
                a= daAtleta(g,idAtleta);
                if (existeAtletaGestor(g,idAtleta) == 0){
                    erroAtleta++;
                }
                else{
                    registaTempo(g,a,min,seg,miliSeg,tipoProva,nomeEvento);
                }
            }
            if (tipoProva[1] == '2'){
                fgets(linha,LINHA,stdin);
                sscanf(linha,"%[^\n]",idEq);
                fgets(linha,LINHA,stdin);
                sscanf(linha,"%d:%d.%d",&min,&seg,&miliSeg);
                if (existeEquipaGestor(g,idEq)==0){
                    erroEquipa++;
                }
                else{
                    e = (equipa)daEquipa(g,idEq);
                    a = (atleta)daPrimeiroAtleta(e);
                    registaTempo(g,a,min,seg,miliSeg,tipoProva,nomeEvento);
                    a = (atleta)daSegundoAtleta(e);
                    registaTempo(g,a,min,seg,miliSeg,tipoProva,nomeEvento);
                }
            }
        }
        j++;
    }
        if((erroAtleta > 0)||(erroEquipa > 0)){
            printf("Evento registado com erros\n");
            if (erroAtleta > 0)
                printf("Atletas nao registados: %d\n",erroAtleta);
            if (erroEquipa > 0)
                printf("Equipas nao registadas: %d\n",erroEquipa);
        }
        else {
            printf("Evento registado\n");
        }
}

void funcMelhor(gestor g,char * linha){
    char cmd[LINHA];
    char dados[LINHA];
    int idAtleta;
    int erroAtleta =0;
    char tipoProva[SIZEP];

    if (sscanf(linha, "%s %d",cmd, &idAtleta)!= 2){
        printf("Comando errado\n");
        return;
    }
    if (existeAtletaGestor(g, idAtleta) == 0){
        erroAtleta = 1;
    }
    fgets(dados,LINHA,stdin);
    sscanf(dados,"%[^\n]",  tipoProva);
    if(erroAtleta == 1){
        printf("Atleta nao registado\n");
        return;
    }
    if(provaValida(tipoProva) == 0){
        printf("Prova invalida\n");
        return;
    }
    if(existeAtletaTempoProva(g, idAtleta, tipoProva) == 0){
        printf("Atleta sem tempo na prova\n");
        return;
    }
    else{
        printf("Melhor tempo: %d:%02d.%02d %s\n",daMelhorTempoMinutoAtletaProva(daMelhorTempoAtletaProva(g, idAtleta, tipoProva)),daMelhorTempoSegundoAtletaProva(daMelhorTempoAtletaProva(g, idAtleta, tipoProva)), daMelhorTempoMiliAtletaProva(daMelhorTempoAtletaProva(g, idAtleta, tipoProva)),daNomeEventoGestor(g, idAtleta, tipoProva));
    }
}

void funcTempos(gestor g,char * linha){
    int idAtleta;
    char cmd[LINHA];
    char tipoProva[SIZEP];
    int min;
    int seg;
    int p=0;
    int miliSeg;

    if (sscanf(linha, "%s %d",cmd,&idAtleta)!= 2){
        printf("Comando errado\n");
        return;
    }
    fgets(linha,LINHA,stdin);
    if(sscanf(linha,"%[^\n]",tipoProva) != 1){
        printf("Comando errado\n");
        return;
    }
    if(existeAtletaGestor(g,idAtleta)==0){
        printf("Atleta nao registado\n");
        return;
    }
    if (provaValida(tipoProva)==0){
        printf("Prova invalida\n");
        return;
    }
    if (daMelhorTempoAtletaProva(g,idAtleta,tipoProva) == 0){
            printf("Atleta sem tempo na prova\n");
            return;
    }
    if (existeAtletaTempoProva(g,idAtleta,tipoProva) == 0){
        printf("Atleta sem tempo na prova\n");
        return;
    }
    else{
        for(p=0;p<daTamanhoSequenciaTempos(g);p++){
            min = daMinutoTemposAtleta(g,idAtleta,tipoProva,p);
            seg = daSegundoTemposAtleta(g,idAtleta,tipoProva,p);
            miliSeg = daMiliTemposAtleta(g,idAtleta,tipoProva,p);
            if (min != -1){
                printf("%d:%02d.%02d\n",min,seg,miliSeg);
            }
        }
    }
}

void funcMinimo(gestor g,char * linha){
    char cmd[LINHA];
    char dados[LINHA];
    char tipoProva[SIZEP];
    int min;
    int seg;
    int miliSeg;

    if (sscanf(linha, "%s %[^\n]",cmd, tipoProva)!= 2){
        printf("Comando errado\n");
        return;
    }
    else{
        fgets(dados,LINHA,stdin);
        sscanf(dados,"%d:%d.%d",  &min, &seg, &miliSeg);
        if(provaValida(tipoProva) == 0){
            printf("Prova invalida\n");
            return;
        }
        if(existeMinimoGestor(g,tipoProva)==1){
            actualizaMinimoGestor(g,tipoProva,min,seg,miliSeg);
            printf("Tempo de referencia atualizado\n");
            return;
        }
        if(novoMinimoGestor(g, tipoProva, min, seg, miliSeg)==1){
            printf("Tempo de referencia atribuido\n");
            return;
        }
    }
}

void funcMinimos(gestor g, char * linha){
    char cmd[LINHA];
    if (sscanf(linha, "%s",cmd)!= 1){
        printf("Comando errado\n");
        return;
    }
    minimo m;
    iterador it;
    if(tamanhoMinimoGestor(g) != 0){
        it = iteradorMinimoGestor(g);
        while(temSeguinteIterador(it)){
            m=((minimo)seguinteIterador(it));
            printf("%s %d:%02d.%02d\n", daTipoProvaMinimo(m), daMinutoMinimo(m), daSegundoMinimo(m),daMiliMinimo(m));
        }
        destroiIterador(it);
    }
}

void funcApurados(gestor g, char * linha){
    char cmd[LINHA];
    char nomeAnterior[SIZEN];
    char tipoProva[SIZEP];
    int min,seg,mili;
    int p=0,n;
    atleta a;

    for(n=0;n<50;n++){
        nomeAnterior[n]='~';
    }

    if (sscanf(linha, "%s %[^\n]",cmd, tipoProva)!= 2){
        printf("Comando errado\n");
        return;
    }
    if(provaValida(tipoProva) == 0){
        printf("Prova invalida\n");
        return;
    }
    if(naoTemMinimoProva(g, tipoProva) == 0){
        printf("Prova sem tempo minimo\n");
        return;
    }
    if(provaVazia(g, tipoProva) == 0){
        printf("Sem atletas\n");
        return;
    }
    else{
        min = daMinutoTemposAtletaOrdemNome(g,tipoProva,nomeAnterior);
        seg = daSegundoTemposAtletaOrdemNome(g,tipoProva,nomeAnterior);
        mili = daMiliTemposAtletaOrdemNome(g,tipoProva,nomeAnterior);
        a = daAtletaTempo(daTempoAlfabetico(g,tipoProva,nomeAnterior));
        strcpy(nomeAnterior,daNome(a));

        if((min !=-1) && (daTempoTotalMinimo(g,tipoProva) > daMelhorTempoAtletaProva(g,daId(a),tipoProva))){
            printf("%s %d:%02d.%02d\n",daNome(a),min,seg,mili);
        }
        else if (daTempoTotalMinimo(g,tipoProva) < daMelhorTempoAtletaProva(g,daId(a),tipoProva)){
            printf("Sem atletas\n");
            return;
        }
        for(p=1;p<daTamanhoSequenciaTempos(g);p++){
            min = daMinutoTemposAtletaOrdemNome2(g,tipoProva,nomeAnterior);
            seg = daSegundoTemposAtletaOrdemNome2(g,tipoProva,nomeAnterior);
            mili = daMiliTemposAtletaOrdemNome2(g,tipoProva,nomeAnterior);
            a = daAtletaTempo(daTempoAlfabetico2(g,tipoProva,nomeAnterior));
            strcpy(nomeAnterior,daNome(a));
            if((min !=-1) && (daTempoTotalMinimo(g,tipoProva)) > (daMelhorTempoAtletaProva(g,daId(a),tipoProva))){
                printf("%s %d:%02d.%02d\n",daNome(a),min,seg,mili);
            }
        }
    }
}

void funcProva(gestor g, char * linha){
    char cmd[LINHA];
    char tipoProva[SIZEP];
    int min,seg,mili;
    int p;
    int id,idAntigo=999;
    atleta a;

    if (sscanf(linha, "%s %[^\n]",cmd, tipoProva)!= 2){
        printf("Comando errado\n");
        return;
    }
    if(provaValida(tipoProva) == 0){
        printf("Prova invalida\n");
        return;
    }
    if(provaVazia(g, tipoProva) == 0){
        printf("Sem atletas\n");
        return;
    }
    else {
            min = daMinutoTemposAtletaOrdemID(g,tipoProva,idAntigo);
            seg = daSegundoTemposAtletaOrdemID(g,tipoProva,idAntigo);
            mili = daMiliTemposAtletaOrdemID(g,tipoProva,idAntigo);
            id = daIdOrdenado(g,tipoProva,idAntigo);
            a = daAtleta(g,id);
            idAntigo = id;
            if(min!=-1){
                printf("%d %s %d:%02d.%02d\n",id,daNome(a),min,seg,mili);
            }
            for(p=1;p<daTamanhoSequenciaTempos(g);p++){
                min = daMinutoTemposAtletaOrdemID2(g,tipoProva,idAntigo);
                seg = daSegundoTemposAtletaOrdemID2(g,tipoProva,idAntigo);
                mili = daMiliTemposAtletaOrdemID2(g,tipoProva,idAntigo);
                if(min!=-1){
                    id = daIdOrdenado2(g,tipoProva,idAntigo);
                    a = daAtleta(g,id);
                    idAntigo = id;
                    printf("%d %s %d:%02d.%02d\n",id,daNome(a),min,seg,mili);
                }
            }
    }
}

void funcFaixa(gestor g, char *linha){
    char cmd[LINHA];
    int idAntigo = 0;
    int idAtleta;
    char sexo;
    char faixaEtaria[SIZEF];
    atleta a;
    if (sscanf(linha,"%s %s %c",cmd, faixaEtaria, &sexo)!= 3){
        printf("Comando errado\n");
        return;
    }
    if ((strcmp(faixaEtaria,"junior")!=0) && (strcmp(faixaEtaria,"senior")!=0 )&& (strcmp(faixaEtaria,"veterano")!=0)){
        printf("Comando errado\n");
        return;
    }
    if(encontraIDMenorAtleta2(g,idAntigo,sexo,faixaEtaria)== 0){
        printf("Sem atletas\n");
        return;
    }
    else {
        while(encontraIDMenorAtleta2(g,idAntigo,sexo,faixaEtaria)!=0){
            idAtleta = encontraIDMenorAtleta2(g,idAntigo,sexo,faixaEtaria);
            a = daAtleta(g,idAtleta);
            printf("%d %s %02d/%02d/%04d\n",daId(a),daNome(a),daDia(a),daMes(a),daAno(a));
            idAntigo = idAtleta;
        }
    }
}

void funcElimina(gestor g, char *linha){
    char cmd[LINHA];
    char nome[SIZEN];
    int idAtleta;
    atleta a;

    if (sscanf(linha, "%s %d",cmd, &idAtleta)!= 2){
        printf("Comando errado\n");
        return;
    }
    if(existeAtletaGestor(g,idAtleta)==0){
        printf("Atleta nao registado\n");
        return;
    }
    else{
        a = daAtleta(g,idAtleta);
        strcpy(nome,daNome(a));
        if (eliminaAtletaGestor(g, idAtleta)== 1)
            printf("Atleta %s eliminado\n", nome);
    }
}

void interpretador(gestor g){
    char linha[LINHA];
    char cmd[COMANDO];
    while (1){
        printf("> ");
        fgets(linha,LINHA,stdin);
        sscanf(linha,"%s", cmd);
        if((strcasecmp("ATLETA",cmd)==0)){
            funcAtleta(g,linha);
        }
        else if((strcasecmp("EQUIPA",cmd)==0)){
            funcEquipa(g,linha);
        }
        else if((strcasecmp("EVENTO",cmd)==0)){
            funcEvento(g,linha);
        }
        else if((strcasecmp("MELHOR",cmd)==0)){
            funcMelhor(g,linha);
        }
        else if((strcasecmp("TEMPOS",cmd)==0)){
            funcTempos(g,linha);
        }
        else if((strcasecmp("MINIMO",cmd)==0)){
            funcMinimo(g,linha);
        }
        else if((strcasecmp("MINIMOS",cmd)==0)){
            funcMinimos(g,linha);
        }
        else if((strcasecmp("APURADOS",cmd)==0)){
            funcApurados(g,linha);
        }
        else if((strcasecmp("PROVA",cmd)==0)){
            funcProva(g,linha);
        }
        else if((strcasecmp(cmd,"FAIXA")==0)){
            funcFaixa(g,linha);
        }
        else if((strcasecmp(cmd,"ELIMINA")==0)){
            funcElimina(g,linha);
        }
        else if((strcasecmp(cmd,"SAIR")== 0)){
            printf("Programa terminou\n");
            return;
        }


        else{
            printf("Comando errado\n");
        }
    }
}

int provaValida(char * tipoProva) {
    int existe=0;
    if(strcmp(tipoProva,"C1 500 M")==0){
        existe = 1;
        return existe;
    }
    else if(strcmp(tipoProva,"C1 1000 M")==0){
        existe = 1;
        return existe;
    }
    else if(strcmp(tipoProva,"C1 500 F")==0){
        existe = 1;
        return existe;
    }
    else if(strcmp(tipoProva,"C1 1000 F")==0){
        existe = 1;
        return existe;
    }
    else if(strcmp(tipoProva,"C2 500 M")==0){
        existe = 1;
        return existe;
    }
    else if(strcmp(tipoProva,"C2 1000 M")==0){
        existe = 1;
        return existe;
    }
    else if(strcmp(tipoProva,"C2 500 F")==0){
        existe = 1;
        return existe;
    }
    else if(strcmp(tipoProva,"C2 1000 F")==0){
        existe = 1;
        return existe;
    }
    else if(strcmp(tipoProva,"K1 500 M")==0){
        existe = 1;
        return existe;
    }
    else if(strcmp(tipoProva,"K1 1000 M")==0){
        existe = 1;
        return existe;
    }
    else if(strcmp(tipoProva,"K1 500 F")==0){
        existe = 1;
        return existe;
    }
    else if(strcmp(tipoProva,"K1 1000 F")==0){
        existe = 1;
        return existe;
    }
    else if(strcmp(tipoProva,"K2 500 M")==0){
        existe = 1;
        return existe;
    }
    else if(strcmp(tipoProva,"K2 1000 M")==0){
        existe = 1;
        return existe;
    }
    else if(strcmp(tipoProva,"K2 500 F")==0){
        existe = 1;
        return existe;
    }
    else if(strcmp(tipoProva,"K2 1000 F")==0){
        existe = 1;
        return existe;
    }
    else{
        return existe;
    }
}


int main(void)
{
    gestor g = criaGestor();
    interpretador(g);
    destroiGestor(g);
    return 0;
}


