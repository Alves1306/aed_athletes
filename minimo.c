#include <stdlib.h>
#include <string.h>

#include "minimo.h"

/* Constantes do TAD minimo */
#define SIZEP 50

/* Estrutura de dados do TAD minimo */
struct _minimo{
    int minMinimo;
    int segMinimo;
    int miliSegMinimo;
    char tipoProvaMinimo[SIZEP];
};

/* Implementações das funcões do TAD minimo */
minimo criaMinimo(char * tipo_Prova, int min_Minimo, int seg_Minimo, int mili_Minimo){
    minimo m;
    m= (minimo) malloc(sizeof(struct _minimo));
    if (m==NULL)
        return NULL;
    strcpy (m->tipoProvaMinimo,tipo_Prova);
    m->minMinimo = min_Minimo;
    m->segMinimo = seg_Minimo;
    m->miliSegMinimo = mili_Minimo;
    return m;
}

int daMinutoMinimo(minimo m){
    return m->minMinimo;
}

int daSegundoMinimo(minimo m){
    return m->segMinimo;
}

int daMiliMinimo(minimo m){
    return m->miliSegMinimo;
}


char * daTipoProvaMinimo(minimo m){
    return m->tipoProvaMinimo;
}

void actualizaMinutoMinimo(minimo m, int minuto){
    m->minMinimo = minuto;
}
void actualizaSegundoMinimo(minimo m, int segundo){
    m->segMinimo = segundo;
}
void actualizaMiliMinimo(minimo m, int miliSegundo){
    m->miliSegMinimo = miliSegundo;
}

float calculaTempoMinimo(minimo m){
    float soma = ((m->minMinimo* 60 )+ (m->segMinimo) + (m->miliSegMinimo * 0.01));
    return soma;
}

void destroiMinimo(minimo m){
    free(m);
}

void destroiGenMinimo(void *m){
    destroiMinimo((minimo) m);
}
