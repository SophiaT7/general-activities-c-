#include <stdio.h>

#define MAX 100

struct Lista{
	int dados[MAX];
	int tamanho;
};

void inserir(struct Lista *lista, int valor){
	if((*lista).tamanho>=MAX){
		return;
	}
	int i;
	for(i= (*lista).tamanho-1; i>=0 && (*lista).dados[i]>valor; i--){ // vai comecar a inserir values no inicio
			(*lista).dados[i+1]=(*lista).dados[i];
	}
	(*lista).dados[i+1]=valor;
	(*lista).tamanho++;
}

void imprime(struct Lista *lista){
	for(int i=0; i<(*lista).tamanho; i++){
		printf("%d", (*lista).dados[i]);
		if(i<(*lista).tamanho-1);
	}
}

int main() {
    struct Lista lista = {{0}, 0};
    inserir(&lista, 3);
    inserir(&lista, 1);
    inserir(&lista, 4);
    inserir(&lista, 2);
    inserir(&lista, 5);
    imprimir(&lista); // saida: [1, 2, 3, 4, 5]
    return 0;
}
