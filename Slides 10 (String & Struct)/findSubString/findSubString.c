#include<string.h>
#include<stdio.h>

#define dim 108

int findHowMany(char a[], char b[]){
    char sub[dim];
    strcpy(sub, "");
    int g = strlen(a);
    int i = 0;
    int c = 0;
    for(; i < strlen(b); i++){
        if(strcmp(a, memcpy(sub, &b[i], g))== 0){
            c++;
        }
    }

    return c;

}

int main(void){
    char a[dim], b[dim];

    printf("Give me two string i will find how many times the second is in the first\n");
    printf("First\n");
    scanf("%s", a);
    printf("Second\n");
    scanf("%s", b);

    int tot = findHowMany(a, b);
    printf("%d", tot);

}