#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>

typedef struct vector {
    int number_of_elements;
    int capacity;
    int *elem;
} vector;

void vector_create(vector *v);
void resize(vector *v);
void vector_add(vector *v, int c);

#endif
