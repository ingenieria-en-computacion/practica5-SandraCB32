#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>

typedef char Data;

typedef struct {
    Data* data;
    int head;
    int tail;
    int size;
    int count;
} Queue;

Queue queue_create(int size);
void queue_enqueue(Queue* queue, Data value);
Data queue_dequeue(Queue* queue);
bool queue_is_empty(Queue* queue);
void queue_delete(Queue* queue);

#endif // __QUEUE_H__