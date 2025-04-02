#include <stdio.h>

#define TAM 100

struct Pilha{
	int pilha[TAM];
	int topo;
};

void inicio(struct Pilha *p){
	(*p).topo = -1 ;
}

void empilha(struct Pilha *p, int elemento){
	if((*p).topo<TAM-1){
		(*p).topo++;
		(*p).pilha[(*p).topo] = elemento;
	}else{
		exit(1);
	}
}

int desempilha(struct Pilha *p){
	if((*p).topo >= 0){
		(*p).topo--;
		return (*p).pilha[(*p).topo];
	}else{
		exit(1);
	}
}

int calculos(char *op){
	struct Pilha pilha;
	inicio(&pilha);

	int i = 0;
	while (op[i]!= '\0'){
		if (op[i] == ' ') {
            i++;
            continue;
        }

		if(op[i]>='0' && op[i]<='9'){
			int num=0;
			while(op[i]>='0' && op[i]<='9'){
				num = num * 10 + (op[i]-'0');
				i++;
			}
			empilha(&pilha, num);
		}else if(op[i]=='+' || op[i]=='-' || op[i]=='*' || op[i]=='/'){
			if(pilha.topo<1){
				exit(1);
			}
			int b = desempilha(&pilha);
			int a = desempilha(&pilha);
			switch (op[i]){
				case '+': empilha(&pilha, a+b);
				break;
				case '-': empilha(&pilha, a-b);
				break;
				case '*': empilha(&pilha, a*b);
				break;
				case '/': empilha(&pilha, a/b);
				break;
			}
		}
		i++;
	}
	return desempilha(&pilha);
}

int main(){
	char expressao[] = "3 4 + 2 * 7 /"; // (3 + 4) * 2 / 7
    int resultado = calculos(expressao);
    printf("Resultado: %d\n", resultado);
    return 0;
}
