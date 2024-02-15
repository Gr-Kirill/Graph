#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

struct node {
    double data;
    struct node* next;
};

struct node* init(double number);
struct node* push(struct node* elem, double number);
struct node* pop(struct node* root);
void destroy(struct node* root);

#endif