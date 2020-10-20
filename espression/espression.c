#include<stdio.h>
int main(void){

    int i,k;
    float j;

    i = 20;
    k = i % 3;
    i = i / 3;
    k = i / 4.0F; //<- specifica con F che il denominatore è float
    j = i / 4.0F;

    printf("%f", j);

    return(0);
}