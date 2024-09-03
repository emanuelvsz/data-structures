#include "stack.h"

void init_stack(Stack *s) {
    s->top = -1;
}

int push(Stack *s, int car_id) {
    if (is_full(s)) return 0;
    s->cars[++(s->top)] = car_id;
    return 1;
}

int pop(Stack *s) {
    if (is_empty(s)) return -1;
    return s->cars[(s->top)--];
}

int peek(Stack *s) {
    if (is_empty(s)) return -1;
    return s->cars[s->top];
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_full(Stack *s) {
    return s->top == MAX_CARS - 1;
}

int size(Stack *s) {
    return s->top + 1;
}
