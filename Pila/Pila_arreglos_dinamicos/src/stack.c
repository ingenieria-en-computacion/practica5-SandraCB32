#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Crea una nueva pila vacía y la devuelve.
 * 
 * @param len valor que indica cuantos elementos se pueden guardar en la pila
 * @return Una nueva pila vacía. Si la creación falla, el estado de la cola es inválido.
 * @details Esta función inicializa una pila vacía. 
 *          Asigna memoria dinámica a data mediante malloc con un número de elementos igual a len
 */
Stack stack_create(int len) {
    Stack s;
    s.data = (Data*)malloc(len * sizeof(Data)); // Asigna memoria dinámica
    if (s.data == NULL) {
        s.top = -1; // Estado inválido si falla la asignación
    } else {
        s.top = -1; // Inicializa la pila como vacía
    }
    return s;
}

/**
 * Inserta un elemento en la parte superior de la pila.
 * 
 * @param s Referencia a la pila donde se insertará el elemento.
 * @param d Dato que se insertará en la pila.
 * @details Esta función añade el dato `d` en la parte superior de la pila. Si la pila está llena, 
 *          la función no realiza ninguna operación.
 */
void stack_push(Stack* s, Data d) {
    if (s == NULL || s->data == NULL) return;

    s->data[++(s->top)] = d; // Incrementa top y almacena el dato
}

/**
 * Elimina y devuelve el elemento en la parte superior de la pila.
 * 
 * @param s Referencia a la pila de la cual se eliminará el elemento.
 * @return El dato que estaba en la parte superior de la pila. Si la pila está vacía 
 *         devuelve un valor que indica error (por ejemplo, -1 o un valor predeterminado).
 * @details Esta función elimina el elemento en la parte superior de la pila y lo devuelve.
 *          Si la pila está vacía, no se realiza ninguna operación y se devuelve un valor de error.
 */
Data stack_pop(Stack* s) {
    if (s == NULL || s->data == NULL || s->top < 0) {
        return -1; // Devuelve -1 si la pila está vacía o es inválida
    }
    return s->data[(s->top)--]; // Devuelve el dato y decrementa top
}

/**
 * Verifica si la pila está vacía.
 * 
 * @param s Referencia a la pila que se desea verificar.
 * @return 1 si la pila está vacía, 0 si no lo está. Si el puntero `s` es NULL, devuelve -1.
 * @details Esta función comprueba si la pila no contiene elementos. Es útil para evitar operaciones
 *          como `stack_pop` en una pila vacía.
 */
int stack_is_empty(Stack *s) {
    if (s == NULL || s->data == NULL) {
        return -1; // Devuelve -1 si la pila es inválida
    }
    return s->top == -1 ? 1 : 0; // Devuelve 1 si está vacía, 0 si no lo está
}

/**
 * Vacía la pila, eliminando todos sus elementos.
 * 
 * @param s Referencia a la pila que se desea vaciar.
 * @details Esta función hace que top sea igual a -1
 */
void stack_empty(Stack* s) {
    if (s == NULL || s->data == NULL) return;
    s->top = -1; // Reinicia el índice top
}

/**
 * Elimina data y libera la memoria asociada.
 * 
 * @param s Referencia a la pila que se desea liberar la memoria de data
 * @details Esta función libera la memoria asignada dinámicamente para data dentro de la pila
 */
void stack_delete(Stack* s) {
    if (s == NULL || s->data == NULL) return;

    free(s->data); // Libera la memoria dinámica
    s->data = NULL; // Evita accesos posteriores
    s->top = -1; // Marca la pila como inválida
}

/**
 * Imprime los elementos de la pila.
 * 
 * @param s Referencia a la pila que se desea imprimir.
 * @details Esta función imprime los elementos de la pila en orden, desde la parte superior
 *          hasta la base. Si la pila está vacía la función imprime
 *          un mensaje indicando que la pila está vacía o es inválida. La salida se dirige a
 *          la salida estándar (stdout).
 */
void stack_print(Stack* s) {
    if (s == NULL || s->data == NULL || stack_is_empty(s)) {
        printf("La pila está vacía o es inválida.\n");
        return;
    }

    printf("Elementos de la pila (de arriba hacia abajo):\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->data[i]);
    }
}