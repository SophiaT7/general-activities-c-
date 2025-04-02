#include <iostream>

struct No{
	int dado;
	No* next;
	No* prev;

	No(int valor): dado(valor), next(nullptr), prev(nullptr){}
};

class Lista{
	No* head;
	No* tail;

public:

	Lista(): head(nullptr), tail(nullptr){}

	void push(int valor){
		No* begin=new No(valor);

		if(head==nullptr){
			head=tail=begin;//comeco recebe fim que recebeu comeco
			begin->next=begin->prev=nullptr; //ptr de prox recebe ptr de anterior q recebeu comeco/ formando um ciclo
		}else{
			begin->next = head;
			begin->prev = nullptr;
			head->prev = begin;
			head=begin;
		}
	}

	void excluir(){
		No* atual=head;
		while(atual!=nullptr){
			No* temp=atual;
			atual= atual->next;
			delete temp;
		}
		head=nullptr;
		tail=nullptr;
	}
	void print() {
        No* temp = head;
        while (temp != nullptr) {
            std::cout << temp->dado << " , ";
            temp = temp->next;
        }
		std::cout << "NULL" << std::endl;
    }

	~Lista() {
		excluir();
    }
};

int main(){
	Lista lista;

	lista.push(10);
	lista.push(20);

	std::cout <<"lista antes";
	lista.print();

	lista.excluir();

	std::cout<<"depois";
	lista.print();

	return 0;

}
