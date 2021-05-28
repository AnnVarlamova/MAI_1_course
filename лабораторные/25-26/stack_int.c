#include "stack_int.h"

stack_int* stack_int_create()
{
    stack_int *new = (stack_int*) malloc(sizeof(stack_int));
    new->top = NULL;
    return new;
}

bool stack_int_is_empty(stack_int *s)
{
    return s->top == NULL;
}

void stack_int_push(stack_int *s, int data)
{
    stack_node *new = (stack_node*) malloc(sizeof(stack_node));
    new->value = data;
    if (s->top == NULL) {
        s->top = new;
    } else {
        new->next = s->top;
        s->top = new;
    }
}

void stack_int_delete(stack_int *s, int data_to_del)
{
    stack_node *cur = s->top, *prev = NULL;
    while (cur != NULL) {
        if (cur->value == data_to_del) {
            if (cur == s->top) {
                s->top = cur->next;
                free(cur);
            } else {
                prev->next = cur->next;
                free(cur);
            }
        }
        prev = cur;
        cur = cur->next;
    }
}

void stack_int_print(stack_int *s)
{
    stack_node *cur = s->top;
    while (cur != NULL) {
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

int stack_int_size(stack_int *s)
{
    int res = 0;
    stack_node *cur = s->top;
    while (cur != NULL) {
        cur = cur->next;
        ++res;
    }
    return res;
}

void stack_int_insertion_sort(stack_int *s)
{
    for (stack_node *i = s->top; i != NULL; i = i->next) {
        for (stack_node *j = i->next; j != NULL; j = j->next) {
            if (i->value > j->value) {
                int tmp = i->value;
                i->value = j->value;
                j->value = tmp;
                continue;
            }
        }
    }
}