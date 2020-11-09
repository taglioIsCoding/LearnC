#include<stdio.h>
#define max 10

int main(void){
    int loc[max], snow[max];
    int i = 0, num, num2;
    int j = 0;
    float avg;

    printf("Give the Place number and the Leve of snow\n");

   
    do{
        printf("Insert Place number %d or 0 to exit\n", i);
        do{
            scanf("%d", &num);
            if (num > 0 ){
                loc[i] = num;
                printf("Insert the level of snow %d\n", i);
                scanf("%d", &num2);
                snow[i] = num2;
                i++;
            }
            if (num < 0)
                printf("You must a valid number\n");
        }while(num < 0);
    }while(i < max && num!= 0);

    //dim = i - 1;

    for(j = 0; j < i ; j++){
        avg += snow[j];
    }

    avg = avg/ (float)i;

    printf("Places with a low level of snow are:\n");
    for(j = 0; j < i  ; j++){
       if(snow[j]< avg){
           printf("%d have less snow\n", loc[j]);
       }
    }
}