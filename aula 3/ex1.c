#include <stdio.h>

void matriz(int m, int n) {
    int *mat = (int *)malloc(m * n * sizeof(int));
    int **linhas = (int **)malloc(m * sizeof(int *));

    for (int i = 0; i < m; i++) {
        linhas[i] = mat + i * n;
    }

    int count = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            linhas[i][j] = count++;
        }
    }

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("%d", linhas[i][j]);
		}
	}

	free(linhas);
	free(mat);
}

int main() {
    int m = 3, n = 4;
    matriz(m, n);
    return 0;
}
