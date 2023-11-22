#include <stdio.h>
#include <stdlib.h>

// Estrutura de Lista
typedef struct ListaStruct {
    int item;
    struct ListaStruct *prox;
} Lista;

// Construtor de nó
Lista* no(int item, Lista *prox) {
    Lista *nova_lista = (Lista*)malloc(sizeof(Lista));
    nova_lista->item = item;
    nova_lista->prox = prox;
    return nova_lista;
}

// Função para exibir inversa.
void exibe_inv(Lista* lista) {
    if (lista == NULL) return;
    exibe_inv(lista->prox);
    printf("%d - ", lista->item);
}

// Função para criar um novo nó.
int main(void) {
    Lista* L = no(3, no(1, no(5, NULL)));
    exibe_inv(L);
    return 0;
}
