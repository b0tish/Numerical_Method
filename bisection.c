#include <stdio.h>
#include <math.h>
#define f(x) (4*x*x*x-2*x+6)
#define EPS 0.001

int main(){
  int iter = 1;
  float x1,x2,x0,f1,f2,f0;
start:

  printf("Input the two initial guesses:");
  scanf("%f%f",&x1,&x2);

  f1 = f(x1);
  f2 = f(x2);
  if (f1 * f2 > 0){
    printf("Incorrect initial guesses.\n");
    goto start;
  }
  

  printf("\nStep\t\t  x1\t\t  f(x1)\t\t   x2\t\t  f(x2)\t\t   x0\t\t  f(x0)\n");

  do{
    x0 = (x1+x2) / 2.0; 
    f0 = f(x0);
    f1 = f(x1);
    f2 = f(x2);;

    printf("%d\t\t%f\t%f\t%f\t%f\t%f\t%f\n", iter, x1, f1, x2, f2, x0, f0);

    if (f0 == 0.0)
      break;
    else if (f1 * f0 < 0){
      x2 = x0;
    }
    else{
      x1 = x0;
    }
    iter++;
  }while(fabs(f0) > EPS);
  printf("\nRoot:%f\n\n", x0);
  return 0;
  
}
