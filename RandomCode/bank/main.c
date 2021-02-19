/*gcc main.c bank.c list.c element.c order.c -o bank*/

#include"bank.h"

int main(void){
    FILE *fp, *fc;
    Loan test;
    Loan * tuttiLoan;
    list LoanOfPeople;
    int i = 0;
    int dimLoan = 0;
    char fileName[30] = "prestiti.txt\0";
    fp = fopen("prestiti.txt", "r");

    if(fp==NULL){
        printf("ERROR\n");
        return false;
    }

    test = leggiUnLoan(fp);

    printf("--------LEGGI UNO------------\n");
    printf("ID: %d Sur: %s Name: %s amount: %f \n", test.id, test.surname, test.name, test.amount);
    fclose(fp);

    printf("--------LEGGI ATTIVI------------\n");
    tuttiLoan = leggiLoanAttivi(fileName, &dimLoan);
    for(i = 0; i < dimLoan; i++){
        printf("ID: %d sur: %s\n", tuttiLoan[i].id, tuttiLoan[i].surname);
    }

    printf("--------ORDINA ATTIVI------------\n");
    ordina(tuttiLoan, dimLoan);
    for(i = 0; i < dimLoan; i++){
        printf("ID: %d Sur: %s Name: %s amount: %f \n", tuttiLoan[i].id, tuttiLoan[i].surname, tuttiLoan[i].name, tuttiLoan[i].amount);
    }

    printf("--------CERCA PERSONE------------\n");
    LoanOfPeople = estrai(tuttiLoan, dimLoan, "Chesani Mazzanti", "Federico Domenico Maria");
    
    printf("--------ESPOSIZIONE------------\n");
    espo(tuttiLoan, dimLoan);    


    list temp;
    while (!empty(LoanOfPeople)){
       temp = LoanOfPeople;
       LoanOfPeople = tail(LoanOfPeople);
       free(temp); 
    }
    free(tuttiLoan);
}