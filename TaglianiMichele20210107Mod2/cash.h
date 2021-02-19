/*

Candidato Michele Tagliani
Matricola 0000978601

Fondamenti di informatica T1

*/


#include"element.h"
#include"order.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"

typedef Element Negozio;

// typedef struct
//       {
//         int id;
//         float importo;
//         char nomeNegozio[1024];
//       } Operazione;


//Operazione e' definita all'interno di order.h per un bug con la libreria
//Negozio e' definita all'inetrno di elementdef.h
Operazione * leggiTutteOperazioni(char * fileName, int * dim);
list leggiNegozi(char * fileName);
void stampaOperazioni(Operazione * v, int dim);

void ordina(Operazione * v, int dim);
int negozioFisico(char * nomeNegozio, list negozi);
Operazione * filtra(Operazione * v, int dim, list negozi, int * dimLog);

float spesaCliente(int idCliente, Operazione * v, int dim);