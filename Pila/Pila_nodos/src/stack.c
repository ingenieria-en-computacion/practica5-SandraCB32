#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Crea una nueva pila vacía y la devuelve.
 * 
 * @return Un apuntador a la nueva pila creada. Si la creación falla, devuelve NULL.
 * @details Esta función asigna memoria dinámicamente para una nueva pila utilizando `malloc`.
 *          Si la asignación de memoria falla, la función devuelve NULL. La pila creada
 *          está vacía y `top` apunta a NULL.
 */
Stack *stack_create() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s == NULL) {
        return NULL; // Fallo en la asignación de memoria
    }
    s->top = NULL; // Inicializa la pila como vacía
    return s;
}

/**
 * Inserta un elemento en la parte superior de la pila.
 * 
 * @param s Apuntador a la pila donde se insertará el elemento.
 * @param d Dato que se insertará en la pila.
 * @details Esta función añade el dato `d` en la parte superior de la pila. Si la pila está llena
 *          o el puntero `s` es NULL, la función no realiza ninguna operación.
 */
void stack_push(Stack* s, Data d) {
    if (s == NULL) return;

    Node *new_n = new_node(d);
    if (new_n == NULL) return; // Fallo en la creación del nodo

    new_n->next = s->top; // El nuevo nodo apunta al nodo actual en la cima
    s->top = new_n;       // Actualiza la cima de la pila
}

/**
 * Elimina y devuelve el elemento en la parte superior de la pila.
 * 
 * @param s Apuntador a la pila de la cual se eliminará el elemento.
 * @return El dato que estaba en la parte superior de la pila. Si la pila está vacía o el puntero
 *         `s` es NULL, devuelve un valor que indica error (por ejemplo, -1).
 * @details Esta función elimina el elemento en la parte superior de la pila y lo devuelve.
 *          Si la pila está vacía, no se realiza ninguna operación y se devuelve un valor de error.
 */
Data stack_pop(Stack* s) {
    if (s == NULL || s->top == NULL) {
        return -1; // Pila vacía o inválida
    }

    Node *temp = s->top;      // Nodo a eliminar
    Data d = temp->data;      // Guarda el dato del nodo
    s->top = temp->next;      // Actualiza la cima de la pila
    delete_node(temp);        // Libera la memoria del nodo eliminado
    return d;
}

/**
 * Verifica si la pila está vacía.
 * 
 * @param s Apuntador a la pila que se desea verificar.
 * @return 1 si la pila está vacía, 0 si no lo está. Si el puntero `s` es NULL, devuelve -1.
 * @details Esta función comprueba si la pila no contiene elementos. Es útil para evitar operaciones
 *          como `stack_pop` en una pila vacía.
 */
int stack_is_empty(Stack* s) {
    if (s == NULL) {
        return -1; // Pila inválida
    }
    return s->top == NULL ? 1 : 0; // Devuelve 1 si está vacía, 0 si no lo está
}

/**
 * Vacía la pila, eliminando todos sus elementos.
 * 
 * @param s Apuntador a la pila que se desea vaciar.
 * @details Esta función elimina todos los elementos de la pila, dejándola vacía.
 *          Si el puntero `s` es NULL, la función no realiza ninguna operación.
 *          La memoria de los elementos eliminados se libera adecuadamente.
 */
void stack_empty(Stack* s) {
    if (s == NULL) return;

    while (s->top != NULL) {
        stack_pop(s); // Elimina cada nodo de la pila
    }
}

/**
 * Elimina la pila y libera la memoria asociada a ella.
 * 
 * @param s Apuntador a la pila que se desea eliminar.
 * @details Esta función libera la memoria asignada dinámicamente para la pila y todos sus elementos
 *          utilizando `free`. Si el puntero pasado es NULL, la función no realiza ninguna operación.
 *          Es responsabilidad del llamante asegurarse de que la pila ya no se utiliza después
 *          de ser eliminada.
 */
void stack_delete(Stack *s) {
    if (s == NULL) return;

    stack_empty(s); // Vacía la pila antes de eliminarla
    free(s);        // Libera la memoria de la estructura de la pila
}

/**
 * Imprime los elementos de la pila.
 * 
 * @param s Apuntador a la pila que se desea imprimir.
 * @details Esta función imprime los elementos de la pila en orden, desde la parte superior
 *          hasta la base. Si la pila está vacía o el puntero `s` es NULL, la función imprime
 *          un mensaje indicando que la pila está vacía o es inválida. La salida se dirige a
 *          la salida estándar (stdout).
 */
void stack_print(Stack *s) {
    if (s == NULL) {
        printf("La pila es inválida.\n");
        return;
    }

    if (stack_is_empty(s)) {
        printf("La pila está vacía.\n");
        return;
    }

    printf("Elementos de la pila (de arriba hacia abajo):\n");
    Node *current = s->top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}