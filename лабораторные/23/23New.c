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
    tree *knot = (tree *)malloc(sizeof(tree));
    knot->key = key;
    knot->left = NULL;
    knot->right = NULL;
    knot->parent = NULL;
    return knot;
}

tree *add(tree *root, int key) {
    if (root == NULL)
        create(key);
    else {
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
}

int exists(tree *root, int find) {
    int k = 0;
    if (root != NULL) {
        k = k + exists(root->left, find);
        if (root->key == find) {
            k++;
        }
        k = k + exists(root->right, find);
    }
    return k;
}

int count_not_leaves(tree *root) {
    int i = 0;
    tree *knot = root;
    if (knot != NULL) {
        i = i + count_not_leaves(knot->left);
        if ((knot->left != NULL) || (knot->right != NULL)) {
            i++;
        }
        i = i + count_not_leaves(knot->right);
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
        } else if (root->parent == NULL) {
            printf("root %d\t\t", root->key);
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
    if ((a->left == NULL) && (a->right == NULL)) {
        b = a->parent;
        if (a == b->right) {
            b->right = NULL;
        }
        if (a == b->left) {
            b->left = NULL;
        }
    }

    if ((a->left == NULL) && (a->right != NULL)) {
        b = a->parent;
        if (a == b->right) {
            b->right = a->right;
        }
        else
            b->left = a->right;
    }

    if ((a->left != NULL) && (a->right == NULL)) {
        b = a->parent;
        if (a == b->right)
            b->right = a->left;
        else
            b->left = a->left;
    }

    if ((a->left != NULL) && (a->right != NULL)) {
        b = a;
        a = min_(a->right);
        b->key = a->key;
        if (a->parent->left == a) {
            if (a->right != NULL) {
                a->parent->left = a->right;
                a->right->parent = a->parent->left;
            } else
                a->parent->left = NULL;
        }
        if (a->parent->right == a) {
            if (a->right != NULL) {
                a->parent->right = a->right;
                a->right->parent = a->parent->right;
            } else
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
    printf("to create tree press `c` then `enter` or whitespace\n");
    printf("to add knot press `a` then `enter`or whitespace\n");
    printf("to remove knot press `r` then `enter`or whitespace\n");
    printf("to watch tree press `w` then `enter`or whitespace\n");
    printf("to run function press `f` then `enter`or whitespace\n");
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
            if (exists(this_tree, value) != 0) {
                printf("It already exists\n");
            } else {
                this_tree = add(this_tree, value);
                printf("has been added %d\n", value);
            }
        }
        if (strncmp(string, "r",2) == 0) {
            scanf("%d", &value);
            if (exists(this_tree, value) == 0) {
                printf("It doesn`t exist in this tree\n");
            }
            else {
                if (this_tree->parent == NULL) {
                    tree *tmp = NULL;
                    if ((this_tree->left == NULL) && (this_tree->right == NULL)) {
                        free(this_tree);
                        this_tree = NULL;
                    }
                    else if ((this_tree->left != NULL) && (this_tree->right == NULL)) {
                        this_tree = this_tree->left;
                        this_tree->parent = NULL;
                    }
                    else if ((this_tree->left == NULL) && (this_tree->right != NULL)) {
                        this_tree = this_tree->right;
                        this_tree->parent = NULL;
                    } else if ((this_tree->left != NULL) && (this_tree->right != NULL)) {
                        tmp = min_(this_tree->right);
                        this_tree->key = tmp->key;
                        if (tmp->right == NULL) {
                            if (tmp->parent->right == tmp)
                                tmp->parent->right = NULL;
                            else
                                tmp->parent->left = NULL;
                        } else {
                            if (tmp->parent->right == tmp)
                                tmp->parent->right = tmp->right;
                            else
                                tmp->parent->left = tmp->right;
                        }
                    }
                } else
                    remove_(this_tree, value);
                printf("has been removed %d\n", value);
            }
        }
        if (strncmp(string, "w",2) == 0) {
            if (this_tree != NULL)
                show(this_tree);
        else
            printf("There is no tree, please, press `c` or `a` to create the root");
            printf("\n");
        }
        if (strncmp(string, "f",2) == 0) {
            printf("the amount of not leaves is %d\n", count_not_leaves(this_tree));
        }
    }
    return 0;
}
