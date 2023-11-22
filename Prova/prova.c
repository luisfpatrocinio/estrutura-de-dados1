#include <stdio.h>
#include <string.h>

// Prova 4
struct livro {
    int cod;
    char nome[20];
};

typedef struct livro Tlivro;
Tlivro livros[5];
int ultimo = 0;
//inserir o novo elemento no inicio da lista
// Se necessários os elementos devem ser reorganizados na lista:
// Ex.: lista = [] ---> inserir 10 -----> lista = [10]
// inserir 12 ----------------> lista = [12,10]
// inserir 7 -----------------> lista = [7,12,10]

void inserirInicio(Tlivro novo){
    if (ultimo < 5) {
        // Complete aqui.
        // Percorre a lista do final para o começo, "empurrando" para a direita.
        for (int i = ultimo; i > 0; i--) {
            livros[i] = livros[i-1];
        }
        livros[0] = novo;
        ultimo++;
    } else {
        printf("\nBiblioteca lotada!!!");
    }
}

//inserir o novo elemento no final da lista
void inserirNoFinal(Tlivro novo){
    if (ultimo < 5) {
        // Completar aqui
        livros[ultimo] = novo;
        ultimo++;
    } else {
        printf("\nBiblioteca lotada!!!");
    }
}

//A função deve retornar a posição do código procurado
//Se não encontrar a função deve retornar -1
int buscar(int codigo) {
    int p = -1;
    //Complete aqui
    // Percorrer a lista procurando o código.
    for (int i = 0; i < ultimo; i++) {
        if (livros[i].cod == codigo) {
            p = i;
            break;
        }
    }
    return p;
}

void mostra() {
    printf("\nMostrando os livros da biblioteca:\n");
    for (int i = 0; i < ultimo; i++) {
        printf("\n# Codigo do livro: %d", livros[i].cod);
        printf("\nNome do livro: %s", livros[i].nome);
    }

}

int main() {
    // Cadastre os elementos no inicio da lista:
    // (8,"Aprendendo a programar em C")
    // (10,"Aprendendo a Programar em Python")
    // (12,"Estrutura de Dados 2")
    // (13,"Matemática Aplicada")
    inserirInicio((Tlivro){8, "Aprendendo C"});
    inserirInicio((Tlivro){10, "Aprendendo Python"});
    inserirInicio((Tlivro){12, "Estrutura de Dados"});
    inserirInicio((Tlivro){13, "Matematica Aplicada"});
    inserirNoFinal((Tlivro){5, "Livro Final"});

    // Procure na lista o elemento de codigo 12
    int pos = buscar(12);
    // mostre o resultado
    printf("\nPosicao do livro de codigo 12: %d", pos);
    
    // Procure na lista o elemento de codigo 20
    pos = buscar(20);
    // mostre o resultado
    printf("\nPosicao do livro de codigo 20: %d", pos);

    //Mostre os elementos da lista
    mostra();

    printf("\n= FIM DO PROGRAMA =\n");
}