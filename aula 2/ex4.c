#include <stdio.h>

int main(){
	int vet[5];
	int repetidos [5] = {0};

	for(int i=0;i<5;i++){
		scanf("%d", &vet[i]);
	}

	for(int i=0;i<5;i++){
		for(int j=0; j<5; j++){
			if (vet[i]==vet[j]){
				repetidos[i] = vet[i];
			}
		}
	}

	printf("repetidos");
    int found = 0;
    for (int i = 0; i < 5; i++) {
        if (repetidos[i] != 0) {
            printf("%d ", repetidos[i]);
            found = 1;
        }
    }

}
