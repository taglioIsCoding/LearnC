/*

Candidato Michele Tagliani
Matricola 0000978601

Fondamenti di informatica T1

*/
#include<stdio.h>
#include<string.h>
#define MAX 255

typedef struct
      {
        int id;
        float importo;
        char nomeNegozio[1024];
      } Operazione;

typedef Operazione toOrder;

void incSwap();
void incComp();
void resetCounters();
void printCounters();


void swapOrder(toOrder * a, toOrder * b);
void assignT(toOrder *lvalue, toOrder rvalue);
int compareT(toOrder a, toOrder b);
void bubbleSort(toOrder v[], int n);
void insOrd(toOrder v[], int pos);
void insertSort(toOrder v[], int n);
void merge(toOrder v[], int i1, int i2, int fine, toOrder vout[]);
void mergeSort(toOrder v[], int iniz, int fine, toOrder vout[]);
void quickSort(toOrder a[],int  iniz,int fine);