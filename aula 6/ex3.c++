#include <iostream>
#include <stack>

bool balanceado(const std::string& str){// const ela nao sera modificada/& passado por ref usandp string original == string esta sendo passada por referencia
	std::stack<char> s;
	for(int i=0;i<str.length();i++){
		char ch=str[i];//procurar e seguir os if's
		if(ch == '('||ch=='{'||ch=='['){
			s.push(ch);// vai inserir tais caracteres ate que se encontre os que fecham ela atravez do pop/ empurra os caractres(pilha-LIFO)
		}else{
			if(s.empty()){
				return false;
			}
			char top=s.top(); //pega elemento do topo
			if( (ch == ')' && top == '(') ||
				(ch == '}' && top == '{') ||
				(ch == ']' && top == '[')) { // se algum desses casos forem atendidos ele desempilha um a um
				s.pop();
			}else{ // se nao estiver de acordo retorna false
				return false;
			}
		}
	}
	return s.empty(); // ate q esteja vazia
}

int main(){
	std::string exp1="{[()]}";
	std::string exp2="{[(])}";

	std::cout<<exp1<<"--"<<(balanceado(exp1)? "balanceado":"n esta balanceado")<<std::endl;
	std::cout<<exp2<<"--"<<(balanceado(exp2)? "balanceado":"n esta balanceado")<<std::endl;

	return 0;
}
