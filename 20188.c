#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* left;
    struct node* right;
} Node;

Node *make_node(int v){
    Node *n = malloc(sizeof(Node));
    if(n != NULL){
        n->value = v;
        n->left = NULL;
        n->right = NULL;
    }

    return n;
}

Node *insert_node(Node *top, int v, int i){
    i++;
    if(top == NULL){
        printf("count: %d\n", i);
        return make_node(v);
    }

    if(v < top->value){
        top->left = insert_node(top->left, v, i);
    }else{
        top->right = insert_node(top->right, v, i);
    }

    return top;
}

void traverse(Node *n){
    if(n == NULL){
        return;
    }

    traverse(n->left);
    printf("%d\n", n->value);
    traverse(n->right);
}

int main(){
    Node *top = NULL;
    top = insert_node(top, 7, 0);
    top = insert_node(top, 5, 0);
    top = insert_node(top, 9, 0);
    top = insert_node(top, 4, 0);
    top = insert_node(top, 6, 0);
    top = insert_node(top, 8, 0);
    top = insert_node(top, 10, 0);
    top = insert_node(top, 3, 0);

    traverse(top);

    return 0;
}