#include"registratore.h"
/*gcc recorder.c registratore.c -o recorder;*/
int main(void){

    FILE *fp;
    Scontrino toInsert;

    fp = fopen("reg.dat", "w");
    printf("give me a price and a number of items i will print them in binary\n");

    if(fp==NULL){
        printf("ERROR\n");
        return 0;
    }

    do{
        printf("Inserti a price or 0.00 to exit\n");
        scanf("%f", &toInsert.price);
        printf("Inserti a number of items or 0 to exit\n");
        scanf("%d", &toInsert.items);
        if(toInsert.price != 0.00 || toInsert.items != 0){
            write(fp, toInsert);
        }
    }while(toInsert.price != 0.00 && toInsert.items != 0);
    
    fclose(fp);

    fp = fopen("reg.dat", "r");
    if(fp==NULL){
        printf("ERROR\n");
        return 0;
    }

    while(read(fp, &toInsert) > 0){
        printf("Price %f Items %d\n", toInsert.price, toInsert.items);
    }

    fclose(fp);

}