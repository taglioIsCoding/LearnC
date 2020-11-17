#include<stdio.h>
#include<string.h>

int concat(char a[], char b[], char c[]){
    int i = 0;
    int j = 0;
    
    for(i = 0; i < strlen(a) ; i++){
        c[i] = a[i];
    }

    for(j = 0; j < strlen(b); j++){
        c[i] = b[j];
        i++;
    }
    
    c[i]='\0';
    return i;

    /*
    strcpy(c, a);
    strcpy(&c[strlen(c)], b);
    return strlen(c)*/

}

int main(void){
    char a[] = {'c', 'i','a','0','!','\0'};
    char b[] = {'w', 'o', 'r', 'l', 'd', '\0'};
    char c[200];

    printf("I copy two string in another string\n");

    int tot = concat(a, b, c);
    printf("The string is %s and the lenght is %d\n", c, tot);
}