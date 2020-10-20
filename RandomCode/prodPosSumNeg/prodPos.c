#include<stdio.h>

int main(void){
    int totSum = 0;
    int totProd = 0;
    int c;
    do
    {
        printf("Insert a number or zero to exit:\n");
        scanf("%d", &c);
        scanf("%*c");
        if ( c > 0){
            if (totProd == 0){
                totProd = 1;
            }
            totProd = totProd * c;
        }else if (c < 0){
            totSum = totSum + c;
        }
    } while (c != 0);

    printf("The prod of positives is %d\n", totProd);
    printf("The sum of neg is %d\n", totSum);

}