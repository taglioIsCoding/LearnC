#include<stdio.h>

void reverse(){
    char c;
    printf("insert a new char\n");
    scanf("%c", &c);
    scanf("%*c");

    if (c == '\n'){
        return;
    }
    else{
       reverse();
       printf("%c", c);
    }
}

int main(void){
    char c, tot;
    printf("Give me a string and i will reverse it i will stop with backslash n \n ");

    reverse();
}