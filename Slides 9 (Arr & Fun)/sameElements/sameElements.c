#include<stdio.h>
#define max 10
#define TYPE int
#define TRUE 1
#define FALSE 0

int read(TYPE data[], int dimF){
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

int min(int a, int b){
    if(a > b){
        return b;
    }else{
        return a;
    }
    
}

int search(TYPE arr[], int dim, int find, int check[]){
    int i;
    for(i = 0; i<dim; i++){
        if(arr[i]==find && check[i]!= TRUE){
            check[i] = TRUE;
            return TRUE;
        }
    }
    return FALSE;
}

int compareTo(TYPE data1[], TYPE data2[], int dim1, int dim2){
    int dimMin = min(dim1, dim2);
    int i = 0;
    int res;
    int strc[dim1];
    
    for (i = 0; i < dim1; i++){
        strc[i] = FALSE;
    }

    if(dim1 != dim2){
        return FALSE;
    }else{
        do{
            res = 0;
            res = search(data1, dim1, data2[i], strc);
            i++;
        }while(i < dim1 && res != 0 );

        if (res == 0){
            return FALSE;
        }else{
            return TRUE;
        }
    }

    
}

int main(void){
    TYPE data1[max], data2[max];
    int dim1, dim2;
    int i = 0, res;

    printf("Give me two arrays i will checks if there are the same elements\n");
    dim1 = read(data1, max);
    dim2 = read(data2, max);


    //printf("%d", compareTo(data1, data2, dim1, dim2));
    if(compareTo(data1, data2, dim1, dim2) == FALSE){
        printf("Not equals\n");
    }else
    {   
        if(compareTo(data2, data1, dim2, dim1) == TRUE){
            printf("Equals\n");
        }else{
            printf("Not equals\n");
        }
        
    }
    

}