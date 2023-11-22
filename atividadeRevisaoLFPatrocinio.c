#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int cod;
    char nome[20];
} No;

int pos = 0;    // Qnt de elementos em "vetor".
No vetor[10];

void incluir(No novo) {
    vetor[pos] = novo;
    pos++;
}

int procura(int mat) {
    int i = 0;
    while (i < pos) {
        if (vetor[i].cod == mat) {
            return i;
        }
        i++;
    }
    return -1;
}

// Mostra todos os elementos do vetor.
void mostra() {
    printf("Exibindo a lista de tamanho %d.\n", pos);
    int i = 0;
    while (i < pos) {
        printf("%d - %s\n", vetor[i].cod, vetor[i].nome);
        i++;
    }
}

// Remove um elemento da lista. 
// A posição do elemento a ser removido é passado como parâmetro na.
int remover(int posicao) {
    if (posicao > pos) return 0;
    
    vetor[posicao] = vetor[pos - 1];
    pos--;
    
    return 1;
}

int main() {
    No primeiro = {45, "ana maria"};
    No segundo = {88, "carla gomes"};
    No terceiro = {26, "patrocinio"};
    
    incluir(primeiro);
    incluir(segundo);
    incluir(terceiro);
    
    // Mostrar todos:
    mostra();
    
    // Procurar pelo índice em todos os itens.
    printf("Qual valor deseja consultar o índice? (max: %d)\n", pos-1);
    int valorDesejado;
    scanf("%d", &valorDesejado);
    if (valorDesejado > 0) {
        printf("Índice encontrado: %d\n", procura(valorDesejado));
    } else {
        printf("Índice não encontrado!");
    }
    
    // Inserir índice a remover:
    printf("Qual índice remover? (max: %d)\n", pos-1);
    int indiceARemover;
    scanf("%d", &indiceARemover);
    printf("Removendo o índice %d...\n", indiceARemover);
    
    // Remove o primeiro
    remover(indiceARemover);
    
    // Mostra novamente:
    mostra();
    
}
