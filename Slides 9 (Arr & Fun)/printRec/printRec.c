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

void print(int data[], int size){
    if (size != 0){
        size--;
        print(data, size);
        printf("element: %d\n", data[size]);
    }else{ 
    }
    return;
}

int main(void){
    int data1[max];
    int size1 = 0,i;
    

    printf("give me an array i print it recursively\n");
    /*
        when you pass an array like this you are passing to
        the function the address of the first element of the array
    */
    size1 = read(data1, max);
    print(data1, size1);

}