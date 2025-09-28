#include<iostream> using namespace std; 
struct Vertice { 
    int valor; 
    // Carga útil 
    int altura; 
    int fb; 
    Vertice *esq; 
    Vertice *dir; 
    // Construtor 
    Vertice(int v): esq{nullptr}, dir{nullptr}, valor{v},altura{0},fb{0} {} 
}; 
    class Avl { 
        // Encapsula toda a lógica! 
    public:
         Avl(): raiz{nullptr}{} 
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
            cout << endl;
        } 
    private: 
        Vertice *raiz; 

        int altura(Vertice *v) { 
            return v ? v->altura : 0; 
        } 
        int fator_bal(Vertice *v) { 
            return v ? altura(v->esq) - altura(v->dir) : 0; 
        } 
        int profundidade(Vertice *v) { 
            return 0; 
        } 
        Vertice* min(Vertice *v) { 
            return nullptr; 
        }
        
        
        void atualiza_altura(Vertice *v) {
        v->altura = 1 + max(altura(v->esq), altura(v->dir));
        }

        Vertice* rot_dir(Vertice *y) {
        Vertice *x = y->esq;
        Vertice *T2 = x->dir;

        x->dir = y;
        y->esq = T2;

        atualiza_altura(y);
        atualiza_altura(x);

        return x;
        }


        Vertice *rot_esq(Vertice *v) { 
           Vertice *y = x->dir;
            Vertice *T2 = y->esq;

            y->esq = x;
            x->dir = T2;

            atualiza_altura(x);
            atualiza_altura(y);

            return y; 
        } 

        Vertice *rot_dir(Vertice *v) { 
            Vertice *x = y->esq;
            Vertice *T2 = x->dir;

            x->dir = y;
            y->esq = T2;

            atualiza_altura(y);
            atualiza_altura(x);

            return x;
        } 
        
        Vertice* balancear(Vertice *v) {
        atualiza_altura(v);
        int fb = fator_bal(v);

        if (fb > 1 && fator_bal(v->esq) >= 0)
            return rot_dir(v);

        if (fb > 1 && fator_bal(v->esq) < 0) {
            v->esq = rot_esq(v->esq);
            return rot_dir(v);
        }

        if (fb < -1 && fator_bal(v->dir) <= 0)
            return rot_esq(v);

        if (fb < -1 && fator_bal(v->dir) > 0) {
            v->dir = rot_dir(v->dir);
            return rot_esq(v);
        }

        return v;
        }


        Vertice* insere(Vertice *v, int valor) {
            if (!v) return new Vertice(valor);

            if (valor < v->valor)
                v->esq = insere(v->esq, valor);
            else if (valor > v->valor)
                v->dir = insere(v->dir, valor);
            else
                return v;

            return balancear(v);
        }

        Vertice* min(Vertice *v) {
            while (v->esq) v = v->esq;
            return v;
        }



        Vertice* remove(Vertice *v, int valor) {
             if (v == nullptr)
              return v; 
            if (valor < v->valor){ 
                v->esq = remove(v->esq, valor); 
            } else if (valor > v->valor){ v
                ->dir = remove(v->dir, valor);
            } else{
            if (!v->esq || !v->dir) {
                Vertice *temp = v->esq ? v->esq : v->dir;
                if (!temp) {
                    temp = v;
                    v = nullptr;
                } else {
                    *v = *temp;
                }
                delete temp;
            } else {
                Vertice *temp = min(v->dir);
                v->valor = temp->valor;
                v->dir = remove(v->dir, temp->valor);
            }
        }

        if (!v) return v;
        return balancear(v); 
    } 
    void imprime(Vertice* v) { 
        if (v == nullptr) return; 
        cout << v->valor << endl; 
        imprime(v->esq); 
        imprime(v->dir); 
    } 

using namespace std; 
int main() {
     Avl t; 
     //RVO ou NRVO Avl 
     *tt = new Avl();
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