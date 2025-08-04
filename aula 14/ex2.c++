#include <iostream>
#include <vector>
//3)
int buscaBinariaString(const std::vector<std::string>& vetor, const std::string& chave) {
    int inicio = 0;
    int fim = vetor.size() - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (vetor[meio] == chave)
            return meio;
        else if (chave < vetor[meio])
            fim = meio - 1; // esquerda
        else
            inicio = meio + 1; // direita
    }
    return -1;
}

//4)
int ternaria(const std::vector<int>& vetor, int chave) {
    int inicio = 0;
    int fim = vetor.size() - 1;

    while (inicio <= fim) {
        int terco1 = inicio + (fim - inicio) / 3;
        int terco2 = fim - (fim - inicio) / 3;

        if (vetor[terco1] == chave)
            return terco1;
        else if (vetor[terco2] == chave)
            return terco2;

        if (chave < vetor[terco1])
            fim = terco1 - 1; // primeiro terço
        else if (chave > vetor[terco2])
            inicio = terco2 + 1; //terceiro terço
        else
            inicio = terco1 + 1, fim = terco2 - 1; // terço do meio
	}
    return -1;
}
