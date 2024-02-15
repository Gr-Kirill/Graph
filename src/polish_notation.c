#include "polish_notation.h"

void check_numbers(const char *str, double x, struct node **top, char *buf, int *cur, int *i) {
    if (str[*i] == 'x') {
        *top = push(*top, x);
        (*i)++;
    } else {
        while (str[*i] != '\0' && str[*i] != ' ') {
            buf[(*cur)++] = str[(*i)++];
        }
        buf[*cur] = '\0';
        *cur = 0;
        *top = push(*top, atof(buf));
    }
}

double get_value(char *str, double x, int *flag_error) {
    struct node *top = init(INIT_VALUE);
    char buf[PRECISION];
    int i = 0, cur = 0;
    double ans = 0;
    // printf("%s\n", str);
    while (*flag_error == 0 && str[i] != '\0') {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == 'x') {
            check_numbers(str, x, &top, buf, &cur, &i);
        } else if (str[i] == 's' || str[i] == 'c' || str[i] == 't' || str[i] == 'k' || str[i] == 'l' ||
                   str[i] == 'q' || str[i] == '~') {
            if (top && top->data != INIT_VALUE) {
                ans = operation_1(top->data, str[i++]);
                top = pop(top);
                top = push(top, ans);
            } else {
                *flag_error = 1;
            }
        } else if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-') {
            if (top && top->next && top->next->data != INIT_VALUE && top->data != INIT_VALUE) {
                ans = operation_2(top->next->data, top->data, str[i++]);
                top = pop(top);
                top = pop(top);
                top = push(top, ans);
            } else {
                *flag_error = 1;
            }
        } else if (str[i] == ' ') {
            while (str[i] == ' ') {
                i += 1;
            }
        } else {
            *flag_error = 1;
        }
    }
    if (top && top->data != INIT_VALUE) {
        ans = top->data;
        top = pop(top);
    } else {
        *flag_error = 1;
    }
    if (top->data != INIT_VALUE) {
        *flag_error = 1;
    }
    destroy(top);
    return ans;
}

double operation_1(double a, char op) {
    double ans = 0;
    if (op == 's')
        ans = sin(a);
    else if (op == 'c')
        ans = cos(a);
    else if (op == 't')
        ans = tan(a);
    else if (op == 'k')
        ans = ((double)1 / tan(a));
    else if (op == 'q')
        ans = sqrt(a);
    else if (op == 'l')
        ans = log(a);
    else if (op == '~')
        ans = -a;
    return ans;
}

double operation_2(double a, double b, char op) {
    double ans = 0;
    if (op == '+')
        ans = a + b;
    else if (op == '-')
        ans = a - b;
    else if (op == '*')
        ans = a * b;
    else if (op == '/')
        ans = a / b;
    return ans;
}