#include<stdio.h>
#define max 10

void search(int arr[], int dim, int find){
    int i;
    for(i = 0; i<dim; i++){
        if(arr[i]==find){
            printf("Index: %d", i);
        }
    }
    return;
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
    int data[max];
    int size = 0, num, find;
    int j = 0;

    printf("Give me some number i willl find one in the array\n");
    /*
        when you pass an array like this you are passing to
        the function the address of the first element of the array
    */
    size = read(data, max);
    
    do{
        printf("Give me the number to find\n");
        scanf("%d", &find);
    }while(find < 0);

    search(data, size, find);
    

}