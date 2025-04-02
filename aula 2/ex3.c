#include <stdio.h>

int main(){
	int vet[5];
	int max;
	int min;
	int soma =0;
	int acMedia = 0;

	printf("de os valroes");

	for(int i=0;i<5;i++){
		scanf("%d", &vet[i]);
		soma+=vet[i];
	}

	max = min = vet[0]; // eh necessario realizar isso ja que os valores podem pegar lixo de memoria e ultrapassar do fim da arrey

	for(int i=0;i<5;i++){
		if(vet[i]>max){
			max = vet[i];
		}
		if(vet[i]<min){
			min = vet[i];
		}
	}

	int media = soma/5;

	for(int i=0;i<5;i++){
		if(vet[i]>media){
			acMedia++;
		}
	}

	printf("valor media %d\n", media);
	printf("valor min e max: %d, %d \n", min, max );
	printf("valor acima da media: %d", acMedia);
}
