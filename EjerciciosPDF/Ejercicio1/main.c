#include <stdio.h>
#include <string.h>
#include "stack.h"

// Función para verificar si los caracteres coinciden
bool is_matching_pair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// Función para verificar el equilibrio de paréntesis, llaves y corchetes
bool check_balance(const char* expression) {
    Stack stack = stack_create(strlen(expression)); // Crear pila del tamaño de la expresión

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        // Si es un carácter de apertura, lo empujamos a la pila
        if (ch == '(' || ch == '[' || ch == '{') {
            stack_push(&stack, ch);
        }
        // Si es un carácter de cierre, verificamos si coincide con el tope de la pila
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack_is_empty(&stack) || !is_matching_pair(stack_pop(&stack), ch)) {
                stack_delete(&stack); // Liberar memoria antes de salir
                return false; // No está equilibrado
            }
        }
    }

    // Si la pila está vacía al final, está equilibrado
    bool balanced = stack_is_empty(&stack);
    stack_delete(&stack); // Liberar memoria
    return balanced;
}

int main() {
    char expression[100];

    printf("Ingrese una expresión: ");
    fgets(expression, sizeof(expression), stdin);

    // Eliminar el salto de línea al final de la entrada
    size_t len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n') {
        expression[len - 1] = '\0';
    }

    if (check_balance(expression)) {
        printf("La expresión está equilibrada.\n");
    } else {
        printf("La expresión no está equilibrada.\n");
    }

    return 0;
}