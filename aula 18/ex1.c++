#include <iostream>
#include <vector>
using namespace std;

void siftUp(vector<int>& heap, int index) {
    if (index == 0) return; // chega na raiz
    int parentIndex = (index - 1) / 2;//descobrir quem eh o pai

    // se o filho é menor que o pai, troca
    if (heap[index] < heap[parentIndex]) {
        swap(heap[index], heap[parentIndex]);
        siftUp(heap, parentIndex);
    }
}

void insert(vector<int>& heap, int value) {// insere novo num no heap
    heap.push_back(value); // adiciona no final
    siftUp(heap, heap.size() - 1); // reorganiza com siftUp
}

void siftDown(vector<int>& heap, int index) {//p quando tiramos o menor do topo e colocamos outro no topo
    int leftChild = 2 * index + 1;//se estiver fora de ordem precisamos jogar p baixo se estiver fora de ordem
    int rightChild = 2 * index + 2;//calcula onde estao os filhos
    int smallest = index;//numero atual eh o menor

    // encontra o menor entre pai, filho esquerdo e direito
    if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
        smallest = leftChild;
    }
    if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
        smallest = rightChild;
    }

    // se  algum filho for menor, troca de lugar com ele
    if (smallest != index) {//continua empurrando pra baixo com o siftDown de novo
        swap(heap[index], heap[smallest]);
        siftDown(heap, smallest);
    }
}
