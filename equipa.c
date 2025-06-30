#include <stdlib.h>
#include <string.h>

#include "atleta.h"
#include "equipa.h"

#define IDEQUIPA 20

struct _equipa{
    char idEquipa[IDEQUIPA];
    atleta a1,a2;
};

equipa criaEquipa(char* id_Equipa,atleta atleta1,atleta atleta2){
    equipa e;
    e = (equipa)malloc(sizeof(struct _equipa));
    if (e == NULL)
        return NULL;
    strcpy ((e->idEquipa),id_Equipa);
    e->a1 =  atleta1;
    e->a2 =  atleta2;
    return e;
}


void destroiEquipa(equipa e){
    free(e);
}

int existeEquipa(equipa e1, equipa e2){
    int igual = 0;
    if (e1->idEquipa == e2->idEquipa)
        igual = 1;
    return igual;
}

char * daIdEquipa(equipa e){
    return e->idEquipa;
}

atleta daPrimeiroAtleta(equipa e){
    return e->a1;
}

atleta daSegundoAtleta(equipa e){
    return e->a2;
}

void destroiGenEquipa(void *e){
    destroiEquipa((equipa) e);
}
