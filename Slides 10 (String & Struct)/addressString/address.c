#include<stdlib.h>
#include<string.h>

int address(char cognome[], char nome[], char indirizzo[], int dim){
    strcpy(indirizzo, "");
    if(strlen(cognome) > dim){
        return -1;
    }
    if(strlen(cognome)+strlen(nome) < dim){
        strcat(indirizzo, cognome);
        strcat(indirizzo, " ");
        strcat(indirizzo, nome);
        return 0;
    }else if(strlen(cognome) + 3 < dim ){
        strcpy(indirizzo, cognome);
        strcat(indirizzo, " ");
        indirizzo[strlen(indirizzo)] = nome[0];
        strcat(indirizzo, ".");
        strcat(indirizzo, "\0");
        return 0;
    }else{
        return -1;
    }
}