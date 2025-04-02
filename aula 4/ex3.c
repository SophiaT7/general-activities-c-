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

void remove(struct Lista *lista, int valor){
	int i=0;
	while(i<(*lista).tamanho&&(*lista).dados[i] != valor){
		i++;
	}
	for(; i<(*lista).tamanho-1; i++){
		(*lista).dados[i] = (*lista).dados[i+1];
	}
	(*lista).tamanho--;
}

int busca(struct Lista *lista, int valor){
	for(int i=0; i<(*lista).tamanho; i++){
		if((*lista).dados[i]==valor){
			return i;
		}
	}
	return -1;
}

void imprime(struct Lista *lista){
	for(int i=0; i<(*lista).tamanho; i++){
		printf("%d", (*lista).dados[i]);
	}
}

int main() {
    struct Lista lista = {{0}, 0};
    inserir(&lista, 3);
    inserir(&lista, 1);
    inserir(&lista, 4);
    inserir(&lista, 2);
    inserir(&lista, 5);
    imprimir(&lista);

	remove(&lista, 3);
	imprime(&lista);

	int posicao =  busca(&lista,4);
	printf(posicao != -1? "elemento na 4 posicao %d\n" : "elemento 4 nao found", posicao);
	
    return 0;
}
