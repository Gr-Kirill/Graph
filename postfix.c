#include "postfix.h"

void str_to_postfix(char *str, char *result, int *flag_error) {
    struct node *stack = init(INIT_VALUE);
    int postfix_idx = 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == 'x') {
            result[postfix_idx++] = str[i];
        } else if (str[i] == '(') {
            stack = push(stack, '(');
        } else if (str[i] == ')') {
            while (stack && stack->data != INIT_VALUE && stack->data != '(') {
                result[postfix_idx++] = ' ';
                result[postfix_idx++] = stack->data;
                stack = pop(stack);
            }
            if (stack && stack->data == '(') {
                stack = pop(stack);
            } else {
                *flag_error = 1;
            }
        } else {
            check_symbols(str, result, flag_error, &postfix_idx, &i, &stack);
        }
    }
    while (stack && stack->data != INIT_VALUE) {
        result[postfix_idx++] = ' ';
        result[postfix_idx++] = stack->data;
        stack = pop(stack);
    }
    destroy(stack);
    result[postfix_idx] = '\0';
}

void check_symbols(char *str, char *result, int *flag_error, int *postfix_idx, int *i, struct node **stack) {
    if (*postfix_idx - 1 >= 0 && result[*postfix_idx - 1] != ' ') {
        result[(*postfix_idx)++] = ' ';
    }
    while (*stack && (*stack)->data != INIT_VALUE && priority1(&str[*i]) <= priority2((*stack)->data)) {
        // printf("%d %d\n", priority1(&str[*i]), priority2((*stack)->data));
        result[(*postfix_idx)++] = (*stack)->data;
        result[(*postfix_idx)++] = ' ';
        *stack = pop(*stack);
    }
    if (str[*i] == 'c' && memcmp(&str[*i], "cos", 3) == 0) {
        if ((*stack = push(*stack, 'c')) != NULL) {
            *i += 2;
        }
    } else if (str[*i] == 's' && memcmp(&str[*i], "sin", 3) == 0) {
        if ((*stack = push(*stack, 's')) != NULL) {
            *i += 2;
        }
    } else if (str[*i] == 't' && memcmp(&str[*i], "tan", 3) == 0) {
        if ((*stack = push(*stack, 't')) != NULL) {
            *i += 2;
        }
    } else if (str[*i] == 'c' && memcmp(&str[*i], "ctg", 3) == 0) {
        if ((*stack = push(*stack, 'k')) != NULL) {
            *i += 2;
        }
    } else if (str[*i] == 's' && memcmp(&str[*i], "sqrt", 4) == 0) {
        if ((*stack = push(*stack, 'q')) != NULL) {
            *i += 3;
        }
    } else if (str[*i] == 'l' && memcmp(&str[*i], "ln", 2) == 0) {
        if ((*stack = push(*stack, 'l')) != NULL) {
            *i += 1;
        }
    } else if (str[*i] == '-' && (*i == 0 || (*i - 1 >= 0 && str[*i - 1] == '('))) {
        *stack = push(*stack, '~');
    } else if (str[*i] == '*' || str[*i] == '+' || str[*i] == '/' || str[*i] == '-') {
        *stack = push(*stack, str[*i]);
    } else if (str[*i] != ' ') {
        *flag_error = 1;
    }
}

int priority1(char *sym) {
    int ans = 4;
    if (*sym == '(' || *sym == ')')
        ans = 0;
    else if (*sym == 'c' && memcmp(sym, "cos", 3) == 0)
        ans = 3;
    else if (*sym == 's' && memcmp(sym, "sin", 3) == 0)
        ans = 3;
    else if (*sym == 't' && memcmp(sym, "tan", 3) == 0)
        ans = 3;
    else if (*sym == 'c' && memcmp(sym, "ctg", 3) == 0)
        ans = 3;
    else if (*sym == 's' && memcmp(sym, "sqrt", 4) == 0)
        ans = 3;
    else if (*sym == 'l' && memcmp(sym, "ln", 2) == 0)
        ans = 3;
    else if (*sym == '*' || *sym == '/')
        ans = 2;
    else if (*sym == '+' || *sym == '-')
        ans = 1;
    else if (*sym == '~')
        ans = 1;
    return ans;
}

int priority2(char sym) {
    int ans = 4;
    if (sym == '(' || sym == ')')
        ans = 0;
    else if (sym == 'c' || sym == 's' || sym == 't' || sym == 'k' || sym == 'q' || sym == 'l')
        ans = 3;
    else if (sym == '*' || sym == '/')
        ans = 2;
    else if (sym == '-' || sym == '+')
        ans = 1;
    else if (sym == '~')
        ans = 1;
    return ans;
}