#include<stdio.h>
#include<string.h>

#define dim 108

void printchar(char a[]){
    if(a[0]== '\0'){
        return;
    }else{
        printf("%c\n", a[0]);
        printchar(&(a[1]));
    }
}

int main(void){
    char a[dim];
    printf("Give me a string i will print it recorsively\n");
    printf("String:\n");
    scanf("%s", a);

    printchar(a);

}