#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "draw.h"
#include "polish_notation.h"
#include "postfix.h"
#include "stack.h"

int main() {
    char str[1000], postfix_str[1000], matr[HEIGHT][WIDTH];
    int flag_error = 0;
    input_str(str);
    str_to_postfix(str, postfix_str, &flag_error);
    clear_matr(matr);
    double step_x = 4 * M_PI / WIDTH, step_y = 2.0 / HEIGHT;
    int index, j = 0;
    for (double main_x = 0; main_x <= 4 * M_PI; main_x += step_x) {
        if (flag_error) break;
        double y = get_value(postfix_str, main_x, &flag_error);
        if (y >= -1. && y <= 1.) {
            index = find_index(y, step_y);
            matr[(HEIGHT / 2) + index][j] = '*';
        }
        j++;
    }
    if (flag_error == 0) {
        output(matr);
    } else {
        printf("n/a");
    }

    return 0;
}