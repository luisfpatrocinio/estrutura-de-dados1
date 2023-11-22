#include <iostream>

using namespace std;

#define VALOR_ERRO -7777;

class Pilha {
    public:
        int MAX_SIZE;
        int *dados;
        int topo = -1;

        Pilha(int tamanho) {
            MAX_SIZE = tamanho;
            dados = new int[MAX_SIZE];
        }
    
        bool isEmpty() {
            return topo == -1;
        }

        void push(int elemento) {
            if (topo < MAX_SIZE - 1) {
                dados[++topo] = elemento;
                cout << "Elemento " << elemento << " adicionado à pilha." << endl;
            } else {
                cout << "Erro: Pilha cheia. Não é possível adicionar mais elementos." << endl;
            }
        }

        int pop() {
            if (!isEmpty()) {
                int valorRemovido = dados[topo];
                cout << "Removendo elemento " << valorRemovido << " da pilha." << endl;
                topo--;
                return valorRemovido;
            } else {
                cout << "Erro: Pilha vazia. Não é possível remover elementos." << endl;
                return VALOR_ERRO;
            }
        }

        int getTop() {
            if (!isEmpty()) {
                return dados[topo];
            } else {
                cout << "Erro: Pilha vazia. Não há elemento no topo." << endl;
                return -1;  // Valor padrão indicando erro.
            }
        }

        ~Pilha() {
            delete[] dados;
        }
};

void empilha(int valor, Pilha pilha) {
    pilha.push(valor);
}

int main() {
    Pilha minhaPilha = Pilha(3);
    minhaPilha.push(1);
    minhaPilha.push(2);
    cout << minhaPilha.pop() << endl;
}