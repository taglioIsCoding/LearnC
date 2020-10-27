#include<stdio.h>

int max(int x, int y){
    if( x > y){
        return x;
    }else{
        return y;
    }
}

int max3(int x, int y, int z){
    int maxT = max(x, y);
    int maxD = max(maxT, z);
    return maxD;
}

int main(void){
    int a = 0;
    int b = 0;
    int c = 0;

    printf("Inserisci 3 numeri faro max dei primi 2 e max di tutti e tre\n");
    printf("numero 1)\n");
    scanf("%d", &a);
    printf("numero 2)\n");
    scanf("%d", &b);
    printf("numero 3)\n");
    scanf("%d", &c);
    int max2 = max(a, b);
    printf("Il massimo tra i primi due e': %d\n", max2);
    int maxAll = max3(a, b, c);
    printf("Il massimo tra tutti e tre e': %d\n", maxAll);
}