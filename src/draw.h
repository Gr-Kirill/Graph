#ifndef DRAW_H
#define DRAW_H

#include <stdio.h>

#define HEIGHT 25
#define WIDTH 80

void clear_matr(char (*matr)[WIDTH]);
void input_str(char *str);
int find_index(double y, double step);
void output(char (*matr)[WIDTH]);

#endif