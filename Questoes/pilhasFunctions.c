
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
#define ERROR_CODE 'x'

// Criar a estrutura da Pilha
typedef struct Stack {
    int top;
    char data[MAX];
} Stack;

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

bool isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

void printStack(Stack* stack) {
    printf("Printando Stack de %d elementos: \n", stack->top + 1);
    int counter = 0;
    while (counter < stack->top) {
        printf("%c ", stack->data[counter]);
        counter++;
    }
    printf('\n');
}

void stackValue(char value, Stack* stack) {
    if (isFull(stack)) {
        printf("Sorry man, the stack is full. sad man\n");
    }
    stack->top = stack->top + 1;
    stack->data[stack->top] = value;
}

char popValue(Stack* stack) {
    if (isEmpty(stack)) {
        printf("We dont have values on stack man, what are you doing man\n");
        return ERROR_CODE;
    }
    // return stack.data[stack.top--];
    char removedValue = stack->data[stack->top];
    stack->top = stack->top - 1;
    return removedValue;
}

char getTopValue(Stack* stack) {
    return stack->data[stack->top];
}

void clearStack(Stack* stack) {
    stack->top = -1;
}