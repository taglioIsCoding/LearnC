#include<stdio.h>

int main(void){
    int a = 0;
    int sum = 0, i = 0, j= 0;

    printf("Inserisci un numero e faro la doppia sommatoria\n");
    scanf("%d", &a);

    for ( i = 1; i <= a ; i++ ){
        for ( j = 1; j <= i; j++ ){
            sum = sum + j;
        }
    }

    printf("Il totlale e': %d", sum);
}