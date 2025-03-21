#ifndef __STACK_H__
#define __STACK_H__

#include <stdbool.h>

typedef char Data; // Tipo de dato que manejará la pila

typedef struct {
    Data* data;  // Arreglo dinámico para almacenar los elementos
    int top;     // Índice del elemento en la cima de la pila
    int size;    // Capacidad máxima de la pila
} Stack;

// Funciones para manejar la pila
Stack stack_create(int size);
void stack_push(Stack* stack, Data value);
Data stack_pop(Stack* stack);
Data stack_peek(Stack* stack);
bool stack_is_empty(Stack* stack);
void stack_delete(Stack* stack);

#endif // __STACK_H__