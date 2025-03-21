#ifndef __STACK_H__
#define __STACK_H__

#include <stdbool.h>

typedef char Data;

typedef struct {
    Data* data;
    int top;
    int size;
} Stack;

Stack stack_create(int size);
void stack_push(Stack* stack, Data value);
Data stack_pop(Stack* stack);
bool stack_is_empty(Stack* stack);
void stack_delete(Stack* stack);

#endif // __STACK_H__