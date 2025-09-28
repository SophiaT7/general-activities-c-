#include<iostream>

using namespace std;

struct Vertice {
    int valor; // Carga útil
    int altura;
    int fb;
    string cor;// cor vermelho e negro 
    Vertice *esq;//filho da esquerda
    Vertice *dir;//filho da direita
    
    // Construtor
    Vertice(int v): esq{nullptr}, dir{nullptr}, valor{v},altura{0},fb{0}, cor{"vermelho"} {}
};

class RedBlack { // Encapsula toda a lógica!

    public:

        RedBlack(): raiz{nullptr}{}

        void insere(int valor) {
            raiz = insere(raiz, valor);
        }
        
        void remove(int valor) {
            raiz = remove(raiz, valor);
        }

        bool busca(int valor) {
            return false;
        }

        void imprime() {
            imprime(raiz);
        }


    private:
        Vertice *raiz;

         Vertice* bst_insere(Vertice* raiz, Vertice* novo) {
        if (!raiz) return novo;

        if (novo->valor < raiz->valor) {//se o valor novo for inserido a partir da raiz e ele for menor que a raiz ele vai p esquerda
            raiz->esq = bst_insere(raiz->esq, novo);
            raiz->esq->pai = raiz;
        } else if (novo->valor > raiz->valor) {// e se o valor for maior que a raiz ele vai pra direita
            raiz->dir = bst_insere(raiz->dir, novo);
            raiz->dir->pai = raiz;
        }

        return raiz;
    }

        int altura(Vertice *v) {
            return 0;
        }

        int fator_bal(Vertice *v) {
            return 0;
        }

        int profundidade(Vertice *v) {
            return 0;
        }

        Vertice* min(Vertice *v) {
            return nullptr;
        }

            void rot_esq(Vertice* x) {
            Vertice* y = x->dir;
            x->dir = y->esq;
            if (y->esq) y->esq->pai = x;

            y->pai = x->pai;
            if (!x->pai) raiz = y;
            else if (x == x->pai->esq) x->pai->esq = y;
            else x->pai->dir = y;

            y->esq = x;
            x->pai = y;
            }

            void rot_dir(Vertice* y) {
            Vertice* x = y->esq;
            y->esq = x->dir;
            if (x->dir) x->dir->pai = y;

            x->pai = y->pai;
            if (!y->pai) raiz = x;
            else if (y == y->pai->esq) y->pai->esq = x;
            else y->pai->dir = x;

            x->dir = y;
            y->pai = x;
        }

        Vertice* remove(Vertice *v, int valor) {
            if (v == nullptr) return v;

            if (valor < v->valor) {
                v->esq = remove(v->esq, valor);
            }

            else if (valor > v->valor) {
                v->dir = remove(v->dir, valor);
            }

            else { // Encontrou o elemento!

                // 1. O vértice é uma folha
                if (v->esq == nullptr && v->dir == nullptr) {
                    delete v;
                    return nullptr;
                }
                
                // 2. O vértice tem 1 filho

                if (v->esq != nullptr && v->dir == nullptr) {

                }

                else if(v->esq == nullptr && v->dir != nullptr) {

                }

                else {
                    // 3. O vértice tem 2 filhos: o sucessor!
                }
                
                
            }

            return v;

        }

        void corrigir_insercao(Vertice* z) {
        while (z->pai && z->pai->cor == VERMELHO) {
            if (z->pai == z->pai->pai->esq) {
                Vertice* tio = z->pai->pai->dir;
                if (tio && tio->cor == VERMELHO) {
                    z->pai->cor = PRETO;
                    tio->cor = PRETO;
                    z->pai->pai->cor = VERMELHO;
                    z = z->pai->pai;
                } else {
                    if (z == z->pai->dir) {
                        z = z->pai;
                        rot_esq(z);
                    }
                    z->pai->cor = PRETO;
                    z->pai->pai->cor = VERMELHO;
                    rot_dir(z->pai->pai);
                }
            } else {
                Vertice* tio = z->pai->pai->esq;
                if (tio && tio->cor == VERMELHO) {
                    z->pai->cor = PRETO;
                    tio->cor = PRETO;
                    z->pai->pai->cor = VERMELHO;
                    z = z->pai->pai;
                } else {
                    if (z == z->pai->esq) {
                        z = z->pai;
                        rot_dir(z);
                    }
                    z->pai->cor = PRETO;
                    z->pai->pai->cor = VERMELHO;
                    rot_esq(z->pai->pai);
                }
            }
        }
        raiz->cor = PRETO;
    }

        void imprime(Vertice* v) {
            if (v == nullptr) return;

            cout << v->valor << endl;

            imprime(v->esq);
            imprime(v->dir);
        }

};

using namespace std;

int main() {

    RedBlack t; //RVO ou NRVO

    RedBlack *tt = new RedBlack();

    tt->insere(500);
    (*tt).insere(500);

    t.insere(100);
    t.insere(50);
    t.insere(200);
    t.insere(30);
    t.insere(60);
    t.insere(55);

    t.remove(55);
    t.remove(50);

    t.imprime();


    return 0;
}