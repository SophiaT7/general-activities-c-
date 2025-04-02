#include <stdio.h>
#include <time.h>

#define TAM 100

// linear
int linear(int v[], int n, int alvo) {
    for (int i = 0; i < n; i++) {
        if (v[i] == alvo)
            return i;
    }
}

// binario
int binario(int v[], int n, int alvo) {
    int e = 0, d = n - 1;
    while (e <= d) {
        int meio = (e + d) / 2;
        if (v[meio] == alvo)
            return meio;
        if (v[meio] < alvo)
            e = meio + 1;
        else
            d = meio - 1;
    }
}

int main() {
    int v[TAM];
    for (int i = 0; i < TAM; i++) {
        v[i] = i;
    }
    int alvo = TAM - 1;

    clock_t inicio, fim; //biblioteca time.h para medir o tempo gasto em cada busca
    double time;

    inicio = clock();
    linear(v, TAM, alvo);
    fim = clock();
    time = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("busca linear %f", time);

    inicio = clock();
    binario(v, TAM, alvo);
    fim = clock();
    time = ((double)(fim - inicio)) / CLOCKS_PER_SEC; //busca linear eh mais lenta p/ tamanhos grandes, a busca binaria eh mais eficiente
    printf("busca binaria %f", time);

    return 0;
}
