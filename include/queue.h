#ifndef QUEUE_H
#define QUEUE_N

#include <stddef.h>
#include "cache.h"

//------------------------------------------------------------------------------
//
// Queue header
//
//------------------------------------------------------------------------------
//
// This is a header for my implementation 
// of the Queue data struct
//
//------------------------------------------------------------------------------

typedef size_t TQueueValue;

struct queue;

typedef struct queue TQueue;

TQueue* create_queue (size_t size);

void queue_add_to_head (TQueue* queue, TQueueValue new_el);

TQueueValue queue_get_head (TQueue* queue);

TQueueValue queue_get_tail (TQueue* queue);

void queue_clean (TQueue* queue);

void queue_delete (TQueue* queue);

#endif // QUEUE_H