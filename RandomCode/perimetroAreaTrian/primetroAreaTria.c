#include<stdio.h>
#include<math.h>

float perimetro(float x, float y, float z){
    return x+y+z;
} 

float area(float x, float y, float z){
    float p = perimetro(x, y, z)/ 2.0F;
    return sqrt(p * (p - x) * (p - y) * (p - z));
}

int main(void){
    float a, b, c;
    printf("Dammi i tre lati di un triangolo e calcolero perimetro e area\n");
    printf("Lato 1\n");
    scanf("%f", &a);
    printf("Lato 2\n");
    scanf("%f", &b);
    printf("Lato 3\n");
    scanf("%f", &c);

    float per = perimetro(a,b,c);
    printf("Perimetro: %f\n", per);
    float ar = area(a, b, c);
    printf("Area: %f", ar);

}