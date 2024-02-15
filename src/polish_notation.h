#ifndef POLISH_NOTATION_H
#define POLISH_NOTATION_H
#include <math.h>
#include <stdio.h>

#include "stack.h"

#define PRECISION 15
#define INIT_VALUE -2147483647

double get_value(char *str, double x, int *flag_error);

double operation_1(double a, char op);
double operation_2(double a, double b, char op);
void check_numbers(const char *str, double x, struct node **top, char *buf, int *cur, int *i);

#endif