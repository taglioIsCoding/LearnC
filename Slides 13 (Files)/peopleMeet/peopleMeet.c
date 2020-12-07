#include"peopleDo.h"
#define MAX 20
/*gcc peopleMeet.c peopleDo.c -o peopleMeet;*/
int main(void){
    Person list[MAX];
    FILE *fp;
    int dim;
    int i;

    /*Legge solo ma funziona*/
    printf("I will read from txt file than print to binary\n");

    fp = fopen("people.txt", "r");

    if(fp == NULL){
        printf("ERROR\n");
        return 0;
    }

    dim = readText(fp, list);
    fclose(fp);
    printf("ciao %d\n", dim);



    for(i=0; i<dim; i++){
        printf("Name: %s, Surname %s\n", list[i].name, list[i].surname);
    }

}