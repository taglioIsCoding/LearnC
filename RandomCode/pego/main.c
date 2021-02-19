#include"pego.h"

/*gcc main.c element.c list.c pego.c order.c -o main;*/

int main(void){

    FILE *fp, *fc;
    Set test;
    Complex comp;
    list tuttiSets;
    int i = 0;
    int num;
    char fileName[30] = "negozio\0";
    char fileComp[30] = "complessi.txt\0";
    fp = fopen("negozio.txt", "r");

    if(fp==NULL){
        printf("ERROR\n");
        return false;
    }

    test = leggiUnSet(fp);

    printf("--------LEGGI UNO------------\n");
    printf("Set: %d desc: %s type: %c n: %d cost: %f \n", test.id, test.desc, test.type, test.avaible, test.cost);
    fclose(fp);

    printf("--------LEGGI TUTTI------------\n");
    tuttiSets = leggiTutti(fileName);
    showList(tuttiSets);

    printf("--------LEGGI UN COMPLEX------------\n");
    fc = fopen("complessi.txt", "r");
    if(fc==NULL){
        printf("ERROR\n");
        return false;
    }
    comp = leggiUnComplex(fc);
    printf("Id: %d \n", comp.idC);
    for(i = 0; i < comp.dimParts; i++){
        printf("Set: %d ", comp.idParts[i]);
    }
    fclose(fc);

    printf("\n");
    printf("--------TROVA COMPKLEX------------\n");
    comp = trovaComplex(fileComp, 48960);
    printf("Id: %d \n", comp.idC);
    for(i = 0; i < comp.dimParts; i++){
        printf("Set: %d ", comp.idParts[i]);
    }
    printf("\n");

    printf("--------Controllo disponibuilita------------\n");
    printf("Inserisci il set da controllare\n");
    scanf("%d", &num);
    switch (disp(tuttiSets, num ,fileComp))
    {
    case 10:
        printf("C'e' \n");
        break;
    case -10:
        printf("NON C'e' \n");
        break;
    }

    list temp;
    while (!empty(tuttiSets)){
       temp = tuttiSets;
       tuttiSets = tail(tuttiSets);
       free(temp); 
    }
    fclose(fp);

}