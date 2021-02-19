#include"element.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"list.h"
#include"order.h"

typedef Element Loan;

Loan leggiUnLoan(FILE * fp);
Loan * leggiLoanAttivi(char * fileName, int * dim);
void ordina(Loan * elenco, int dim);
list estrai(Loan * elenco, int dim, char * cognome, char * nome);
void espo(Loan * elenco, int dim);