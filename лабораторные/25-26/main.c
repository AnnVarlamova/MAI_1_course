#include "stack_int.h"

int main(void)
{
    stack_int *s = stack_int_create();
    printf("Note: To cancel just make uncorrect input (not integer)\n");
    printf("Put items into the stack: ");
    int input;
    while (scanf("%d", &input) > 0) {
        stack_int_push(s, input);
    }
    printf("  Your stack: ");
    stack_int_print(s);
    stack_int_insertion_sort(s); // Устойчивая, работает за O(n)
    printf("Sorted stack: ");
    stack_int_print(s);
    return 0;
}