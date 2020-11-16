#include<stdio.h>
#define max 10

int read(int data[], int dimF){
    int i = 0, num;
    int j = 0;

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
    }while(i < dimF && num!= 0);
    return i;
}

int minOf2(int a, int b){
    if ( a > b){
        return b;
    }
    else if (b > a) {
        return a;
    }
    else {
       return a;
    }
}

/**
 *NOT WORKIIING
 */

int main (void){

    int data1[max], data2[max];
    int size1 = 0, size2=0;
    int i;
    int c1 = 0, c2=0;

    printf("Give me two ordered arrays and i will print them in order\n");
    size1 = read(data1, max);
    size2 = read(data2, max);

    int sizeMin = minOf2(size1, size2);

    for(i = 0; i < sizeMin; i++){
        if(data1[c1] < data2[c2]){
            printf("numberA %d\n", data1[c1]);
            c1++;
        }else{
            printf("numberA %d\n", data2[c2]);
            c2++;
        }
    }
    
    
    if(c2 < size2){
        for(i = c2; i < size2; i++){
            printf("numberB %d\n", data2[c2+i]);
        }
    }else{
        for(i = c1; i < size1; i++){
            printf("numberB %d\n", data1[c1+i]);
        }
    }

}