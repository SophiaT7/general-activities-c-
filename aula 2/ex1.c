#include <stdio.h>

int main(){
	int mat[3][4];
	int soma[4]={0};

	printf("de os valores");
	for(int i=0;i<3;i++){
		for(int j=0; j<4;j++){
			scanf("%d", &mat[i][j]);
			soma[j]+=mat[i][j];
		}
	}

	for(int i=0;i<4;i++){
		printf("coluna %d: %d", i, soma[i]);
	}
}
