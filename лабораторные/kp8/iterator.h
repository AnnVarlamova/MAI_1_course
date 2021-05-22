#ifndef ITERATOR_H
#define ITERATOR_H

#include "list.h"

typedef struct _iterator iterator;


struct _iterator 
{
    list_node *node;
};

iterator  *iterator_create(list *lst);
void       iterator_next(iterator *it);
void       iterator_prev(iterator *it);
list_node *iterator_get(iterator *it);
int        iterator_length(list *lst);
void       change_places(list *lst);

#endif
