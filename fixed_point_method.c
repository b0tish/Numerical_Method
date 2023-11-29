#include <stdio.h>
#include <math.h>

// #define f(x) x*x-x-1
#define g(x) 1+1/x
#define EPS 0.001

int main(){
  int iter = 1;
  float x0,xn,error;

  printf("\n=========================================\n");
  printf("Name: Saugat Maharjan\n");
  printf("Roll.No: 17\n");
  printf("1.4) Solution By Fixed Point Method\n");
  printf("=========================================\n\n");
  printf("Enter the initial value of x:");
  scanf("%f",&x0);
  
  printf("\nIter\t\t   x0\t\t\t   xn\t\t\t  Error\n");
  do{
    xn = g(x0);
    error = fabs((xn-x0)/xn);
    printf("%d\t\t%f\t\t%f\t\t%f\n",iter,x0,xn,error);
    x0 = xn;
    iter++;
  }while(error > EPS);
  printf("Root = %f\n\n", xn);
  return 0; 
}
