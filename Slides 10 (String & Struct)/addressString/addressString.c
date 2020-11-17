#include<string.h>
#include<stdio.h>
#include"address.h"

#define dim 108
/*Not working at all*/
int main(void){
    char cognome[dim];
    char nome[dim];
    char indirizzo[dim];
    int lenght;

    printf("Give surname, name and the lenght on the envelop, we will se if it fit\n");
    printf("Surname\n");
    scanf("%s", cognome);
    printf("Name\n");
    scanf("%s", nome);
    printf("Length\n");
    scanf("%d", &lenght);

    int code = address(cognome, nome, indirizzo, lenght);
    if(code < 0){
        printf("Error!\n");
    }else{
        printf("String on the envelop %s", indirizzo);
    }

}

/*gcc address.c addressString.c -o myapp*/