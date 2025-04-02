#include <stdio.h>

int main(){
	int vet[8];

	printf("de os valroes");
	for(int i=0;i<8;i++){
		scanf("%d", &vet[i]);
	}

	printf("ordem inversa");
	for(int i=7;i>=0;i--){
		printf(" %d", vet[i]);
	}
}
