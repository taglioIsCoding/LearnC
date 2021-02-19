/*

Candidato Michele Tagliani
Matricola 0000978601

Fondamenti di informatica T1

*/

#include"element.h"
#include"stdio.h"
#include"stdlib.h"
#include"list.h"



int readB(FILE *fp, Element *e){
    return fread(e, sizeof(Element), 1, fp);
}


int writeB(FILE *fp, Element e){
    return fwrite(&e, sizeof(Element), 1, fp);
}

boolean writeList(FILE *fp, list l){
    while (!empty(l))
    {
        writeList(fp, tail(l));
        fwrite(l, sizeof(Element), 1, fp);
        return true;
    }

    return false;
}

boolean readList(FILE *fp, list *l){
    Element e;
    while(fread(&e, sizeof(Element), 1, fp) == 1){
        *l = cons(e, *l);
    }
    return true;
}