#include<stdio.h>
#define SIZE 100

int main()
{
    int n;
    float x[SIZE], y[SIZE], X=0, X2=0, Y=0, XY=0, a, b;
    printf("\n\n==========================================================\n");
    printf("Name: Saugat Maharjan\n");
    printf("Roll.No: 17\n");
    printf("2.3) Least Square Method\n");
    printf("==========================================================\n");

    printf("Enter the number of data:");
    scanf("%d", &n);
    printf("Enter data:\n");
    
    for(int i=0;i<n;i++)
    {
        printf("x[%d]=",i);
        scanf("%f", &x[i]);
        printf("y[%d]=",i);
        scanf("%f", &y[i]);
    }

    for(int i=0;i<n;i++)
    {
        X = X + x[i];
        X2 = X2 + x[i]*x[i];
        Y = Y + y[i];
        XY = XY + x[i]*y[i];
    }

    b = (n*XY-X*Y)/(n*X2-X*X);
    a = (Y - b*X)/n;
    printf("a=%0.2f and b = %0.2f",a,b);
    printf("\nEquation of best fit is: y = %0.2f + %0.2fx\n\n\n",a,b);
    return 0;
}
