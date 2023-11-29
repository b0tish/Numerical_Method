#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 100

void Cholesky_Decomposition(int matrix[][MAX], int n) {
    int lower[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int sum = 0;

            if (j == i) {
                for (int k = 0; k < j; k++)
                    sum += pow(lower[j][k], 2);
                lower[j][j] = sqrt(matrix[j][j] - sum);
            } else {
                for (int k = 0; k < j; k++)
                    sum += (lower[i][k] * lower[j][k]);
                lower[i][j] = (matrix[i][j] - sum) / lower[j][j];
            }
        }
    }

    printf("%s\t\t%s\n", "Lower Triangular", "Transpose");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%-6d\t", lower[i][j]);
        printf("\t");
        for (int j = 0; j < n; j++)
            printf("%-6d\t", lower[j][i]);
        printf("\n");
    }
}

void luDecomposition(int mat[][MAX], int n) {
    int lower[MAX][MAX], upper[MAX][MAX];
    memset(lower, 0, sizeof(lower));
    memset(upper, 0, sizeof(upper));

    for (int i = 0; i < n; i++) {
        for (int k = i; k < n; k++) {
            int sum = 0;
            for (int j = 0; j < i; j++)
                sum += (lower[i][j] * upper[j][k]);
            upper[i][k] = mat[i][k] - sum;
        }

        for (int k = i; k < n; k++) {
            if (i == k)
                lower[i][i] = 1;
            else {
                int sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (lower[k][j] * upper[j][i]);
                lower[k][i] = (mat[k][i] - sum) / upper[i][i];
            }
        }
    }

    printf("%s\t\t%s\n", "Lower Triangular", "Upper Triangular");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%-6d\t", lower[i][j]);
        printf("\t");
        for (int j = 0; j < n; j++)
            printf("%-6d\t", upper[i][j]);
        printf("\n");
    }
}

int main() {
    printf("\n\n==========================================================\n");
    printf("Name: Saugat Maharjan\n");
    printf("Roll.No: 17\n");
    printf("4.2) Dolittle And Cholesky Method\n");
    printf("==========================================================\n");
    int matrix[MAX][MAX] = {{4, 12, -16},
                            {12, 37, -43},
                            {-16, -43, 98}};
    printf("\nCholesky Decomposition:\n");
    Cholesky_Decomposition(matrix, 3);
    printf("\nLU Decomposition:\n");
    luDecomposition(matrix, 3);
    return 0;
}
