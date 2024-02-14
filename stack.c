#include "stack.h"

struct node* init(double number) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = number;
    new_node->next = NULL;
    return new_node;
}

struct node* push(struct node* root, double number) {
    struct node* new_node = init(number);
    if (new_node == NULL) {
        return root;
    }
    struct node* tmp = root;
    new_node->next = tmp;
    root = new_node;
    return root;
}

struct node* pop(struct node* root) {
    if (root == NULL) {
        return NULL;
    }
    struct node* tmp = root;
    root = root->next;
    free(tmp);
    return root;
}

void destroy(struct node* root) {
    struct node* ptr = root;
    struct node* tmp;
    while (ptr != NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}