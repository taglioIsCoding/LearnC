#include<stdio.h>

int ric(int x){
    if ( x == 0){
        return 0;
    }else {
       return x + ric(x-1);
    }
}

int main(void){
    int n;
    int res;
    printf("Dammi un numero e faro la sonna in modo ricorsivo\n");
    scanf("%d", &n);

    res = ric(n);

    printf("Il totale e': %d", res);

}