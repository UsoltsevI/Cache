#include <stdlib.h>
#include "../include/queue.h"

struct queue {
    TQueueValue* data;

    size_t capacity;
    size_t size;

    TQueueValue* head;
    TQueueValue* tail; 
};


TQueue* create_queue (size_t size) {
    TQueue* queue = (TQueue*)calloc(1, sizeof(TQueue));

    queue->capacity = size; queue->size = 0;
    queue->data = (TQueueValue*)calloc(size, sizeof(TQueueValue));
    queue->head = queue->data;
    queue->tail = queue->data;

    return queue;
}

void queue_add_to_head (TQueue* queue, TQueueValue new_el) {
    if (queue->size < queue->capacity) {
        *(queue->head) = new_el;
        queue->size += 1;
        queue->head = &queue->data[queue->size];
        return;
    }

    *(queue->tail) = new_el;
    queue->head = queue->tail;

    if (queue->tail == queue->data + sizeof(TQueueValue) * (queue->capacity - 1))
        queue->tail = queue->data;
    else 
        queue->tail = queue->head + sizeof(TQueueValue);
}

TQueueValue queue_get_head (TQueue* queue) {
    return *(queue->head);
}


TQueueValue queue_get_tail (TQueue* queue) {
    return *(queue->tail);
}

void queue_clean (TQueue* queue) {
    free(queue);
    queue->data = (TQueueValue*)calloc(queue->capacity, sizeof(TQueueValue));
    queue->size = 0;
    queue->head = queue->tail = queue->data;
}

void queue_delete (TQueue* queue) {
    free(queue->data);
    free(queue);
}