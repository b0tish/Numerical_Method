#include <stdio.h>
#include <math.h>

#define f(x) x*x

int main()
{
    float a, b, integration = 0.0, h, k;
    int n;
    printf("\n\n==========================================================\n");
    printf("Name: Saugat Maharjan\n");
    printf("Roll.No: 17\n");
    printf("3.2) Simpons 1/3 Rule\n");
    printf("==========================================================\n");
    printf("Enter lower limit of integration: ");
    scanf("%f", &a);
    printf("Enter upper limit of integration: ");
    scanf("%f", &b);
    printf("Enter number of sub intervals: ");
    scanf("%d", &n);

    h = (b - a) / n;

    for(int i=1; i<= n-1; i++)
    {
        k = a + i * h;
        if (i % 2 == 0){
            integration += 2 * f(k);
        }else{
            integration += 4 * f(k);
        }
    }

    integration = (integration + f(a) + f(b) ) * h / 3;
    printf("\nRequired value of integration is: %f\n", integration);
    return 0;
}
