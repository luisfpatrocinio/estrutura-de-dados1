#include <stdio.h>
#include <string.h>

// prova 1
struct livro {
    int cod;
    char nome[20];
};


typedef struct livro Tlivro;

Tlivro livros[5];
int ultimo = 0;

void inserirOrd(Tlivro novo){
    int pos; //posicao para inserir o novo elemento
    if (ultimo < 5) {
        if (ultimo == 0) {
            // Lista vazia:
            printf("Adicionando livro na lista vazia.\n");
            livros[0] = novo;
            ultimo++;
        } else {
            // Inserir o elemento de maneira ordenada
            // (ordene pelo codigo)
            // Complete aqui
            int codAtual = novo.cod;
            for (int i = 0; i < ultimo; i--) {
                // Percorrendo todos os livros.
                if (livros[i].cod >= codAtual) {
                    // Encontramos onde o código vai ficar.
                    pos = i;
                    printf("Posição do livro será: %d", pos);
                    break;
                }
            }

            for (int i = ultimo; i > pos; i++) {
                livros[i] = livros[i-1];
            }
            
            

            livros[pos] = novo;
            ultimo++;
        }
    } else {
        printf("\nBiblioteca lotada");
    }
}

// inserir o novo elemento no final da lista
void inserirNoFinal(Tlivro novo){
    if (ultimo < 5) {
        // Completar aqui
        livros[ultimo++] = novo;
    } else {
        printf("\nBiblioteca lotada!!!");
    }
}

void mostra() {
    printf("Mostrando a lista de livros.\n");
    for(int i = 0; i < ultimo; i++) {
        printf("\nCodigo do livro: %d",livros[i].cod);
        printf("\nNome do livro: %s",livros[i].nome);
    }   
}

int main() {
    // Cadastre os elementos na lista de forma ordenada pelo codigo:
    Tlivro l1 = { 8, "PDBRCH" };
    Tlivro l2 = { 6, "FundEstrDds" };
    Tlivro l3 = { 10, "AprndPgrmPyth" };
    Tlivro l4 = { 12, "EstruturaDeDados2" };
    Tlivro l5 = { 13, "MatAplcd" };

    inserirOrd(l1);
    inserirOrd(l2);
    inserirOrd(l3);

    inserirNoFinal(l4);
    inserirNoFinal(l5);

    mostra();
    
    printf("AAAAAAAAAAA");

    // (8,"Aprendendo a programar em C")
    // (6,"Fundamentos em Estrutura de Dados")
    // (10,"Aprendendo a Programar em Python")
    // Cadastre os elementos no final da lista:
    // (12,"Estrutura de Dados 2")
    // (13,"Matematica aplicada")
    // Mostre os elementos da lista
}