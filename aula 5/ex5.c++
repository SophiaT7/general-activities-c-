/* Na lista crcular o ultimo aponta para o primeiro e o primeiro deve levar ao ultimo nó.
Insercao: nó ao final deve apontar para o primeiro e nao para nullptr;
Remocao: removendo o ultimo nó, o penultimo aponta para o primeiro;

No* aux=head;
if(head->==head){
delete head;
head=nullptr;
}else{
while(aux->next!=head){
aux=aux->next;
}
No* primeiro=head;
head=head->next;
aux->next=head; ultimo/penultimo vai apontar p o comeco
delete primeiro;

Lista Dupla Circular
ultimo no aponta para o primeiro e o primeiro aponte para o ultimo
e o ptr anterior do primeiro seja o ultimo

Insercao:insere no ao fim, o ultimo deve apontar p o primeiro no (ultimo->primeiro)
e o primeiro deve apontar p o ultimo(primeiro->ultimo);
Remocao: remove o ultimo, o penultimo tem ptr (penultimo = next->primeiro = prev->penultimo);

inserindo...

void push(int valor) {
        No* novo = new No(valor);

        if (head == nullptr) {
            head = tail = novo;
            novo->next = novo->prev = novo;  o no aponta p ele mesmo
        } else {
            novo->next = head;   prox recebe head
            novo->prev = tail;   anterior recebe o fim
            head->prev = novo;   anterior recebe o novo que eh o prox e o ante ao mesmo tempo (atual?)
            tail->next = novo;   prox recebe novo
            head = novo;   o novo no se torna o head e assim ele fica circular
        }
    }
}

Removendo...
    void excluir() {
        if (head == nullptr) return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            No* temp = head;
            head = head->next;  head recebe ptr do prox
            head->prev = tail;  anterior ecebe o fim pois e circular, prev/ant sera o penultimo
            tail->next = head;  prox recebe o head e se torna o primeiro
            delete temp;  exclui head
        }
    }
*/
