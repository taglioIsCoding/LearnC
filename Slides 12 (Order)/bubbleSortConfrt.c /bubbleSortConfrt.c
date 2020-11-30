#include<stdio.h>
#include"order.h"
/*gcc bubblesortconfrt.c order.c -o bubblesortcon;*/
int main(void){
    int v[] = {6,5,4,3,2,1};
    int i;
    //test naive
    naiveSort(v, 6);


    for (i=0; i<6; i++){
        printf("%d ", v[i]);
    }
    
    printf("\n"); 
    printCounters();

    resetCounters();


    //test bubble
    int a[] = {6,5,4,3,2,1};

    bubbleSort(a, 6);

    for (i=0; i<6; i++){
        printf("%d ", a[i]);
    }
    printf("\n"); 
    printCounters();

    return (0);
}
