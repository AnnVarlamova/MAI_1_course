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

list_node *get_by_id(list *lst, int id) {
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
}

int iterator_length(list *lst)
{
    if (!lst) {
        return 0;
    } else {
        if (lst->head->data && !lst->tail->data) {
            return 1;
        } else {
            iterator *len = (iterator *)malloc(sizeof(iterator));
            len->node = lst->head;
            int count = 1;
            do {
                count++;
                len->node = len->node->next;
            } while(len->node != lst->tail);
            return count;
        }
    }
}

void change_places(list *lst)
{
    if (iterator_length(lst) < 2) {
        printf("It's impossible\n");
    } else {
        if (iterator_length(lst) == 2) {
            fprintf(stdout, "[%lf]->[%lf]\n", lst->tail->data, lst->head->data);
        } else {
            if (iterator_length(lst) == 3) {
                list_fprint(lst, stdout);
            } else {
                list_node *tmp = (list_node *)malloc(sizeof(list_node));
                tmp->data = lst->head->next->data;
                lst->head->next->data = lst->tail->prev->data;
                lst->tail->prev->data = tmp->data;
                list_fprint(lst, stdout);
            }
        }
    } 
}
