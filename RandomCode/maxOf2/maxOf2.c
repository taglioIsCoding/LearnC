#include<stdio.h>

int main(void){
    float a,b;
    

    printf("Inserisci il primo numero\n");
    scanf("%f", &a);
    scanf("%*c");
    printf("Inserisci il secondo numero\n");
    scanf("%f", &b);
    scanf("%*c");


    if ( a > b){
        printf("il maggiore e %f", a);
    }
    else if (b > a) {
        printf("il maggiore e %f", b);
    }
    else {
        printf("i due muneri sono uguali");
    }
      
}