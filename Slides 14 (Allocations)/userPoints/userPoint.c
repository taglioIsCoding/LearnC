#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 20

typedef struct{
    char name[20];
    int points;
} User;

int writeRandom(FILE *fp){
    User insert[MAX];
    int i=0;
    for(i = 0; i < 14; i++){
        strcpy(insert[i].name, "Mario\0");
        insert[i].points= i * 10 +1;
    }

    for(i = 0; i < 14; i++){
        fwrite(&insert[i],sizeof(User),1,fp);
    }
    return 0;
}

int readPoints(char userFile[], User result[], int maxDim, int minPoints){
    FILE *fp;
    int i=0;
    fp = fopen(userFile, "rb+");
    if(fp==NULL){
        printf("ERROR\n");
        return 0;
    }


    User temp;
    while(fread(&temp,sizeof(User),1,fp) == 1){
        if(temp.points > minPoints){
            result[i] = temp;
            i++;
        }
    }
    fclose(fp);
    return i;
}

int numberOfElements(char userFile[]){
    FILE *fp;
    User temp;
    int i=0;
    fp = fopen(userFile, "rb+");
    if(fp==NULL){
        printf("ERROR\n");
        return 0;
    }

    writeRandom(fp);
    rewind(fp);

    while(fread(&temp,sizeof(User),1,fp) == 1){
        i++;
    }
    rewind(fp);
    fclose(fp);
    return i;
}

int main(void){
    char fileName[MAX];
    strcpy(fileName, "users.dat\0");
    User *users;
    int minPoints = 3;
    int tot;
    int i;

    printf("Give me the min number of points i willl print the users which name starts with Ma\n");
    printf("Insert min number of points:\n");
    scanf("%d", &minPoints);

    tot = numberOfElements(fileName);
    users = (User *) malloc(sizeof(User) * tot);
    tot = readPoints(fileName, users, MAX, minPoints);

    for(i = 0; i < tot; i ++){
        if(users[i].name[0]=='M' && users[i].name[1]=='a')
        printf("User: %s Points: %d\n", users[i].name, users[i].points);
    }

    free(users);
}