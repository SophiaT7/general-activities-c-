#include <iostream>
#include <vector>

struct Par {
    int chave;
    char valor;
};

void printArray(const std::vector<Par>& arr) {
    for (const Par& p : arr) {
        std::cout << "(" << p.chave << ", '" << p.valor << "') ";
    }
    std::cout << std::endl;
}

void selectionSort(std::vector<Par>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j].chave < arr[minIdx].chave)
                minIdx = j;
        if (minIdx != i) {
            Par temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

void insertionSort(std::vector<Par>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        Par chave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].chave > chave.chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}
