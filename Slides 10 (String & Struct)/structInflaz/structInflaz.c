#include<stdio.h>
#include<string.h>

#define MAX 10

typedef struct tem{
    char name[21];
    float old_price;
    float new_price;
}Item;

int read(Item prezzi[], int max, int *num){
    int i = 0;
    int m = 1;
    do{
        Item itemToInser;
        printf("Intert a product Name or FINE to end\n");
        scanf("%s", itemToInser.name);
        scanf("%*c");
        if(strcmp(itemToInser.name, "FINE") != 0){
            do{
                printf("Intert a product old price\n");
                scanf("%f", &itemToInser.old_price);
                scanf("%*c");
                printf("Intert a product new price\n");
                scanf("%f", &itemToInser.new_price);
                scanf("%*c");
                prezzi[i] = itemToInser;
                i++;
            }while(itemToInser.new_price < 0 && itemToInser.old_price <0);    
        }else{
            m = -1;
        }
    }while(i <= max - 1 && m > 0);

    *num = i;
    return 0;
}

int main(void){
    Item items[MAX];
    int dim;
    int i;
    printf("Give me some products and some prices i will print the tasso di inflazione of the products\n");

    read(items, MAX, &dim);

    for(i = 0; i < dim; i++){
        float infalz = ((items[i].new_price/ (float) items[i].old_price) -1)*100;
        printf("The product %s have a inflazione of %f\n", items[i].name, infalz);
    }
}