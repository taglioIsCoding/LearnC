#include<stdio.h>

int main(void){
    char c;
    do{
        printf("inserisci un carattere e ti daro il suo Ascii\n");
        printf("premi zero per uscire\n");
        scanf("%c", &c);
        scanf("%*c");
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){
            printf("il carattere scelto e' %c \n", c);
            printf("il codice ascii e' %d\n", c);
        } else {
            printf("Errore!\n");
        }
    }while (c!= '0');
    

}