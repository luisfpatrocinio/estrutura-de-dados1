#include <cstdio>
#include <iostream>
#define fmt "%d"

using namespace std;

typedef int Item;
typedef struct no {
    Item item;
    struct no *prox;
} *Lista;
Lista inclue(Item x, Lista p) {
    Lista n = (Lista)malloc(sizeof(Lista));
    n->item = x;
    n->prox = p;
    return n;
}

int main() {
    Lista I = inclue(3, inclue(2, inclue(1, NULL)));
}