#ifndef __QUEUE_H__
#define __QUEUE_H__
#include "../binarytree/binarytree.h"

#define MAX_SIZE 10

typedef struct queue {
    Element buffer[MAX_SIZE];
    int front;
    int rear;
} Queue;

Queue* queue_new();
int queue_is_empty(Queue* q);
int queue_is_full(Queue* q);
int enqueue(Queue* q,Element *e);
int dequeue(Queue* q,Element *e);


#endif
