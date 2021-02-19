/*gcc main.c list.c element.c cash.c order.c -o main*/
/*

Candidato Michele Tagliani
Matricola 0000978601

Fondamenti di informatica T1

*/
#include"cash.h"

int main(void){
    FILE *fp;
    Operazione * tutteOp;
    Operazione * operazioneFisica;
    list negozi = emptyList();
    int i = 0;
    int res;
    int dimOperazioni = 0;
    int dimOperazioniF = 0;
    char fileName[30] = "operazioni.txt\0";
    char fileName2[30] = "negozi.txt\0";

    // Riporto insieme al main richiesto nell'esercizio 4 i vari test 
    // che ho effettuato

    printf("--------LEGGI OPERAZIONI------------\n");
    tutteOp = leggiTutteOperazioni(fileName, &dimOperazioni);
    for(i = 0; i < dimOperazioni; i++){
        printf("ID: %d importo: %f Negozio: %s\n", tutteOp[i].id, tutteOp[i].importo, tutteOp[i].nomeNegozio);
    }

    printf("--------LEGGI LISTA NEGOZI------------\n");
    negozi = leggiNegozi(fileName2);
    showList(negozi);

    //L'array viene stampato partendo dall'ultimo elemento
    printf("--------STAMPA RICORSIVA------------\n");
    stampaOperazioni(tutteOp, dimOperazioni);

    //Le operzioni sono state ordinate usando l'algorimo insert sort
    printf("--------OPERAZIONI ORDINATE------------\n");
    ordina(tutteOp, dimOperazioni);
    for(i = 0; i < dimOperazioni; i++){
        printf("ID: %d importo: %f Negozio: %s\n", tutteOp[i].id, tutteOp[i].importo, tutteOp[i].nomeNegozio);
    }

    //CONTROLLO TEST DI UN NEGOZIO FISICO
    /*printf("--------LEGGI LISTA NEGOZI------------\n");
    res = negozioFisico("AmazonEUSRL", negozi);
    if(res == 0){
        printf("No fisico\n");
    }else if(res == 1)
    {
        printf("Fisico\n");
    }*/

    printf("--------OPERAZIONI NEGOZI FISICI-------\n");
    operazioneFisica = filtra(tutteOp, dimOperazioni, negozi, &dimOperazioniF);
    for(i = 0; i < dimOperazioniF; i++){
        printf("ID: %d importo: %f Negozio: %s\n", operazioneFisica[i].id, operazioneFisica[i].importo, operazioneFisica[i].nomeNegozio);
    }
    
    // printf("--------SPESA DI UN CLIENTE------------\n");
    // printf("Il cliente ha speso %f\n", spesaCliente(12, tutteOp, dimOperazioni));
    

    //Si assume che l'array sia stato ordinato dalla funzione creata in precedenza
    printf("---SPESA DI UN CLIENTE IN NEG FISICI------\n");
    for(i = 0; i < dimOperazioniF; i++){
        if(operazioneFisica[i].id != operazioneFisica[i+1].id || (i+1) > dimOperazioniF){
            printf("Il cliente %d ha speso %f\n", operazioneFisica[i].id,spesaCliente(operazioneFisica[i].id, operazioneFisica, dimOperazioniF));
        }
    }
        

    //dealloco liste e array dinamici
    list temp;
    while (!empty(negozi)){
       temp = negozi;
       negozi = tail(negozi);
       free(temp); 
    }
    free(operazioneFisica);
    free(tutteOp);
}