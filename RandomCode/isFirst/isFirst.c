#include<stdio.h>

int isPrimo(int x){
    int i;
    if(x == 2 ){
        return 1;
    }else
    {
        for (i = 2; i < x-1; i++){
            if(x % i == 0){
                return 0;
            }
        }
        return 1;
    }
}

void primi(int a){
    int i;
    for ( i = 0; i < a; i++){
        if(isPrimo(i)){
            printf("Il numero %d è primo!\n", i);
        }
    } 
}

int main(void){
    int a;
    printf("Ti quali numeri primi ci sono fino a N\n");
    scanf("%d", &a);
    primi(a);
}