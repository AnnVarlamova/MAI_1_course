#ifndef STACK_INT_H
#define STACK_INT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _stack_node {
    int value;
    struct _stack_node *next;
} stack_node;

typedef struct _stack_int {
    stack_node *top;
} stack_int;

stack_int* stack_int_create();
bool       stack_int_is_empty(stack_int *s);
void       stack_int_push(stack_int *s, int data);
void       stack_int_delete(stack_int *s, int data_to_del);
void       stack_int_print(stack_int *s);
int        stack_int_size(stack_int *s);
void       stack_int_insertion_sort(stack_int *s);
bool       exist_elem(stack_int *s, int data_to_del);
void       help();
void       add(stack_int *s);

#endif