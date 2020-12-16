#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"
#define MAX 64
/*gcc works.c list.c element.c -o works;*/


typedef struct
{
    char clientName[MAX];
    int day;
    float amount;
}Work;

//I write the binary files
int write(FILE *fp, Work src){
    strcpy(src.clientName, "Marcellino\0");
    src.amount=12.54;
    src.day=24;

    fwrite(&src,sizeof(src),1,fp);

    strcpy(src.clientName, "caVolox\0");
    src.amount=132;
    src.day=55;

    fwrite(&src,sizeof(src),1,fp);

    return 0;
}

/*list findBills(char *fileName, char *clientName){

}*/

void findFile(FILE *fp, char *clientName, char *fileFound){
    char userName[MAX];
    char fileName[MAX];
    while (fscanf(fp, "%s %s", userName , fileName) != EOF)
    {   
        if(strcmp(clientName, userName)== 0){
            strcpy(fileFound, fileName);
            return;
        }
    }
    strcpy(fileFound, NULL);
    return;
}

int main(void){
    FILE *fp;
    fp = fopen("register.txt", "r");
    if(fp==NULL){
        printf("ERROR\n");
        return 0;
    }
    char clientName[64];
    char fileName[MAX];
    printf("Insert the client name\n");
    scanf("%s", clientName);

   findFile(fp, clientName, fileName);

    printf("Il cliente e sul file %s\n", fileName);



    fclose (fp);
}