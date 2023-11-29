#include <stdio.h>
#include <math.h>
#define f(x) x*x-5*x+6
#define EPS 0.0001

int main(){
  int iter = 1;
  float x1,x2,x3,e,f1,f2; 
  printf("\nInput the two initial guesses:");
  scanf("%f%f",&x1,&x2);

  printf("\nStep\t\t   x1\t\t   f(x1)\t\t   x2\t\t           f(x2)\t\t   x3\t\t          Error\n");
  
  do{
    f1 = f(x1);
    f2 = f(x2);
    x3 = x2 - ((f2*(x2-x1)) / (f2-f1));
    e = fabs((x3 - x2) / x3);

    printf("%d\t\t%f\t%f\t\t%f\t\t%f\t\t%f\t\t%f\n",iter,x1,f1,x2,f2,x3,e);
    
   x1 = x2;
    x2 = x3;
    iter++;
  }while(e > EPS);
  
  printf("\nRoot:%f\n\n\n",x3);

    return 0;
}
