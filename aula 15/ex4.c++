#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void countingSort(std::vector<int>& arr){//recebe vetor de inteiros
	if (arr.empty()) return;// se o vetor estiver vazio n faz nada

	int max_val = *std::max_element(arr.begin(), arr.end());// usa max_val p achar o maior valor no vetor a partir do inicio ate o fim, necessita de * pois retorna ponteiro p o elemento

	std::vector<int> count(max_val + 1, 0);//vetor(count) de tamanho max_value+1, conta quantas vezes o veotr sera usado p contar quantas vezes cada numero aparece e todos elementos comecam com 0

	for(int num:arr){// p cada numero (num e arr) incrementa count[num]
		count[num]++; // se arr = {2, 3, 2}, então count[2] = 2, count[3] = 1.
	}

	int index=0;
	for(int i=0; i<=max_val; ++i){// p cad valor i de index=0 eh verificado qntas vezes ele apareceu (count[i])
		while(count[i]-- > 0){ //enquanrto o vetor decrementando a cada for seja maior que 0 ai ele incrementa acresecentando o valor de i
			arr[index++]=i;// decrementando ate zerar
		}
	}
}
int main(){
	vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

	auto start = high_resolution_clock::now();

	countingSort(arr);

	auto end = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end - start);

	cout << "Vetor ordenado: ";
    for (int num : arr) {
        cout << num << " ";
    }
	std::cout << "Tempo: " << duration.count() << "ms\n";

	return 0;
}
