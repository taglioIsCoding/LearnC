#include<math.h>
#include<stdio.h>

void sumIm(float * re, float * im, float * re2, float * im2, float * reTot, float * imTot){
    
    *reTot = *re + * re2;
    *imTot = *im + *im2;
    return;
}

int main(void){
    float re, im, re2, im2;
    float reTot, imTot;

    printf("Give me the first real part: \n");
    scanf("%f", &re);
    printf("Give me the first immaginal part: \n");
    scanf("%f", &im);
     printf("Give me the second real part: \n");
    scanf("%f", &re2);
    printf("Give me the second immaginal part: \n");
    scanf("%f", &im2);

    sumIm(&re, &im, &re2, &im2, &reTot, &imTot);

    printf("Module: %f\n", imTot);
    printf("Arg: %f\n", reTot);

}