#include<stdio.h>

void toMin(int mill, int * min, int * sec, int * milli){
    * milli = mill % 1000;
    *sec = mill / 1000;
    *min = *sec / 60;
    
    return;
}

int main(void){
    int millisecondi;
    int min, sec, milli;
    printf("Give me milliseconds: \n");
    scanf("%d", &millisecondi);

    toMin(millisecondi, &min, &sec, &milli);

    printf("Time %d:%d.%d\n", min, sec, milli);
    
}