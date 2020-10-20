#include<stdio.h>

int main(void){
    char a,b,c;
    printf("inserisci 3 caratteri:\n");
    printf("Carattere 1:");
    scanf("%c", &a);
    scanf("%*c");
    printf("Carattere 2:");
    scanf("%c", &b);
    scanf("%*c");
    printf("Carattere 3:");
    scanf("%c", &c);
    scanf("%*c");
    printf("I caratteri scelti sono: %c, %c, %c", a,b,c);
}