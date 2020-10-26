#include<stdio.h>
#include<math.h>

int main(void){
    int i = 0;
    int a = 0;
    float res = 0;

    do{
        printf("Inserisci un numero e faro la formula\n");
        printf("Inserisci un numero negativo per uscire\n");
        scanf("%d", &a);
        scanf("%*c");
        res = 0;

        if(a > 0){
            for ( i = 0; i <= a ; i++ ){
                if(i%2 == 0){
                    res = res + ((float)4 /(2*i +1)) ;
                }else
                {
                    res = res + (-1 * ((float)4/(2*i +1))) ;
                }
            }
            printf("Il totlale e': %f \n", res);
        }
    }while(a>0);
}