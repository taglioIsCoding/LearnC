#include<stdio.h>
#define max 4

int main(void){
    int v1[max], v2[max], vUnion[max];
    int i = 0, num;
    int v1c = 0, v2c = 0;
    int j = 0;

    printf("Give me two array i will altern the elemnts\n");

   
    do{
        printf("Inset number %d of v1\n", i);
        scanf("%d", &num);
        v1[i] = num;
        i++;
    }while(i < max);

    do{
        printf("Inset number %d of v2\n", j);
        scanf("%d", &num);
        v2[j] = num;
        j++;
    }while(j < max);

    for(i = 0; i < max * 2; i++){
        if(i%2==0){
            vUnion[i] = v1[v1c];
            v1c ++;
        }else
        {
            vUnion[i] = v2[v2c];
            v2c ++;
        }    
    }

    for(j = 0; j < max * 2  ; j++){
        printf("%d: %d\n", j, vUnion[j]);
    }
}
