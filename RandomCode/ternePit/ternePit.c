#include<stdio.h>

int isTernaPit(int x, int y, int z){
    if(x*x+y*y==z*z){
        return 1;
    }
    return 0;
}

void trovaTerne(int n){
    int x, y, z;
    for (x = 1; x < n; x++){
        for (y = 1; y < n; y++){
            for (z = 1; z < n; z++){
                if(isTernaPit(x,y,z)){
                   printf("%d, %d, %d è una terna pitagorica!\n", x, y, z);
                } 
            } 
        }
    }
}

int main(void){
    int a;
    printf("Dammi un numero e troverò tutte le terne pitagoriche\n");
    scanf("%d", &a);
    trovaTerne(a);

}