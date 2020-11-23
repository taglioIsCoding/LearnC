#include<stdio.h>
#define max 10

int main(void){

    //Le strutture andrebbero nel punto h se ci fossero piu file
    struct Corso {
        char denominazione[21];
        char nomeDoc[21];
        int nStudenti;
    };

    struct Corso corsi[max];
    int nCors;
    int avg;
    int sum = 0;
    int i;

    printf("Insert some courses i will print the ones with more studats than the avarage\n");
    printf("Intert the number or courses\n");
    scanf("%d", &nCors);

    for(i = 0; i < nCors; i++){
        struct Corso c1;
        printf("Intert the name of the cours\n");
        scanf("%s", c1.denominazione);
        printf("Intert the name of teacher\n");
        scanf("%s", c1.nomeDoc);
        do{
            printf("Intert the name of the students\n");
            scanf("%d", &c1.nStudenti);
        }while(c1.nStudenti < 0);

        corsi[i] = c1;
    }

    for(i = 0; i < nCors; i++){
        sum += corsi[i].nStudenti;
    }

    avg = sum / nCors;

    for(i = 0; i < nCors; i++){
        if( corsi[i].nStudenti > avg){
            printf("The course: %s \nThe Teacher is %s \n", corsi[i].denominazione, corsi[i].nomeDoc);
        }
    }


}