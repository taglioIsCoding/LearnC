#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 3

typedef struct {
    unsigned int matr;
    unsigned int CDL;
} Dati;

typedef struct {
    unsigned int matr;
    char nome[21];
    char cognome[31];
    char via[31];
    char citta[31];
    unsigned int CAP;
} Indirizzo;

typedef struct {
      unsigned int matr;
      char nome[21];
      char cognome[31];
      char via[31];
      char citta[31];
      unsigned int CAP;
      unsigned int CDL;
} Elemento;

int main(void){
    FILE *fpD;
    FILE *fpA;
    Dati data[MAX];
    Indirizzo indirizzi[MAX];
    Elemento Elements[MAX];
    int i =0;
    int j =0;
    int d= 0;

    printf("I willread two file and make a joint\n");

    fpD= fopen("data.txt", "r");
    fpA= fopen("address.txt", "r");

    if(fpA==NULL || fpD == NULL){
        printf("ERROR\n");
        return 0;
    }

    while(fscanf(fpD, "%d %d", &data[i].matr, &data[i].CDL) !=EOF){
        i++;
    }

    i = 0 ;

    while(fscanf(fpA, "%d %s %s %s %s %d", &indirizzi[i].matr, indirizzi[i].nome, indirizzi[i].cognome, indirizzi[i].via, indirizzi[i].citta, &indirizzi[i].CAP) !=EOF){
        i++;
    }

    for(i = 0; i < MAX; i++){
        for(j =0; j<MAX; j++){
            if(data[i].matr == indirizzi[j].matr){
                Elemento e;
                e.matr = data[i].matr;
                strcpy(e.nome, indirizzi[j].nome);
                strcpy(e.cognome, indirizzi[j].cognome);
                strcpy(e.via, indirizzi[j].via);
                strcpy(e.citta, indirizzi[j].citta);
                e.CAP = indirizzi[j].CAP;
                e.CDL = data[i].CDL;
                Elements[d]= e;
                d++;
            }
        }
    }

    for(i = 0; i < MAX; i++){
        printf("ID: %d Student: %s lives in %s\n", Elements[i].matr ,Elements[i].nome, Elements[i].citta);
    }

    fclose(fpD);
    fclose(fpA);

}