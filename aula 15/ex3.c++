#include <iostream>
#include <vector>
#include <algorithm>

void insertionSort(std::vector<float>& bucket) {
    for (int i = 1; i < bucket.size(); ++i) {//comeca do segundo elemento (1) e vai ate o final
        float key = bucket[i];//guarda valor em chave
        int j = i - 1;//indice anterior
        while (j >= 0 && bucket[j] > key) {//enquanto key < bucket[j] desloca os valores amiores a frente
            bucket[j + 1] = bucket[j];//valor anterior v pra frente
            --j;//decrementa o indice anterior (a eaquerda)
        }
        bucket[j + 1] = key;//insere esse valo na posicao correta
    }
}

void bucketSort(std::vector<float>& arr) {
    int n = arr.size();//guarda tamanho do vetor
    std::vector<std::vector<float>> buckets(n);//cria n buckets

    //coloca cada valor no bucket certo
    for (float val : arr) {//para cada valor calcula indice do bucket com base na pos inicial
        int idx = val * n;//idx eh o indice do bucket
        if (idx == n) idx = n - 1; // garante que 1.0 caia no último bucket
        buckets[idx].push_back(val);//coloca o valor no bucket
    }

    for (auto& bucket : buckets)//p cada bucket realiza um insertion sort
        insertionSort(bucket);


    int idx = 0;
    for (auto& bucket : buckets) {//para cada valor de cada bucket insere o valor e avanca no indice
        for (float val : bucket)
            arr[idx++] = val;
    }
}
