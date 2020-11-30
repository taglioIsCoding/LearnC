#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXDIM 4

typedef struct snowStation
{
    char name[20];
    int snowLevel;
} Station;

int read(Station s[], int max, int *num){
    int i = 0;
    int m = 1;
    do{
        Station itemToInser;
        printf("Intert a product Name or FINE to end\n");
        scanf("%s", itemToInser.name);
        scanf("%*c");
        if(strcmp(itemToInser.name, "FINE") != 0){
            do{
                printf("Intert a snow level\n");
                scanf("%d", &itemToInser.snowLevel);
                scanf("%*c");
                s[i] = itemToInser;
                i++;
            }while(itemToInser.snowLevel < 0);    
        }else{
            m = -1;
        }
    }while(i <= max - 1 && m > 0);

    *num = i;
    return 0;
}

int compare(Station s1, Station s2){
    if(s1.snowLevel > s2.snowLevel){
        return 1;
    }else if(s1.snowLevel < s2.snowLevel){
        return -1;
    }else {
        return 0;
    }
}

void merge(Station v[], int i1, int i2, int fine, Station vout[])
{
    int i = i1, j = i2, k = i1;
    while (i <= i2 - 1 && j <= fine){
        if (compare(v[i], v[j]) < 0 ){
            vout[k] = v[i];
            i++;
        }else{
            vout[k] = v[j];
            j++;
        }
        k++;
    }

    while (i <= i2 - 1){
        vout[k] = v[i];
        i++;
        k++;
    }
    while (j <= fine){
        vout[k] = v[j];
        j++;
        k++;
    }
    for (i = i1; i <= fine; i++)
        v[i] = vout[i];
}

void mergeSort(Station v[], int iniz, int fine, Station vout[])
{
    int mid;
    if (iniz < fine)
    {
        mid = (fine + iniz) / 2;
        mergeSort(v, iniz, mid, vout);
        mergeSort(v, mid + 1, fine, vout);
        merge(v, iniz, mid + 1, fine, vout);
    }
}

int main(void){
    int c=0;
    Station stations[MAXDIM];
    Station ordered[MAXDIM];
    printf("Give me some stations and snow level i will order it\n");

    read(stations, MAXDIM, &c);

    for(c = 0; c < MAXDIM; c++){
        ordered[c].snowLevel = 0;
    }

    mergeSort(stations, 0, MAXDIM-1, ordered);

    for(c = 0; c < MAXDIM; c++){
        printf("Station: %s Snowl Level: %d\n", stations[c].name, stations[c].snowLevel);
    }

}