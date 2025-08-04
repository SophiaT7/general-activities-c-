#include <iostream>
#include <vector>
#include <algorithm>

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

void countingSortWithNegative(std::vector<int>& arr) {// a primeira funcao so fucniona com valores positivos, portanto devemos transformar esses val neg em positivos
    if (arr.empty()) return;

    int min_val = *std::min_element(arr.begin(), arr.end());//encontra o menor valor
    int max_val = *std::max_element(arr.begin(), arr.end());//encontra maior valor do vetor
    int range = max_val - min_val + 1;// encontra quantidade de numeros diferentes entre os max e min

    std::vector<int> count(range, 0);// cria vetor count com tamanho range

    for (int num : arr)// p cada numero num e arr ha a cao p transformar os indices em positivo
        count[num - min_val]++;//se min_val = -3 e num = -3, count[0]++ ai o 3 fica positivo

    int index = 0;
    for (int i = 0; i < range; ++i) {
        while (count[i]-- > 0)
            arr[index++] = i + min_val;//0 + (-2) = -2       1 + (-2) = -1      2 + (-2) = 0     4 + (-2) = 2 e assim o vetor que antes era:{-2,-1,0,2} passa a ser {2,1,0,2}
    }
}
