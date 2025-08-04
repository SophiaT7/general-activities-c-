#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

int buscaSequencial(const std::vector<int>& vetor, int chave) {
    for (int i = 0; i < vetor.size(); ++i) {
        if (vetor[i] == chave) return i;
    }
    return -1;
}

int buscaBinaria(const std::vector<int>& vetor, int chave) {
    int inicio = 0;
    int fim = vetor.size() - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] == chave) return meio;
        else if (chave < vetor[meio]) fim = meio - 1;
        else inicio = meio + 1;
    }

    return -1;
}

std::vector<int> gerarVetor(int n) {
    std::vector<int> vetor(n);
    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(0, n * 10);

    for (int i = 0; i < n; ++i) {
        vetor[i] = dist(rng);
    }

    return vetor;
}

int main() {
    std::vector<int> tam = {100, 1000, 10000, 100000, 1000000, 10000000};

    for (int n : tam) {
        std::cout << "tamanho do vetor: " << n << "\n";

        std::vector<int> vetor = gerarVetor(n);

        int chaveSeq = vetor[n - 1];

        auto inicio = std::chrono::high_resolution_clock::now();
        buscaSequencial(vetor, chaveSeq);
        auto fim = std::chrono::high_resolution_clock::now();
        auto tempoSeq = std::chrono::duration<double, std::milli>(fim - inicio).count();

        std::cout << "Tempo busca sequencial: " << tempoSeq << " ms\n";

        std::sort(vetor.begin(), vetor.end());

        int chaveBin = -1;

        inicio = std::chrono::high_resolution_clock::now();
        buscaBinaria(vetor, chaveBin);
        fim = std::chrono::high_resolution_clock::now();
        auto tempoBin = std::chrono::duration<double, std::milli>(fim - inicio).count();

        std::cout << "tempo: " << tempoBin << " ms\n";
    }
    return 0;
}
