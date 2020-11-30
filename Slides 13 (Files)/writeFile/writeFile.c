#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main(void){
    FILE *fptr;
    int m = 1;
    char toInser[20];

    printf("I will write on a file\n");
    /*to edit the file use a*/
    fptr = fopen("test.txt","w");
    if(fptr==NULL){
        printf("ERROR\n");
        return 0;
    }

    do{
        printf("Inster a string of FINE to exit\n");
        scanf("%s", toInser);
        scanf("%*c");
        strcat(toInser, " ");
        if(strcmp(toInser, "FINE ") != 0){
            fprintf(fptr,"%s", toInser);    
        }else{
            m = -1;
        }
    }while(m > 0);
    
    fclose(fptr);
}