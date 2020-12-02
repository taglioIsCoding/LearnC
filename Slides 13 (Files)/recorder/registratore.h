#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct{
    int items;
    float price;
}Scontrino;

int read(FILE *fp, Scontrino *dest);

int write(FILE *fp, Scontrino src);