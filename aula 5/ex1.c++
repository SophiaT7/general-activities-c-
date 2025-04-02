#include <iostream>

struct Lista{
	int dado;
	Lista* next;

	Lista(int valor): dado(valor), next(nullptr) {}
};

class Link{
	Lista* head;
	Lista* tail;

public:
	Link():head(nullptr), tail(nullptr) {}

	void InsertStart(int valor){
		Lista* begin = new Lista(valor);
		begin->next=head;
		head=begin;
		if(tail==nullptr){
			tail=begin;
		}
	}

	void reverse(){
		Lista* prev=nullptr;
		Lista* atual=head;
		Lista* next=nullptr;

		while(atual){
			next=atual->next; //prox recebe ptr do prox
			atual->next=prev; // prox recebe o anterior
			prev=atual;// anterior recebe atual
			atual=next;//atual recebe prox
		}
		head=prev;
	}

	void mostra(){
		Lista* aux=head;
		while(aux){
			std::cout<<aux->dado<<",";
			aux=aux->next;
		}
	}
};

int main(){
	Link list;
    list.InsertStart(5);
    list.InsertStart(4);
    list.InsertStart(3);

	std::cout<<"lista:";
	list.mostra();

	list.reverse();

	std::cout<<"lista reversa";
	list.mostra();

	return 0;
}
