#include <stdio.h>
#include <time.h>

#define TAM 100


int** vet(int n){
	int**mat=(int**)malloc(n*sizeof(int*));
	for(int i=0; i<n; i++){
		mat[i]=(int*)malloc(n*sizeof(int));
	}
	return mat;
}

void liberaVet(int** mat, int n){
	for(int i=0;i<n;i++){
		free(mat[i]);
	}
	free(mat);
}

int* bloco(int n){
	return (int*)malloc(n*n*sizeof(int));
}

double acessaVet(int** mat, int n){
	clock_t inicio=clock();
	for(int i=0; i<n; i++){
		for(int j=0;j<n;j++){
			mat[i][j]++;
		}
	}
	return ((clock()-inicio))/CLOCKS_PER_SEC;
}

double acessaBloco(int* mat, int n){
	clock_t inicio=clock();
	for(int i=0; i<n; i++){
		for(int j=0;j<n;j++){
			mat[i*n+j]++;
		}
	}
	return ((clock()-inicio))/CLOCKS_PER_SEC;
}

int main(){
	int** matV= vet(TAM);
	int* matB= bloco(TAM);

	double tV= acessaVet(matV, TAM);
	double tB= acessaBloco(matB, TAM);

	printf("Tempo do vetor de vetores): %fs\n", tV);
    printf("Tempo do bloco: %fs\n", tB);

    liberar_vetor_de_vetores(matV, TAM);
    free(matB);

    return 0;
}
