#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"gestione.h" 

int main(void){
    Booking bookingArray[MAX];
    int dim = 0;
    int i;
    printf("If u want the program description search es 5 slides 10\n");

    while(1){
        Booking bokingToinsert;
        int c = read(&bokingToinsert);
        switch(c){
                case 0:{
                    exit(0);
                    break;
                }
                case 1:{
                    int d = assegna(bookingArray, MAX, &dim, bokingToinsert.name, bokingToinsert.place);
                    if(d == 1){
                        printf("SUCCESS!\n");
                    }else{
                        printf("ERROR!\n");
                        d--;
                    }
                    break;
                }
                case -1:{
                    for(i = 0; i < dim; i++ ){
                        printf("User: %s Place: %d\n", bookingArray[i].name, bookingArray[i].place);
                    }
                    exit(0);
                    break;
                }
        }
    }
    

}
