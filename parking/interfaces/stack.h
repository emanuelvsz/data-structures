#ifndef STACK_H
#define STACK_H
#define MAX_CARS 10


typedef struct {
    int cars[MAX_CARS];
    int top;
} Stack;

void init_stack(Stack *s);
int push(Stack *s, int car_id);
int pop(Stack *s);
int peek(Stack *s);
int is_empty(Stack *s);
int is_full(Stack *s);
int size(Stack *s);
int contains(Stack *s, int car_id);
int get_car(Stack *s, int index);

#endif
