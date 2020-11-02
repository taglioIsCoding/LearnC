#include<stdio.h>
#include<math.h>

int reverse(int n, int res){
    // int res = 0;
    // while(n !=0){
    //     result = result*10 + n%10;
    //     num = num/10;
    // }
    if( n == 0){
        return res;
    }else{
        return reverse(n/10, res*10 + n%10);
    }
}

int main(void){
    int n, res = 0;
    printf("Insert an int i will reverse it\n");
    scanf("%d", &n);

    res = reverse(n, res);

    printf("reverse number: %d", res);

}