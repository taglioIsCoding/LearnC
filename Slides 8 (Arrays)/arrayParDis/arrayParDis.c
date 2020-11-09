#include<stdio.h>
#define max 10

int pari(int n){
    if(n%2==0)
        return 1;
    else
        return 0;
}

int main(void){
    int ele[max], par[max], dis[max];
    int i = 0, num;
    int j = 0;
    int parC = 0, disC = 0;

    printf("Give me some number i willl split even and odd\n");

   
    do{
        printf("Inset number %d or 0 to exit\n", i);
        do{
            scanf("%d", &num);
            if (num >= 0 ){
                ele[i] = num;
                i++;
            }
            if (num < 0)
                printf("You must insert natural numbers\n");
        }while(num < 0);
    }while(i < max);

    for(i = 0; i < max; i++){
        switch (pari(ele[i])){
        case 1: {
            par[parC] = ele[i];
            parC ++;
            break;
        };
        case 0:{
            dis[disC] = ele[i];
            disC ++;
            break;
        };  
        }
    }

    printf("Even\n");
    for(j = 0; j < parC  ; j++){
        printf("%d: %d\n", j, par[j]);
    }

    printf("Odd\n");
    for(j = 0; j < disC  ; j++){
        printf("%d: %d\n", j, dis[j]);
    }

}