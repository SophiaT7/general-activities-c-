#include <iostream>
#include <stack>

class Queue{
	private:
		std::stack<int> p1, p2; // criando duas pilhas(stack) de modo simplificado
	public:
		void enqueue(int valor){
			p1.push(valor);
		}

		int dequeue(){
			if(p1.empty()&&p2.empty()){
				exit(1);
			}
			if(p2.empty()){
				while(!p1.empty()){
					p2.push(p1.top());
					p1.pop();
				}
			}
			int valor = p2.top();
			p2.pop();
			return valor;
		}
		bool isEmpty(){
			return p1.empty()&& p2.empty();
		}
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);

    std::cout << "Dequeued: " << q.dequeue() << std::endl;// removendo um elemento

    q.enqueue(3);// enfileirando +1 elemento

    std::cout << "Dequeued: " << q.dequeue() << std::endl;// removwendo um elemento
    return 0;
}
