#include<stdio.h>

int main(void){
    float a,b;
    char o;

    printf("Inserisci due numeri e l'operazione desiderata!\n");
    printf("Numero 1:\n");
    scanf("%f", &a);
    scanf("%*c");
    printf("Numero 2:\n");
    scanf("%f", &b);
    scanf("%*c");
    printf("Operazine:\n");
    scanf("%c", &o);
    scanf("%*c");


    switch (o)
    {
    case '+':
        printf("Somma: %f", a+b);
        break;
    case '-':
        printf("Sottrazione: %f", a-b);
        break;
    case '*':
        printf("Moltiplicazione: %f", a*b);
        break;
    case ('/'):
        if (b != 0){
            printf("Rapporto: %f", a/b);
            break;
        }else {
            printf("undefined");
            break;
        }  
    default:
        printf("undefined");
        break;
    }
}