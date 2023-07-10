#include <stdio.h>
#include<math.h>
#define EPS 0.01 
#define f(x) x*x*x-3*x-2 
#define fd(x) 2*x-3 
int main(){
    int count = 1;
    float x0, xn, fx, fdx, error;

    printf("Input initial value of x:");
    scanf("%f", &x0);
    printf("\nIter\t   x0 \t          f(x0)\t           f'(x0) \t   Error\n");
    do{
        fx = f(x0);
        fdx= fd(x0);
        xn = x0 - fx/fdx; 
        error= fabs((xn - x0) / xn);
        printf("%d\t %f \t %f \t %f \t %f\n", count,x0, fx,fdx, error);
        x0 = xn;
        count++;
    }while(error > EPS);
    printf("Root = %f\n\n", xn);
    return 0;
}
