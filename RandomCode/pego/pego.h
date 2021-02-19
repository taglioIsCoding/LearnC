#include"element.h"
#include"list.h"
#include"order.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef Element Set;
typedef struct
{
    int idC;
    int idParts[9];
    int dimParts;
} Complex;

Set leggiUnSet(FILE *fp);
list leggiTutti(char * fileName);

Complex leggiUnComplex(FILE * fp);
Complex trovaComplex(char * fileName, int target);

int disp(list elenco, int target, char * fileName);