#include<stdio.h>
#include<math.h>

#define f1(x, y, z)(17 - y + 2 * z) / 20
#define f2(x, y, z)(-18 - 3 * x + z) / 20
#define f3(x, y, z)(25 - 2 * x + 3 * y) / 20

void jacob(int e){
  float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3;
  int count = 1;
  printf("\nCount\tx\ty\tz\n");
  do {
    x1 = f1(x0, y0, z0);
    y1 = f2(x0, y0, z0);
    z1 = f3(x0, y0, z0);
    printf("%d\t%0.4f\t%0.4f\t%0.4f\n", count, x1, y1, z1);
    e1 = fabs(x0 - x1);
    e2 = fabs(y0 - y1);
    e3 = fabs(z0 - z1);

    count++;

    x0 = x1;
    y0 = y1;
    z0 = z1;

  } while (e1 > e && e2 > e && e3 > e);

  printf("\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n\n", x1, y1, z1);
}

void seidel(int e){
  float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3;
  int count = 1;

  printf("\nCount\tx\ty\tz\n");
  do {
    x1 = f1(x0, y0, z0);
    y1 = f2(x1, y0, z0);
    z1 = f3(x1, y1, z0);
    printf("%d\t%0.4f\t%0.4f\t%0.4f\n", count, x1, y1, z1);
    e1 = fabs(x0 - x1);
    e2 = fabs(y0 - y1);
    e3 = fabs(z0 - z1);

    count++;

    x0 = x1;
    y0 = y1;
    z0 = z1;

  } while (e1 > e && e2 > e && e3 > e);

  printf("\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n\n", x1, y1, z1);
}

int main() {
  float e;
  printf("\n\n==========================================================\n");
  printf("Name: Saugat Maharjan\n");
  printf("Roll.No: 17\n");
  printf("4.3) Jacobi Iteration and Gauss Seidel Method\n");
  printf("==========================================================\n");
  printf("Enter tolerable error:\n");
  scanf("%f", &e);
  printf("\nJacob Iteration:\n");
  jacob(e);
  printf("\nGauss Seidel Iteration:\n");
  seidel(e);
  return 0;
}
