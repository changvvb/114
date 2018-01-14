#include "./queue.h"
#include <stdlib.h>


Queue* queue_new() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q != NULL) {
        q->front = 0;
        q->rear = 0;
    }
    return q;
}
int queue_is_empty(Queue* q) {
    return (q->rear == q->front); 
}
int queue_is_full(Queue* q){
    return ((q->rear+1)%MAX_SIZE == q->front);
}
int enqueue(Queue* q,Element *e) {
    if(queue_is_full(q)) return -1;
    q->buffer[q->rear] = *e;
    q->rear = (q->rear+1)%MAX_SIZE;
    return 0;
}
int dequeue(Queue* q,Element *e) {
    if(queue_is_empty(q)) return -1;
    *e = q->buffer[q->front];
    q->front = (q->front+1)%MAX_SIZE;
    return 0;
}
