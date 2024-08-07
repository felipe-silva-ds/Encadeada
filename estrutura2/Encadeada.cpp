#include <iostream>

using namespace std;

class No {
    public:
        int valor;
        No *next;

        No() : valor(0), next(nullptr) {}
        No(int valor) : valor(valor), next(nullptr) {}
        No(int valor, No *next) : valor(valor), next(next) {}

};

class LinkedList {
    private:
        No *head;
        int tamanho;

    public:

        LinkedList() : head(nullptr), tamanho(0) {}

        void printarLista() {
            No *atual = head;
            cout << "[ ";
            while (atual != nullptr) {
                cout << atual->valor << ", ";
                atual = atual->next;
            }
            cout << "]" << endl;
        }


        bool estaVazia() {
            return head == nullptr;            
        }

        int obterTamanho() {
            return tamanho;
        }

        int recuperarValor(int pos) {
            if (pos < 1 || pos > tamanho) {
                cerr << "Acesso invalido de recuperação." << endl;
                return -1;
            }
            No *atual = head;
            for (int i = 1; i < pos; i++) {
                atual = atual->next;
            }
            return atual->valor;
        }


        void modificarValor(int valor, int pos) {
            if (pos < 1 || pos > tamanho) {
                cerr << "Tentativa de modificaçao negada" << endl;
                return;
            }
            No *atual = head;
            for (int i = 1; i < pos; i++) {
                atual = atual->next;
            }
            atual->valor = valor;
        }

        void inserirValor(int valor, int pos) {
            if (pos < 1 || pos > tamanho + 1) {
                cerr << "Tentativa de adicionar invalida." << endl;
                return;
            }
            No *novoNo = new No(valor);
            if (pos == 1) {
                novoNo->next = head;
                head = novoNo;
            } else {
                No *anterior = head;
                for (int i = 1; i < pos - 1; i++) {
                    anterior = anterior->next;
                }
                novoNo->next = anterior->next;
                anterior->next = novoNo;
            }
            tamanho++;
        }


        void removerElemento(int pos) {
            if (pos < 1 || pos > tamanho) {
                cerr << "Tentativa de remoção de fora da lista." << endl;
                return;
            }
            No *remover;
            if (pos == 1) {
                remover = head;
                head = head->next;
            } else {
                No *anterior = head;
                for (int i = 1; i < pos - 1; i++) {
                    anterior = anterior->next;
                }
                remover = anterior->next;
                anterior->next = remover->next;
            }
            delete remover;
            tamanho--;
        }

        
};

int main() {


    LinkedList lista = LinkedList();

    lista.printarLista();

    cout << "lista está vazia? " << lista.estaVazia() << endl;

    cout << "Inserindo os valores 15,4,2 nas posições 1, 2 e 3" << endl;

    lista.inserirValor(15, 1);
    lista.inserirValor(4, 2);
    lista.inserirValor(2, 3);

    lista.printarLista();

    cout << "Lista está vazia?  (0 se não, 1 se sim) " << lista.estaVazia() << endl;

    cout << "Tam: " << lista.obterTamanho() << endl;

    cout << "Obtendo o valor do elemento de uma pos aleatoria(1): " << lista.recuperarValor(1) << endl;

    cout << "Modificando o elemento na posição 2" << endl;

    lista.modificarValor(23, 2);

    lista.printarLista();

    cout << "Retirando o elemento na posição 1: " << endl;

    lista.removerElemento(1);

    lista.printarLista();


   
    return 0;
}