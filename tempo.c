#include <string.h>
#include <stdlib.h>

#include "atleta.h"
#include "equipa.h"
#include "tempo.h"

#define SIZEP 50
#define SIZEN 50

struct _tempo{
    char tipoProva[SIZEP];
    int min;
    int seg;
    int miliseg;
    atleta a;
    char nome_evento[SIZEN];
};

tempo criaTempo(atleta a,int minuto, int segundo, int milisegundo, char * tipoProva,char * nome_evento){
    tempo t;
    t= (tempo)malloc (sizeof(struct _tempo));
    if (t==NULL)
        return NULL;
    t->a = a;
    strcpy(t->tipoProva,tipoProva);
    t->min = minuto;
    t->seg = segundo;
    t->miliseg = milisegundo;
    strcpy(t->nome_evento,nome_evento);
    return t;
}

atleta daAtletaTempo(tempo t){
    return t->a;
}

char * daTipoProva(tempo t){
    return t->tipoProva;
}

int daTempoMinuto(tempo t){
    return t->min;
}
int daTempoSeg(tempo t){
    return t->seg;
}
int daTempoMili(tempo t){
    return t->miliseg;
}

char* daNomeEvento(tempo t){
    return t->nome_evento;
}

float calculaTempo(tempo t){
    float soma = ((t->min * 60 )+ (t->seg) + (t->miliseg * 0.01));
    return soma;
}

void destroiTempo(tempo t){
    free(t);
}

void destroiGenTempo(void *t){
    destroiTempo((tempo) t);
}
