#include<stdio.h>
#define max 10

int search(int arr[], int dim, int find){
    int i;
    for(i = 0; i<dim; i++){
        if(arr[i]==find){
            return 1;
        }
    }
    return 0;
}

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

int main(void){
    int data1[max], data2[max], dataU[max];
    int size1 = 0, size2=0,i , num, find;
    int j = 0;
    int dataC = 0;
    

    printf("Give me two array i will print the inserction\n");
    /*
        when you pass an array like this you are passing to
        the function the address of the first element of the array
    */
    size1 = read(data1, max);
    size2 = read(data2, max);
    
    for(i = 0; i < size1; i++){
        if(search(data2, size2, data1[i])){
            dataU[dataC] = data1[i];
            dataC ++; 
        }
    }
    
    for(i = 0; i< dataC; i++)
        printf("Element %d: %d\n", i, dataU[i]);
}
    
