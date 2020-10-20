#include<stdio.h>

int main(void){
    int a,b,c;
    int tot;
    float avg;

    printf("Inserisci il primo numero\n");
    scanf("%d", &a);
    printf("Inserisci il secondo numero\n");
    scanf("%d", &b);
    printf("Inserisci il terzo numero\n");
    scanf("%d", &c);

    tot = a+b+c;
    avg = tot / 3;

    printf("il totale e: %d \n", tot);
    printf("la media e: %f", avg);
    
}