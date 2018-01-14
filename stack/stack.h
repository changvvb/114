#ifndef __STACK_H__
#define __STACK_H__
#include "../binarytree/binarytree.h"

#define MAX_SIZE 10

typedef struct stack {
    Element buffer[MAX_SIZE];
    int top;
} Stack;

Stack * stack_new();
int stack_is_empty(Stack* s);
int stack_is_full(Stack* s);
int stack_push(Stack*s, Element *e);
int stack_pop(Stack*s, Element *e);



#endif
