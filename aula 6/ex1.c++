#include <iostream>
#include <stack>

struct Pilha{
	int dado;
	Pilha* next;
};

class Stack{
	Pilha* top;

public:
	Stack():top(nullptr){}

	void push(int valor){
		Pilha* new_pilha=new Pilha;
		new_pilha->dado=valor;
		new_pilha->next=top;
		top=new_pilha;
	}

	int pop(){
		if(isEmpty()){
			exit(1);
		}
		Pilha* aux=top;
		int valor=aux->dado;
		top=top->next;
		delete aux;
		return valor;
	}

	bool isEmpty(){
		return top==nullptr;
	}

	void mostra(){
		Pilha* aux=top;
		while(aux){
			std::cout<<aux->dado<<" ";
			aux=aux->next;
		}
		std::cout<<std::endl;
	}

	void inverte(){
		Stack aux; // cria um auxiliar p armazenar os invertidos e se a pilha inicial n estiver vazia remove o elemento do top com o pop e empilha com push na aux
		while(!isEmpty()){//entao ele acessa push, topo , e bota o pop(ultimo) no topo
			aux.push(pop());
		}
		*this=aux;
	}
};

int main(){
	Stack s;

	s.push(1);
	s.push(2);

	std::cout<<"original pilha";
	s.mostra();

	s.inverte();
	std::cout <<"Pop"<<s.pop()<<std::endl;
	s.mostra();

	return 0;
}
