#include <stdio.h> 
#include <stdlib.h>
#include"list.h"
/*gcc voteList.c list.c -o voteList;*/


typedef item *list;


list insert(int e, list l) { 
    list t;
    t = (list) malloc(sizeof(item)); 
    t->value = e; 
    t->next = l; 
    return t; 
}

int main(void){
    FILE *fp;
    char nomeFile[20]="votes.txt\0";
    list root = NULL;
    int i = 0; 
    int value;
    fp = fopen(nomeFile, "r+");

    if(fp==NULL){
        printf("ERROR\n");
        return 0;
    }

    while (fscanf(fp, "%d \n", &value) == 1){
       if(i == 0){
           root = insert(value, root);
           i++;
       }

        root = insert(value, root);
        
    }

    showList(root);


    fclose(fp);
}