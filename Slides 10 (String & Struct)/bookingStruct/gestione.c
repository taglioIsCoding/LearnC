#include<stdio.h>
#include<string.h>
#include"gestione.h"

int read(Booking * dest){

    printf("Insert a new booking or FINE to end or STAMPA to print\n");
    printf("Name\n");
    scanf("%s", dest->name);
    if(strcmp(dest->name, "FINE") == 0){
        return 0;
    }else if(strcmp(dest->name, "STAMPA") == 0){
        return -1;
    }else{
        printf("Insert a place number\n");
        scanf("%d", &(dest->place));
        return 1;
    }
}

int assegna( Booking list[],int dim, int * lengthList, char * name, int pref){
    int i = 0;
    int k = 1;
    for(i = 0; i < *lengthList; i++){
        if(list[i].place == pref){
            k = -1;
        }
    }

    if(k<0 || *lengthList+1 > dim){
        return 0;
    }else{
        strcpy(list[*lengthList].name, name); 
        list[*lengthList].place = pref;
        (*lengthList)++;
        return 1;
    }
}