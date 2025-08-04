#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void siftUp(int index) {
        if (index == 0) return;
        int parentIndex = (index - 1) / 2;
        if (heap[index] < heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            siftUp(parentIndex);
        }
    }

    void siftDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest])
            smallest = leftChild;
        if (rightChild < heap.size() && heap[rightChild] < heap[smallest])
            smallest = rightChild;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            siftDown(smallest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    int getMin() const {
        if (heap.empty())
            throw runtime_error("Heap vazia!");
        return heap[0];
    }

    int extractMin() {
        if (heap.empty())
            throw runtime_error("Heap vazia!");

        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        siftDown(0);
        return minValue;
    }

    void printHeap() const {
        cout << "Heap atual: ";
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h;
    h.insert(10);
    h.insert(4);
    h.insert(15);
    h.insert(2);
    h.insert(8);

    h.printHeap();  

    cout << "Menor elemento: " << h.getMin() << endl;

    cout << "Removendo: " << h.extractMin() << endl;
    h.printHeap();

    cout << "Removendo: " << h.extractMin() << endl;
    h.printHeap();

    return 0;
}
