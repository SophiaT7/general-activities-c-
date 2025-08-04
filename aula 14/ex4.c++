#include <iostream>
#include <vector>

using namespace std;

int buscaSequencial(const vector<int>& vetor, int chave) {
    int n = vetor.size();
    int lim = n * 0.05;

    for (int i = 0; i < lim; ++i) {
        if (vetor[i] == chave) return i;
    }

    for (int i = lim; i < n; ++i) {
        if (vetor[i] == chave) return i;
    }
    return -1;
}

void testarBusca(const vector<int>& vetor, int chave) {
    int pos = buscaSequencial(vetor, chave);
    if (pos != -1)
        cout << "elemento " << chave << "posição " << pos << endl;
    else
        cout << "elemento " << chave << "not found" << endl;
}

int main() {
    vector<int> dados = {
        3, 8, 1, 7, 2, 5, 9, 0, 4, 6,
        22, 45, 67, 89, 34, 12, 90, 76, 81, 55,
        100, 200, 300, 400, 500
    };

    testarBusca(dados, 3);

    testarBusca(dados, 34);

    testarBusca(dados, 999);

    return 0;
}
