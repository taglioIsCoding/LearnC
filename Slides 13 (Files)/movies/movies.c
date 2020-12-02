#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define DIM 100
#define MAX 5

typedef struct {
    char name[31];
    float price;
} Place;

typedef struct {
    char title[21];
    char place[31];
    int times[3];
} Program;

typedef struct {
    char title[21];
    float price;
} Film;

int load(FILE * p1, FILE * p2, Film films[]){
    Program toInsert;
    Place placeToInsert;
    int trovato;
    int ins = 0;

    while (fscanf(p1, "%s %s %d-%d-%d", toInsert.title , toInsert.place, &toInsert.times[0], &toInsert.times[1], &toInsert.times[2]) > 0)
    {
        trovato = 0;
        rewind(p2);
        while (fscanf(p2, "%s %f", placeToInsert.name, &placeToInsert.price) == 2 && !trovato){
            if (strcmp (placeToInsert.name, toInsert.place)==0)
            {
                trovato = 1;
                films[ins].price = placeToInsert.price;
                strcpy(films[ins].title, toInsert.title);
                ins++;
            }
        }
    }
    return ins;
}

int main(void){
    FILE *fpF;
    FILE *fpP;
    Film films[DIM];
    int dim;
    float avg = 0;
    int i;

    printf("I will read two file print economic cinema\n");

    fpF= fopen("films.txt", "r");
    fpP= fopen("places.txt", "r");

    if(fpF==NULL || fpP == NULL){
        printf("ERROR\n");
        return 0;
    }

    dim = load(fpF, fpP, films);

    for(i=0; i<dim; i++){
        avg = avg + films[i].price;
    }

    avg = avg/(float)dim;


    for(i=0; i<dim; i++){
        if(films[i].price < avg )
        printf("Title: %s, Price %f\n", films[i].title, films[i].price);
    }

    fclose(fpF);
    fclose(fpP);

}