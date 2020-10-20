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

    if (a > b && a > c){
        if (b > c){
        printf("%c\n", a);
        printf("%c\n", b);
        printf("%c\n", c);
        }else{
            printf("%c\n", a);
            printf("%c\n", c);
            printf("%c\n", b);
        }
    }else if (b > a && b > c){
        if (a > c){
        printf("%c\n", b);
        printf("%c\n", a);
        printf("%c\n", c);
        }else{
            printf("%c\n", b);
            printf("%c\n", c);
            printf("%c\n", a);
        }
    } else if (c > a && c > b){
        if (a > b){
        printf("%c\n", c);
        printf("%c\n", a);
        printf("%c\n", b);
        }else{
            printf("%c\n", c);
            printf("%c\n", b);
            printf("%c\n", a);
      
        }
    }
}