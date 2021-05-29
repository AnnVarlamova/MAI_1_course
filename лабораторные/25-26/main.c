#include "stack_int.h"

int main(void)
{
    stack_int *s = stack_int_create();
    help();
    char string[30] = "";
    while (strcmp(string, "exit") != 0) {
        scanf("%s", string);
        if (strcmp(string, "add") == 0) {
            add(s);
        } else if (strcmp(string, "len") == 0) {
            printf("Stack's length is %d\n", stack_int_size(s));
        } else if (strcmp(string, "sort") == 0) {
            stack_int_insertion_sort(s);
        } else if (strcmp(string, "print") == 0) {
            stack_int_print(s);
        } else if (strcmp(string, "del") == 0) {
            int data;
            printf("Enter data to delete\n");
            if (scanf("%d", &data) > 0) {
                stack_int_delete(s, data);
            }
        } else if (strcmp(string, "exit") == 0) {
        }
        else {
            help();
        }
    }
    return 0;
}