#include<stdio.h>

int main(void){
    int sumMax = 0;
    int inside = 0;
    char value;
    int prev = 0;
    char sum;
    
    do{
        printf("Inserisci un numero e sommo se maggiore del prec\n");
        printf("Inserisci zero per uscire\n");
        scanf("%c", &value);
        scanf("%*c");

        inside = value - '0';

        if(inside >= 1 && inside <= 9){
            if (prev <= inside){
                sum = sum + inside;
                prev = inside;
                printf("La somma parziale è: %d\n", sum);
                printf("Il prev e' %d\n", prev);
            }
            else{
                if (sum > sumMax){
                    sumMax = sum;
                    printf("Il MAX è: %d\n", sumMax);
                }
                sum = 0;
                prev = inside;
            }  
        }
    }while(inside != 0);

    printf("Il max e': %d", sumMax);
}