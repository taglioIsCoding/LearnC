#include"bank.h"

int readField(char buffer[], char sep, FILE *f)
{
    int i = 0;
    char ch = fgetc(f);
    while (ch != sep && ch != 10 && ch != EOF ) {
        buffer[i] = ch;
        i++;
        ch = fgetc(f);
    }
    buffer[i] = '\0';
    if(i>0){
        return 1;
    }else{   
        return 0;
    }
    //return ch;
}

Loan leggiUnLoan(FILE * fp){

    Loan e;
    int i = 0;
    

    i = fscanf(fp, "%d ", &e.id);
    i += readField(e.surname, ';', fp);
    i += readField(e.name, ';', fp);
    i += fscanf(fp, "%f\n", &e.amount);

    if(i==4){
        return e;
    }else{
        e.id = 0;
        return e;
    }
}

Loan * leggiLoanAttivi(char * fileName, int * dim){
    Loan  *activeLoans;
    FILE *fp;
    Loan toInsert;
    int finito = 0;
    int i=0;
    char ch;
    int lines = 0;

    fp = fopen(fileName, "r");
    if(fp==NULL){
        printf("ERROR\n");
        *dim = 0;
        fclose(fp);
        return NULL;
    }

    while (!feof(fp))
    {
        ch = fgetc(fp);
        if (ch == '\n')
        {
            lines++;
        }
    }

    lines ++;
    rewind(fp);
    while(finito!=lines){
        toInsert = leggiUnLoan(fp);
        if(toInsert.id != 0){
            if(strstr(toInsert.surname, "ESTINTO")== NULL){
                (*dim)++;
            }
        }
        finito++;
    }

    finito = 0;
    int some = (*dim);
    printf("%d\n", some);
    rewind(fp);
    activeLoans = (Loan *) malloc((*dim)*sizeof(Loan));
    while(finito != lines){
        toInsert = leggiUnLoan(fp);
        if(toInsert.id != 0){
            if(strstr(toInsert.surname, "ESTINTO")== NULL){
                activeLoans[i] = toInsert;
                i++;
            }  
        }
        finito++;
    }
    fclose(fp);
    return activeLoans;
}

void ordina(Loan * elenco, int dim){
    insertSort(elenco, dim);
}

list estrai(Loan * elenco, int dim, char * cognome, char * nome){
    int i = 0;
    list c = emptyList();
    for(i = 0; i < dim; i++){
        if(strcmp(elenco[i].name, nome)==0 && strcmp(elenco[i].surname, cognome)==0){
            c = cons(elenco[i], c);
        }
    }
    showList(c);
    return c;
}

void estraoPerEspo(Loan * elenco, int dim, char * cognome, char * nome, int * j){
    int i = *j;
    float tot = 0;
    int trovati = 0;
    list c = emptyList();
    for(; i < dim; i++){
        if(strcmp(elenco[i].name, nome)==0 && strcmp(elenco[i].surname, cognome)==0){
            printf("CIAO\n");
        }
    }
}

//SI SUPPONE ARRAY ORDINATO
void espo(Loan * elenco, int dim){
    int flag = 0;
    int i = 0;
    float tot = 0;
    
    while (i < dim)
    {   
        tot = 0;
        do{
            tot+= elenco[i].amount;
            i++;
        }while (strcmp(elenco[i-1].name, elenco[i].name)==0 && strcmp(elenco[i-1].surname, elenco[i].surname)==0); 
        printf("Sur: %s Amount %f\n", elenco[i-1].name, tot);
    }
    
    
}
