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

int delDouble(int data[], int size1, int res[], int sizeResF){
    int i;
    int size2 = 0;
    int c = size1;
    for(i = 0; i < size1; i++){
        if(search(&data[i+1], c - 1, data[i])){
            c--;
        }else{
            res[size2] = data[i];
            size2 ++;
            c--;
        }
    }
    return size2;
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
    int data1[max], data2[max];
    int size1 = 0, size2=0,i;
    int j = 0;
    

    printf("Give me one array i will delete double elements\n");
    /*
        when you pass an array like this you are passing to
        the function the address of the first element of the array
    */
    size1 = read(data1, max);
    size2 = delDouble(data1, size1, data2, max);

     printf("-------------------------------\n");

    for(i =0; i < size2; i++){
        printf("Element %d: %d\n",i, data2[i]);
    }
    
}
    
