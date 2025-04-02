#include <stdio.h>

int main() {
    int matriz1[2][2], matriz2[2][2], resultado[2][2];

    printf("de os elementos matriz 2x2");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }

    printf("de os elementos da segunda matriz 2x2");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    printf("resultado");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", resultado[i][j]);
        }
    }

    return 0;
}
