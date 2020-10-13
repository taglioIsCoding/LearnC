#include <stdio.h>

int test(void){
    printf("ciao");
    return 0;
}

int print(void){
    int k;
    scanf("%d", &k);
    printf("The squere of %d is: %d", k, k*k);
    return 0;
}

int main(void){
    double k = 5.6;

    k = k - 5.59; 
    
    int c = print();
    
    return 0;
}
