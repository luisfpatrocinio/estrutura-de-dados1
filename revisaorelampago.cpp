// Lista Estática.

#include <iostream>

using namespace std;

// Tamanho máximo da lista estátia:
#define MAX_SIZE 10

// Tipo de dado armazenado na lista:
typedef struct pessoa {
    string nome;
    int idade;
} Pessoa;

// Lista estática:
Pessoa lista[MAX_SIZE];
int tamanho = 0;

// Função para incluir elementos no início da lista.
void incluirNoInicio(Pessoa *pessoa) {
    if (tamanho >= MAX_SIZE) {
        printf("Lista cheia!");
        return;
    }
    for (int i = tamanho; i > 0; i--) {
        lista[i] = lista[i - 1];
    }
    tamanho++;
}
