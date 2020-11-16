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

int search(int arr[], int * dim, int find, int last, int * pos){
    int i;
    int lastIndex = 0;
    for(i = 0; i< *dim; i++){
        if(arr[i]==find){
            *pos = i;
        }
    }

    for(i = 0; i< *dim; i++){
        if(arr[i]==last){
            lastIndex = i;
        }
    }

    if(*pos == 0){
        return -1;
    }else{
        *dim = lastIndex - *pos + 1;
        return *pos; 
    }
    
}

int main(void){
    int data1[max];
    int i;
    int first, last;
    int index = 0;
    int size1, posFirst;

    printf("Insert an ordinate array, a first element and a last i will find the pinter to the first element and the dimension of the sub array\n");

    size1 = read(data1, max);

    printf("insert the first element of the sub array\n");
    scanf("%d", &first);
    printf("insert the last element of the sub array\n");
    scanf("%d", &last);
    
    posFirst = search(data1, &size1, first, last ,&index);

    if(posFirst < 0){
        printf("ERROR\n");
    }else{
        printf("First element index: %d, subdim: %d\n", posFirst, size1);
    }
    

}