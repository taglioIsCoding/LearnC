#include<stdio.h>

int somma(int y){
    int n;
    int sum = 0;
    for (n = 1; n <= y; n ++){
        sum = sum + n;
    }
    return sum;
}

int somma2(int x){
    int k;
    int sum = 0;
    for (k = 1; k <=x; k++){
        sum = sum + somma(k);
    }
    return sum;
}

int main(void){
    int a = 0;

    printf("Inserisci 1 numero farola sommatoria\n");
    scanf("%d", &a);
    int sumTot = somma2(a);
    printf("La sommatoria è: %d ", sumTot);
}