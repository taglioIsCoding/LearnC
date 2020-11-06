#include<math.h>
#include<stdio.h>

void converti_complex(float re, float im, float * modulo, float * argomento){
    float arg, mod;

    arg = sqrt(re*re+im*im);
    mod = atan2(im, re);

    *modulo = mod;
    *argomento = arg;
}

int main(void){
    float re, im;
    float modulo, argomento;
    printf("Give me the real part: \n");
    scanf("%f", &re);
    printf("Give me the immaginal part: \n");
    scanf("%f", &im);

    converti_complex(re, im, &modulo, &argomento);

    printf("Module: %f\n", modulo);
    printf("Arg: %f\n", argomento);

}