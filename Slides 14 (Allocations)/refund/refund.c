#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1023
/*NOT FINISHHHHH*/
typedef struct {
    int idTrav;
    char type[MAX];
    float amount;
} Pay;

typedef struct{
    int idTrav;
    Pay *shops;
    int dim;
}Refund;

void scriviSpese(char * nomeFile){
    printf("%s", "Insert your employee number\n");
    scanf("%s", nomeFile);

    //create de .txt file
    FILE *fp;
    int i=0;
    fp = fopen(strcat(nomeFile, ".txt"), "w+");
    if(fp==NULL){
        printf("ERROR\n");
        return;
    }

    Pay toInsert;

    do{
        printf("%s", "Intert the travel id\n");
        scanf("%d", &toInsert.idTrav);
        printf("%s", "Intert the type\n");
        scanf("%s", toInsert.type);
        printf("%s", "Insert the amount or -1 to exit\n");
        scanf("%f", &toInsert.amount);
        if(toInsert.amount != -1){
            fprintf(fp,"%d %s %f\n", toInsert.idTrav, toInsert.type, toInsert.amount);
        }
    }while (toInsert.amount != -1);
    

    fclose(fp);
    return;
};

Pay * leggiSpese(char * nomeFile, int * dim){
    FILE *fp;
    Pay temp;


    int i=0;
    fp = fopen(nomeFile, "r+");
    if(fp==NULL){
        printf("ERROR\n");
        return 0;
    }

    while (fscanf(fp, "%d %s %f\n", &temp.idTrav , temp.type, &temp.amount) > 0){
        (*dim)++;
    }

    Pay * pays;
    pays = (Pay *) malloc(sizeof(Pay)* (*dim));
    rewind(fp);

    while (fscanf(fp, "%d %s %f\n", &temp.idTrav , temp.type, &temp.amount) > 0){
        pays[i] = temp;
        i++;
    }

    fclose(fp);
    return pays;
    
}

int compare(Pay s1, Pay s2){
    if(s1.idTrav > s2.idTrav){
        return 1;
    }else if(s1.idTrav < s2.idTrav){
        return -1;
    }else {
        return 0;
    }
}

void merge(Pay v[], int i1, int i2, int fine, Pay vout[])
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

void mergeSort(Pay v[], int iniz, int fine, Pay vout[])
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
  char nomeFile[MAX]="ciao.txt\0";
  int dim, i;

  //scriviSpese(nomeFile);  
  Pay * spese = leggiSpese(nomeFile, &dim);  
  Pay * oderedPays;
    printf("%d\n", dim);

    mergeSort(spese, 0, dim-1, oderedPays);

  for(i =0; i< dim; i++){
      printf("%s\n", (oderedPays[i]).type);
  }


}