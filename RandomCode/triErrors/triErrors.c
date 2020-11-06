#include<stdio.h>
#include<math.h>


int check(float a, float b, float c){
    if (a<0 || b <0 || c < 0 || a + b < c || b +c < a || c + a < b ){
        return 1;
    } else if ( a == 0 || b == 0 || c == 0 || a+b == c || b+c == a || a+c == b ){
        return 2;
    }else{
        return 0;
    }

}

void calculate(float a , float b, float c, float * area, float * peri ){

    *peri = a + b +c;
    *area = sqrt(*peri/2 * (*peri/2 - a)*(*peri/2 - b)*(*peri/2 - c));
}

int main(void){
    float a,b,c;
    float ar, per;
    printf("I check a triangle and then i will calculate the area\n");
    printf("First:\n");
    scanf("%f", &a);
    printf("Second:\n");
    scanf("%f", &b);
    printf("Third:\n");
    scanf("%f", &c);

    switch(check(a,b,c)){
        case 0:{
            calculate(a, b, c, &ar, &per);
            printf("area: %f\n", ar);
            printf("peri: %f\n", per);
            break;
        }
        case 1:{
            printf("Trianglo non valido\n");
            break;
        }
        case 2:{
            printf("Trianglo degenere\n");
            break;
        }
    }
}