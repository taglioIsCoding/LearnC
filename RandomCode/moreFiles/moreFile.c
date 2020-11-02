#include<stdio.h>
#include"./myMax.h"
#define MAX 5

int main(void){

    int n;
    int ma = 0;

    int i = 0;
    for(i = 0; i < MAX; i++){
        printf("give the %d number\n", i);
        scanf("%d", &n);
        ma = max(n, ma);
    }

    printf("%d", ma);
    
} 
