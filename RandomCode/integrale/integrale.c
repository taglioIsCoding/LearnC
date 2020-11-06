#include<stdio.h>
#include<math.h>

double f(double x){
    return sin(x);
}

void integral(int a, int b,int N, double * res){
    int i = 0;
    double base = b - a / N;
    for (i = 0; i < N; i++){
        *res = *res + base * f(a+i*base);
        printf("%lf\n", *res);
    }

}

int main(void){
    int a, b;
    int N;
    double res = 0;

    do{
    printf("Calculare integral with rectangles\n");
    printf("Fist point\n");
    scanf("%d", &a);
    printf("Second point\n");
    scanf("%d", &b);
    printf("N of rect\n");
    scanf("%d", &N);
    }while (b < a || N <= 0);
    
    integral(a , b, N, &res);

    printf("Integral: %lf", res);

}