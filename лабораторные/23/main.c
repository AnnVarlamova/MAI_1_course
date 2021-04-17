#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Tree {
    int key;
    struct Tree *left;
    struct Tree *right;
    struct Tree *parent;
} tree;

tree *create(int key) {
    tree *knot = (tree *)malloc(sizeof(tree)); //создаём узел (корень)
    knot->key = key;
    knot->left = NULL;
    knot->right = NULL;
    knot->parent = NULL;
    return knot;
}

tree *add(tree *root, int key) {
    tree *knot = (tree *)malloc(sizeof(tree));
    knot->key = key;
    tree *previous = root;
    tree *free = NULL;
    while (previous != NULL) {
        free = previous;
        if (previous->key > key) {
            previous = previous->left;
        } else if (previous->key < key) {
            previous = previous->right;
        }
    }
    if (free->key > key) {
        free->left = knot;
    } else if (free->key < key) {
        free->right = knot;
    }
    knot->parent = free;
    knot->left = NULL;
    knot->right = NULL;
    return root;
}

int count_not_lists(tree *root) {
    int i = 0;
    tree *knot = root;
    if (knot != NULL) {
        i = i + count_not_lists(knot->left);
        if ((knot->left != NULL) || (knot->right != NULL)) {
            i++;
        }
        i = i + count_not_lists(knot->right);
    }
    return i;
}

void *show(tree *root) {
    if (root != NULL) {
        if ((root->left != NULL) || (root->right != NULL)) {
            printf("\n\t parent %d\n", root->key);
            if (root->left != NULL)
                printf("left %d", root->left->key);
            if (root->right != NULL)
            printf("\t\t right %d", root->right->key);
            printf("\n");
        } else {
            printf("list %d\t\t", root->key);
        }
    show(root->left);
    show(root->right);
    }
}

tree *min_(tree *root) {
    tree *knot = root;
    while (knot->left != NULL)
        knot = knot->left;
    return knot;
}

tree *search_(tree *root, int key) {
    if ((root->key == key) || (root == NULL))
        return root;
    if (root->key > key)
        return search_(root->left, key);
    else
        return search_(root->right, key);
}

void *remove_(tree *root, int key) {
    tree *p = root, *a = NULL, *b = NULL;
    a = search_(p, key);
    // 1) у узла нет поддеревьев
    if ((a->left == NULL) && (a->right == NULL)) {
        b = a->parent;
        if (a == b->right) {
            b->right = NULL;
        }
        if (a == b->left) {
            b->left = NULL;
        }
    }
    // 2) есть поддерево справа
    if ((a->left == NULL) && (a->right != NULL)) {
        b = a->parent;
        if (a == b->right) {
            b->right = a->right;
        }
        else
            b->left = a->right;
    }
    //3) есть поддерево слева
    if ((a->left != NULL) && (a->right == NULL)) {
        b = a->parent;
        if (a == b->right)
            b->right = a->left;
        else
            b->left = a->left;
    }
    // 4) есть оба поддерева
    if ((a->left != NULL) && (a->right != NULL)) {
        b = a;
        a = min_(a->right);
        b->key = a->key;
        if (a->parent->left == a) {
            a->parent->left = NULL;
        }
        if (a->parent->right == a) {
            a->parent->right = NULL;
        }
    }
    free(a);
    a = NULL;
}

int main(void)
{
    tree *this_tree = NULL;
    char string[2];
    int value = 0;
    printf("to create tree press `c` then `enter` or whatespace\n");
    printf("to add knot press `a` then `enter`or whatespace\n");
    printf("to remove knot press `r` then `enter`or whatespace\n");
    printf("to watch tree press `w` then `enter`or whatespace\n");
    printf("to run function press `f` then `enter`or whatespace\n");
    printf("to exit press `e` then `enter`\n");
    while (strncmp(string, "e",2) != 0) {
        scanf("%s", string);
        if (strncmp(string, "c",2) == 0) {
            scanf("%d", &value);
            this_tree = create(value);
            printf("has been created %d\n", value);
        }
        if (strncmp(string, "a",2) == 0) {
            scanf("%d", &value);
            this_tree = add(this_tree, value);
            printf("has been added %d\n", value);
        }
        if (strncmp(string, "r",2) == 0) {
            scanf("%d", &value);
            remove_(this_tree, value);
            printf("has been removed %d\n", value);
        }
        if (strncmp(string, "w",2) == 0) {
            show(this_tree);
            printf("\n");
        }
        if (strncmp(string, "f",2) == 0) {
            printf("the amount of not lists is %d\n", count_not_lists(this_tree));
        }
    }
    return 0;
}
