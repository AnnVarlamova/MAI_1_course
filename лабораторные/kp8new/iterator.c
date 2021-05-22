#include "iterator.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

iterator *iterator_create(list *lst)
{
    iterator *it = (iterator *)malloc(sizeof(iterator));
    it->node = lst->head;
    return it;
}

void iterator_next(iterator *it)
{
    if(it->node->next) {
        it->node = it->node->next;
    } else {
        printf("It is the last element\n");
    }
}

void iterator_prev(iterator *it)
{
    if(it->node->prev) {
        it->node = it->node->prev;
    } else {
        printf("It is the first element\n");
    }
}

list_node *iterator_get(iterator *it)
{
    return it->node;
}

/*list_node *get_by_id(list *lst, int id)
{
    if (iterator_length(lst) == 0) {
        printf("This list doesn't exist\n");
    } else {
        if (id > iterator_length(lst)) {
            printf("This node doesn't exist\n");
        } else if (id == 1) {
            return lst->head;
        } else if (id == iterator_length(lst)) {
            return lst->tail;
        } else if (id > 1) {
            iterator *it = iterator_create(lst);
            for (int i = 1; i < id; i++) {
                iterator_next(it);
            }
            return it->node;
        }
    }
}*/

int iterator_length(list *lst)
{
    if (lst->head == NULL && lst->tail == NULL) {
        return 0;
    }
    iterator *len = (iterator *)malloc(sizeof(iterator));
    len->node = lst->head;
    int count = 1;
    while (len->node->next != NULL) {
        count++;
        len->node = len->node->next;
    }
    return count;
}

void change_places(list *lst)
{
    int size = iterator_length(lst);
    if (size < 2 || size == 3) {
        return;
    }
    item t = lst->head->next->data;
    lst->head->next->data = lst->tail->prev->data;
    lst->tail->prev->data = t;
}