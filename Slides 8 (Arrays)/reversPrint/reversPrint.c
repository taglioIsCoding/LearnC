#include<stdio.h>
#define max 10

int main(void){
    int data[max], reverse[max];
    int i = 0, num, dim;
    int j = 0;

    printf("Give me some number i willl print them reversed\n");

   
    do{
        printf("Inset number %d or 0 to exit\n", i);
        do{
            scanf("%d", &num);
            if (num > 0 ){
                data[i] = num;
                i++;
            }
            if (num < 0)
                printf("You must insert natural numbers\n");
        }while(num < 0);
    }while(i < max && num!= 0);

    dim = i - 1;

    for(j = 0; j < i ; j++){
        reverse[j] = data[dim];
        dim --;
    }

    for(j = 0; j < i  ; j++){
        printf("%d: %d\n", j, reverse[j]);
    }
}