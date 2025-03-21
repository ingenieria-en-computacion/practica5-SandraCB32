#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"
#include "queue.h"

// Función para determinar si una frase es palíndromo
bool is_palindrome(const char* phrase) {
    int len = strlen(phrase);
    Stack stack = stack_create(len);
    Queue queue = queue_create(len);

    // Añadir caracteres a la pila y a la cola
    for (int i = 0; phrase[i] != '\0'; i++) {
        if (isalnum(phrase[i])) { // Ignorar espacios y caracteres no alfanuméricos
            char ch = tolower(phrase[i]);
            stack_push(&stack, ch);
            queue_enqueue(&queue, ch);
        }
    }

    // Comparar caracteres de la pila y la cola
    while (!stack_is_empty(&stack) && !queue_is_empty(&queue)) {
        if (stack_pop(&stack) != queue_dequeue(&queue)) {
            stack_delete(&stack);
            queue_delete(&queue);
            return false; // No es palíndromo
        }
    }

    stack_delete(&stack);
    queue_delete(&queue);
    return true; // Es palíndromo
}

int main() {
    char filename[100];
    printf("esPalindromo.txt\n");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: No se pudo abrir el archivo.\n");
        return 1;
    }

    char line[256];
    int line_number = 1;

    while (fgets(line, sizeof(line), file)) {
        // Eliminar el salto de línea al final de la línea
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        if (is_palindrome(line)) {
            printf("Línea %d: Es un palíndromo.\n", line_number);
        } else {
            printf("Línea %d: No es un palíndromo.\n", line_number);
        }
        line_number++;
    }

    fclose(file);
    return 0;
}