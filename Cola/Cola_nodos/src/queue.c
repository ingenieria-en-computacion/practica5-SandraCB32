#include "queue.h"
#include <stdlib.h>

/**
 * Crea una nueva cola vacía.
 */
Queue* queue_create() 
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) 
    {
        return NULL; // Fallo en la asignación de memoria
    }
    q->head = NULL;
    q->tail = NULL;
    return q;
}

/**
 * Agrega un nuevo elemento a la cola.
 */
void queue_enqueue(Queue* q, Data d) 
{
    if (q == NULL) return;

    Node* new_n = new_node(d);
    if (new_n == NULL) return; // Fallo en la creación del nodo

    if (q->tail == NULL) { // Si la cola está vacía
        q->head = new_n;
        q->tail = new_n;
    } else {
        q->tail->next = new_n;
        q->tail = new_n;
    }
}

/**
 * Elimina y devuelve el elemento al frente de la cola.
 */
Data queue_dequeue(Queue* q) 
{
    if (q == NULL || q->head == NULL) 
    {
        return -1; // Cola vacía
    }

    Node* temp = q->head;
    Data d = temp->data;
    q->head = q->head->next;

    if (q->head == NULL) { // Si la cola queda vacía
        q->tail = NULL;
    }

    delete_node(temp);
    return d;
}

/**
 * Verifica si la cola está vacía.
 */
bool queue_is_empty(Queue* q) 
{
    return (q == NULL || q->head == NULL);
}

/**
 * Devuelve el elemento al frente de la cola sin eliminarlo.
 */
Data queue_front(Queue* q) 
{
    if (q == NULL || q->head == NULL) 
    {
        return -1; // Cola vacía
    }
    return q->head->data;
}

/**
 * Vacía la cola eliminando todos sus elementos.
 */
void queue_empty(Queue* q) 
{
    if (q == NULL) return;

    while (!queue_is_empty(q)) 
    {
        queue_dequeue(q);
    }
}

/**
 * Elimina la cola y libera la memoria asociada.
 */
void queue_delete(Queue* q) 
{
    if (q == NULL) return;

    queue_empty(q);
    free(q);
}