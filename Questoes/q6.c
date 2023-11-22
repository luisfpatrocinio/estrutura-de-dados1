#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "pilhasFunctions.c"

int main() {
    // Obter quantidade de numeros:
    int qnt;
    printf("Informe a quantidade de numeros:\n");
    scanf("%d", &qnt);
    
    printf("Vamos utilizar %d numeros.\n", qnt);

    int *numeros = (int*)malloc(qnt * sizeof(int));

    // Obter numeros do usuário:
    for (int i = 0; i < qnt; i++) {
        printf("Num %d: ", i);
        scanf("%d", &numeros[i]);
    }

    printf("Números fornecidos: ");
    // Exibir lista de números:
    for (int i = 0; i < qnt; i++) {
        if (i > 0) printf(" - ");
        printf("%d", numeros[i]);
    }

    return 0;
}