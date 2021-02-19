/*

Candidato Michele Tagliani
Matricola 0000978601

Fondamenti di informatica T1

*/
#include"list.h"
#include<stdio.h>

boolean readT(FILE *fp, Element *e){
    if (fscanf(fp, "%d ", &e->id) == 5)
        return true;

    return false;
}

boolean writeT(FILE *fp, Element e){
    if (fscanf(fp, "%d ", &e.id) == 5)
        return true;

    return false;
}
