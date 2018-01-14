#include "./binarytree.h"
#include "../stack/stack.h"
#include "../queue/queue.h"
#include <stdio.h>
#include <stdlib.h>

Tree init_binary_tree() {
    Tree t = (Node*) malloc(sizeof(Node));
    t->data = 1;
    
    t->lchild = (Node*)malloc(sizeof(Node));
    t->lchild->data = 2;
    
    t->rchild = (Node*)malloc(sizeof(Node));
    t->rchild->data = 3;


    t->lchild->lchild = (Node*)malloc(sizeof(Node));
    t->lchild->lchild->data = 4;
    
    t->lchild->rchild = (Node*)malloc(sizeof(Node));
    t->lchild->rchild->data = 5;

    t->rchild->lchild = (Node*)malloc(sizeof(Node));
    t->rchild->lchild->data = 6;

    t->lchild->rchild->lchild = (Node*)malloc(sizeof(Node));
    t->lchild->rchild->lchild->data = 7;

    return t;
}


void lmr_diverse(Tree t) {
    if(NULL == t) return;
    lmr_diverse(t->lchild);
    printf("%d\t",t->data);
    lmr_diverse(t->rchild);
}

void stack_lmr_deverse(Tree t) {
    if(NULL == t) return;
    Stack * stack = stack_new();
    Node* pnode = t;

    do {
        if(pnode == NULL) {
            stack_pop(stack,&pnode);
            printf("%d\t",pnode->data);
            pnode = pnode->rchild;
        } else {
            stack_push(stack,&pnode);
            pnode = pnode->lchild;
        }
    } while(pnode || !stack_is_empty(stack));

}

void layer_diverse(Tree t) {
    if(NULL == t) return;
    Queue *queue = queue_new();
    Node* pnode = t;
    enqueue(queue,&pnode);

    do {
        dequeue(queue,&pnode);
        printf("%d\t",pnode->data);
        if(pnode->lchild) enqueue(queue,&pnode->lchild);
        if(pnode->rchild) enqueue(queue,&pnode->rchild);
    } while(!queue_is_empty(queue));
}

int main() {
    Tree t = init_binary_tree();
    lmr_diverse(t);
    printf("\n");
    stack_lmr_deverse(t);
    printf("\n");
    layer_diverse(t);
    return 0;
}





