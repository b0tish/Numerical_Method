#include<stdio.h>

#define f(x, y) 2 * y / x
#define g(x,y) x+y

void heun() {
  float x, y, h, xn, l;
  
  printf("Enter value for x and y\n");
  scanf("%f%f", & x, & y);
  printf("Enter value for h and last of x\n");
  scanf("%f%f", & h, & xn);
  
  while (x + h <= xn) {
    l = (h / 2) * (f(x, y) + f(x + h, y + h * f(x, y)));
    y = y + l;
    x = x + h;
    printf("y = %f\tx = %f\n", y, x);
  }
}

void euler() {

  float x0, y0, xn, h, yn, slope;
  int i, n;

  printf("Enter Initial Condition\n");
  printf("x0 = ");
  scanf("%f", & x0);
  printf("y0 = ");
  scanf("%f", & y0);
  printf("Enter calculation point xn = ");
  scanf("%f", & xn);
  printf("Enter number of steps: ");
  scanf("%d", & n);

  h = (xn - x0) / n;

  printf("\nx0\ty0\tslope\tyn\n");
  printf("------------------------------\n");
  for (i = 0; i < n; i++) {
    slope = g(x0, y0);
    yn = y0 + h * slope;
    printf("%.4f\t%.4f\t%0.4f\t%.4f\n", x0, y0, slope, yn);
    y0 = yn;
    x0 = x0 + h;
  }
  printf("\nValue of y at x = %0.2f is %0.3f", xn, yn);
}

int main() {
  printf("\n\n==========================================================\n");
  printf("Name: Saugat Maharjan\n");
  printf("Roll.No: 17\n");
  printf("5.1) Euler's And Heun's Method\n");
  printf("==========================================================\n");
  printf("Heun's Method:\n\n");
  heun();
  printf("\nEuler's Method:\n\n");
  euler();
  printf("\n\n");
  return 0;
}
