
#include"metro.h"

#define MAX 255

// Michele Tagliani
/*gcc main.c list.c element.c metro.c -o main;*/



int main(void){
    FILE *fp;
    Evento even;
    list tuttiEventi;
    Tariffa *tutteTariffe, tempOrder[MAX]; /*Temp order for merge sort*/
    int dimArrTar = 0, i;
    char fileName[30] = "eventi\0";
    fp = fopen("eventi.txt", "r+");
    if(fp==NULL){
        printf("ERROR\n");
        return false;
    }

    printf("--------LEGGI UNO------------\n");
    even = leggiUno(fp);
    printf("%d %s %s\n", even.id, even.in, even.out);

    printf("--------LEGGI TUTTI------------\n");
    tuttiEventi = leggiTutti(fileName);
    showList(tuttiEventi);

    printf("--------LEGGI TARIFFE------------\n");
    tutteTariffe = leggiTariffe("tariffe.txt", &dimArrTar);
    for(i = 0; i < dimArrTar + 1; i++){
        printf("Partenza %s, Arrivo %s, Costo %f\n", tutteTariffe[i].in, tutteTariffe[i].out, tutteTariffe[i].costo);
    }

    printf("--------ORDINO------------\n");
    quickSort(tutteTariffe, 0, dimArrTar);
    for(i = 0; i < dimArrTar + 1 ; i++){
        printf("Partenza %s, Arrivo %s, Costo %f\n", tutteTariffe[i].in, tutteTariffe[i].out, tutteTariffe[i].costo);
    }

    printf("--------RICERCA------------\n");
    printf("Costo %f \n",ricerca(tutteTariffe, dimArrTar, "Bufalora\0", "Bs2\0"));

    printf("--------TOTALI------------\n");
    totali(tutteTariffe, dimArrTar, tuttiEventi);

    list temp;
    while (!empty(tuttiEventi)){
       temp = tuttiEventi;
       tuttiEventi = tail(tuttiEventi);
       free(temp); 
    }
    

    free(tutteTariffe);
    fclose(fp); 
}