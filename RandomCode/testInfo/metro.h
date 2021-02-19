#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"list.h"
#include"element.h"
#include"order.h"



// typedef struct
// {
//     char in[MAX];
//     char out[MAX]; 
//     float costo;
// } Tariffa;

typedef Element Evento;

int readField(char buffer[], char sep, FILE *f);

Evento leggiUno(FILE *fp);

list leggiTutti(char * fileName);

Tariffa * leggiTariffe(char * fileName, int * dim);

float ricerca(Tariffa *v, int dim, char * ingresso, char * uscita);

void totali(Tariffa * tariffe, int dim, list eventi);