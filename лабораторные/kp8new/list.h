#ifndef LIST_H
#define LIST_H

#include <stdio.h>

typedef double item;
typedef struct _list_node list_node;
typedef struct _list list;

struct _list_node
{
    item data;
    list_node *next;
    list_node *prev;
};

struct _list
{
    list_node *head;
    list_node *tail;
};

list *list_create();
void list_insert(list *lst, item val);
void list_insert_before(list *lst, item val, list_node *next_node);
void list_insert_after(list *lst, item curr_val, list_node *prev_node);
void list_delete_elem(list *lst, list_node *node);
void list_fprint(list *lst, FILE *stream);
list_node *get_by_id_list(list *lst, int id, int size);
void delete_elem(list *lst, int id, int size);

#endif
