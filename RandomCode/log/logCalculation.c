#include<stdio.h>
#include<math.h>

int main(void){
    double x,b;
    float log1, log2;

    printf("Insert two positive numbers and i will calculate the log\n");
    do{
        printf("Insert the base\n");
        scanf("%lf", &b);
        scanf("%*c");
        printf("Insert the number\n");
        scanf("%lf", &x);
        scanf("%*c");
    } while (x < 0 || b < 0);

    log1 = log(x);
    log2 = log(b);
    printf("The log is %f", log1/log2);
}