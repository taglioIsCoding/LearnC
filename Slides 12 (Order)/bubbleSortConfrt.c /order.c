#include <stdio.h> 
#include "order.h"

int swap_count = 0;
int comp_count = 0;

void incSwap() { swap_count++; }

void incComp() { comp_count++; }


void resetCounters(){
    swap_count = 0;
    comp_count = 0; 
}
        
void printCounters(){
    printf("Numero di confronti effettuati: %d\n", comp_count);
    printf("Numero di scambi effettuati: %d\n", swap_count);
}

int trovaPosMax(int v[], int n) {
   int i, posMax=0;
   for (i=1; i<n; i++) {
        incComp();
       if (v[posMax]<v[i]) {
               posMax=i;
       }
   }
   return posMax;
}

void scambia(int * a, int * b) {
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
   incSwap();
}

void naiveSort(int v[], int n) {
    int p;
    while (n>1) {
        p = trovaPosMax(v,n);
            if ( p < n-1 )
                scambia( &v[p], &v[n-1]);
        n--;
    }
}

void bubbleSort(int v[], int n)
{
    int i;
    int ordinato = 0;
    while (n > 1 && ordinato == 0)
    {
        ordinato = 1;
        for (i = 0; i < n - 1; i++)
        {
            incComp();
            if (v[i] > v[i + 1])
            {
                scambia(&v[i], &v[i + 1]);
                ordinato = 0;
            }
        }
        n--;
    }
}
