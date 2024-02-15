#include "draw.h"

void clear_matr(char (*matr)[WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            matr[i][j] = '.';
        }
    }
}

void input_str(char *str) {
    int size = 0;
    char sym = 0;
    while (sym != '\n') {
        scanf("%c", &sym);
        if (sym != '\n') {
            str[size] = sym;
            size += 1;
        }
    }
    str[size] = '\0';
}

int find_index(double y, double step) {
    int ans_i = -2;
    double start;
    if (y < 0) {
        start = step / 2;
        int flag = 0;
        for (int i = 0; i > -13 && flag == 0; i--) {
            if (y >= start + (i - 1) * step) {
                ans_i = i;
                flag = 1;
            }
        }
    } else {
        start = -step / 2;
        int flag = 0;
        for (int i = 0; i < 13 && flag == 0; i++) {
            if (y <= start + (i + 1) * step) {
                ans_i = i;
                flag = 1;
            }
        }
    }
    return ans_i;
}

void output(char (*matr)[WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) printf("%c", matr[i][j]);
        printf("\n");
    }
}
