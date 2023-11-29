#include <stdio.h>
#define SIZE 100

int main()
{
	float x[SIZE], y[SIZE], q, p=0, l;
	int n;
	printf("\n\n==========================================================\n");
	printf("Name: Saugat Maharjan\n");
	printf("Roll.No: 17\n");
	printf("2.1) Lagrange Interpolation\n");
	printf("==========================================================\n");

	printf("Enter number of data: ");
	scanf("%d", &n);
	
	for(int i=0;i<n;i++)
	{
		printf("x[%d] = ", i);
		scanf("%f", &x[i]);
		printf("f[%d] = ", i);
		scanf("%f", &y[i]);
	}
	 
	printf("Enter the interpolation point: ");
	scanf("%f", &q);

	for(int i=0;i<n;i++)
	{
		l=1;
		for(int j=0;j<n;j++)
		{
			if(i!=j)
			{
				l = l * (q - x[j])/(x[i] - x[j]);
			}
		}
		p = p + l * y[i];
	}

	printf("Interpolated value at %.3f is %.5f.\n\n\n", q, p);
	return 0;
}
