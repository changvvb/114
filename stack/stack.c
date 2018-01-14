#include "./stack.h"
#include <stdlib.h>

Stack * stack_new() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if(s != NULL) 
        s->top = 0;
    return s;
}
int stack_is_empty(Stack* s) {
    return (0 == s->top);
}

int stack_is_full(Stack* s) {
    return (MAX_SIZE == s->top);
}
int stack_push(Stack*s, Element *e) {
    if(stack_is_full(s)) return -1;
    s->buffer[s->top] = *e;
    s->top ++;
    return 0;
}
int stack_pop(Stack*s, Element *e) {
    if(stack_is_empty(s)) return -1;
    s->top --;
    *e = s->buffer[s->top];
    return 0;
}


