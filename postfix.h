#ifndef POSTFIX_H
#define POSTFIX_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

#define INIT_VALUE -2147483647

void str_to_postfix(char *str, char *result, int *flag_error);
void check_symbols(char *str, char *result, int *flag_error, int *postfix_idx, int *i, struct node **stack);
int priority1(char *sym);
int priority2(char sym);

#endif
