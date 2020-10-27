#include<stdio.h>

int potenza(int x, int y){
    int pow = 1;
    int i;
    for (i = 0; i < y; i++){
       pow = pow * x;
    }
    return pow;
}

int sommaPotenze(int a, int n){
    int i;
    int tot;
    for(i = 1; i <= n; i++){
        tot = tot + potenza(a, i);
    }
    return tot;
}

int main(void){
    int a, n;

    printf("Dammi 2 numeri e sommero le diverse potenze\n");
    printf("Numero di cui fare la potenza\n");
    scanf("%d", &a);
    printf("Numero di somme\n");
    scanf("%d", &n);

    int powSum = sommaPotenze(a, n);
    printf("%d", powSum);
}