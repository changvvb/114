#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

// typedef struct element {
//     int data;
// } Element;
//
//

typedef struct node {
    int data;
   struct node* lchild;
   struct node* rchild;
} Node, *Tree;

typedef Node* Element;

#endif
