#include <iostream>
#include <vector>

// 1
std::vector<int> buscaSequencial(const std::vector<int>& vetor, int chave) {
    int temp[1000];
    int count = 0;

    for (int i = 0; i < vetor.size(); ++i) {
        if (vetor[i] == chave) {
            temp[count] = i;
            count++;
        }
    }
    std::vector<int> indices(count);
    for (int i = 0; i < count; ++i) {
        indices[i] = temp[i];
    }
    return indices;
}


// 2
int buscaBinariaInsercao(const std::vector<int>& vetor, int chave) {
    int inicio = 0;
    int fim = vetor.size() - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] == chave)
            return meio;
        else if (chave < vetor[meio])
            fim = meio - 1;
        else
            inicio = meio + 1;
    }
    return inicio;
}
