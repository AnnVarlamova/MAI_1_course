#include "list.h"
#include <stdio.h>
#include <stdlib.h>

list *list_create()
{
    list *lst = (list*) malloc(sizeof(list));
    lst->head = (list_node*)malloc(sizeof(list_node));
    lst->tail = (list_node*)malloc(sizeof(list_node));
    return lst;
}

void list_insert(list *lst, item val)
{
    if (lst == NULL) {
        return;
    }

    if (!lst->head->data) {
        lst->head->data = val;
    } else if (!lst->tail->data) {
        lst->tail->data = val;
        lst->head->next = lst->tail;
        lst->tail->prev = lst->head;
    } else {
        list_node *node = (list_node*) malloc(sizeof(list_node));
        node->data = val;
        node->prev = lst->tail;
        lst->tail->next = node;
        lst->tail = node;
    }
}

void list_fprint(list *lst, FILE *stream)
{
    fprintf(stream, "Your list\n");
    list_node *node = (list_node*) malloc(sizeof(list_node));
    node = lst->head;
    do {
        fprintf(stream, "[%lf]->", node->data);
        node = node->next;
    } while(node != lst->tail);
    fprintf(stream, "[%f]\n", node->data);
}

void list_delete_elem(list *lst, list_node *node)
{
    if (!lst->head->data) {
        printf("There is no such a list\n");
        return;
    } else {
        if (node->prev) {
            if (node->next) {
                list_node *tmp = (list_node*) malloc(sizeof(list_node));
                tmp->next = node->next;
                tmp->prev = node->prev;
                node->next->prev = tmp->prev;
                node->prev->next = tmp->next;
                free(tmp);
                free(node);
            } else {
                lst->tail = node->prev;
                free(node);
            }
        } else if (node == lst->head) {
            if (node->next) {
                lst->head = node->next;
                free(node);
            } else {
                free(lst);
                list_create();
                printf("Now list is empty\n");
            }
        }

    }
    list_fprint(lst, stdout);
}