#include <stdio.h>

#define MAX 10

void multiplica(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int l1, int c1, int c2) {
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void imprimir(int matriz[MAX][MAX], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int l1, c1, l2, c2;

    printf("digite as linhas e colunas da mat A");
    scanf("%d %d", &l1, &c1);

    printf("digite os elementos da matriz A");
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("digite as linhas e colunas da mat B");
    scanf("%d %d", &l2, &c2);

    printf("digites os elementos da mnatriz B");
    for (int i = 0; i < l2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    multiplicarMatrizes(A, B, C, l1, c1, c2);

    printf(" matriz resultante é:\n");
    imprimirMatriz(C, l1, c2);

    return 0;
}
