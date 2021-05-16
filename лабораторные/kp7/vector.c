#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void vector_create(vector *v)
{
    v->capacity = 0;
    v->number_of_elements = 0;
    v->elem = (int*)malloc(sizeof(int) * v->capacity);
}

void resize(vector *v)
{
    v->capacity++;
    v->elem = (int*)realloc(v->elem, sizeof(int) * (v->capacity));
}

void vector_add(vector *v, int c)
{
    if (v->number_of_elements == v->capacity) {
        resize(v);
    }
    v->elem[v->number_of_elements] = c;
    v->number_of_elements++;
}
