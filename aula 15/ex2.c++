#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void countingSortDigit(std::vector<int>& arr, int exp) {
    const int base = 10;
    std::vector<int> output(arr.size());
    int count[base] = {0};

    for (int num : arr)
        count[(num / exp) % base]++;

    for (int i = 1; i < base; i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % base;
        output[--count[digit]] = arr[i];
    }

    arr = output;
}

void radixSort(std::vector<int>& arr) {
    int max_val = *std::max_element(arr.begin(), arr.end());

    for (int exp = 1; max_val / exp > 0; exp *= 10)
        countingSortDigit(arr, exp);
}
