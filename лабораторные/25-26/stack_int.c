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

bool exist_elem(stack_int *s, int data_to_del) {
    stack_node *cur = s->top;
    int count = 0;
    while (cur != NULL) {
        if (cur->value == data_to_del) {
            count++;
        }
        cur = cur->next;
    }
    if (count == 0) 
        return false;
    return true;
}

void stack_int_delete(stack_int *s, int data_to_del)
{
    if (!exist_elem(s, data_to_del)) {
        printf("It isn't in this stack\n");
        return;
    }
    if (stack_int_is_empty(s)) {
        printf("Stack is empty\n");
        return;
    }
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
    if (stack_int_is_empty(s)) {
        return;
    }
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
        res++;
    }
    return res;
}

void add(stack_int *s) {
    printf("Note: To cancel just make uncorrect input (not integer)\n");
    printf("Put items into the stack: ");
    int input;
    while (scanf("%d", &input) > 0) {
        stack_int_push(s, input);
    }
    char d[30] = "";
    scanf("%s", d);
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

void help() {
    printf("Enter 'add' to full stack\n");
    printf("Enter 'len' to know stack's length\n");
    printf("Enter 'sort' to sort stack\n");
    printf("Enter 'print' to print stack\n");
    printf("Enter 'del' to delete element\n");
    printf("Enter 'exit' for the end\n");
}