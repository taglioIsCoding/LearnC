#include<stdio.h>
#define max 10

int main(void){
    int data[max];
    int i = 0, num;
    int j = 0;

    printf("Give me some number i willl print them if they are the same\n");

   
    do{
        printf("Inset number %d or 0 to exit\n", i);
        scanf("%d", &num);
        if (num != 0)
            data[i] = num;
        i++;
    }while(i < max && num!= 0);

    for(; j < i-1 ; j++){
        if (data[j] == data[j + 1])
        printf("%d: %d\n", j, data[j]);
    }
   
}