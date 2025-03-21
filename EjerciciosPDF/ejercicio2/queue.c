#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Queue queue_create(int size) {
    Queue queue;
    queue.data = (Data*)malloc(size * sizeof(Data));
    if (queue.data == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria para la cola->\n");
        queue.head = -1;
        queue.tail = -1;
        queue.size = 0;
        queue.count = 0;
    } else {
        queue.head = 0;
        queue.tail = -1;
        queue.size = size;
        queue.count = 0;
    }
    return queue;
}

void queue_enqueue(Queue* queue, Data value) {
    if (queue->count == queue->size) {
        fprintf(stderr, "Error: La cola está llena->\n");
        return;
    }
    queue->tail = (queue->tail + 1) % queue->size;
    queue->data[queue->tail] = value;
    queue->count++;
}

Data queue_dequeue(Queue* queue) 
{
    if (queue_is_empty(queue)) {
        fprintf(stderr, "Error: La cola está vacía->\n");
        return '\0';
    }
    Data value = queue->data[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    queue->count--;
    return value;
}

bool queue_is_empty(Queue* queue) {
    return queue->count == 0;
}

void queue_delete(Queue* queue) {
    free(queue->data);
    queue->data = NULL;
    queue->head = -1;
    queue->tail = -1;
    queue->size = 0;
    queue->count = 0;
}