#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack stack_create(int size) {
    Stack stack;
    stack.data = (Data*)malloc(size * sizeof(Data));
    if (stack.data == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria para la pila.\n");
        stack.top = -1;
        stack.size = 0;
    } else {
        stack.top = -1;
        stack.size = size;
    }
    return stack;
}

void stack_push(Stack* stack, Data value) {
    if (stack->top + 1 == stack->size) {
        fprintf(stderr, "Error: La pila está llena.\n");
        return;
    }
    stack->data[++stack->top] = value;
}

Data stack_pop(Stack* stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "Error: La pila está vacía.\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

bool stack_is_empty(Stack* stack) {
    return stack->top == -1;
}

void stack_delete(Stack* stack) {
    free(stack->data);
    stack->data = NULL;
    stack->top = -1;
    stack->size = 0;
}