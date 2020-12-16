#include<stdlib.h>
#include<stdio.h>
#include"list.h"
/*gcc videoGames.c list.c element.c -o videoGames;*/

void printGames(list l){
    while (!empty(l))
    {
        printGames(tail(l));
        printf("%d %s %d\n", l->value.id, l->value.name, l->value.num);
        return;

    }
    return; 
}

boolean loadFromFile(char *fileName, list *games){
    FILE *fp;
    Element toInsert;
    fp = fopen(fileName, "r+");
    *games = emptyList();
    if(fp==NULL){
        printf("ERROR\n");
        return false;
    }

    while(fscanf(fp, "%d %30c %c %d %f", &toInsert.id, toInsert.name, &toInsert.type, &toInsert.num, &toInsert.rate)>0){
        toInsert.name[29]='\0';
        //printf("%s\n", toInsert.name);
        *games = cons(toInsert, *games);
    }
    return true;
}

void findElementByCode(list games, int code)
{
    list cur;
    int found = 0;
    while (games != NULL && found == 0)
    {
        if (games->value.id == code){
            found = 1;
            (games->value.num)--;
        }
        else
            games = games->next;
    }
    if (games->value.id == code && games == NULL){
            found = 1;
            (games->value.num)--;
        }
    return;
}

boolean updateAvailability(char *fileName, list games){
    FILE *fp;
    fp = fopen(fileName, "r+");
    int idExit;
    if(fp==NULL){
        printf("ERROR\n");
        return false;
    }
    list temp = emptyList();
    temp = games;

    while(fscanf(fp, "%d", &idExit) == 1){
        //toInsert.name[29]='\0';
        temp = games;
        //*games = cons(toInsert, *games);
        int trovato = 0;
        while(temp->next != NULL && !trovato){
            //printf("Id giovo nella lista: %d\n", temp->value.id);
            if(temp->value.id == idExit){
                findElementByCode(games, idExit);
                trovato = 1;
            }
            temp = temp->next;
        }
        if(temp->value.id == idExit){  
                findElementByCode(games, idExit);
                trovato = 1;      
        }
        if(trovato == 0){
            printf("Error il codice %d non esiste!\n", idExit);
        }
    }
    return true;
}

int main(void){
    list games;
    list kids;
    loadFromFile("games.txt", &games);        
    printGames(games);
    printf("-------UPDATE-------\n");
    updateAvailability("sales.txt", games);
    printGames(games);
    /*printf("-------G4KIDS-------\n");
    kids = gamesForKids(games, 4);
    printGames(kids);
    saveOrdersToFile("ordine.txt", games, 5);*/ //DEALLOCAZIONE DELLE LISTE!!!
    return 0;
}