#ifndef __TREE_H__
#define __TREE_H__
#include "stack.h"

typedef struct _Node
{
char _varOp;
int _num;
struct _Node *_left;
struct _Node *_right;
} Node;

Node *treeNodeCreate(void);
void treeDestroy(Node **node);
void treeBuild(Node **node, Stack *st);
Node **search(Node **node, char value);
void printExp(Node *tree, int i);
void PKL(Node **node, const int level);
int  isLetter(const char ch);
int  isNumber(const char ch);
int  isOp(const char ch);
int  opPrior(const char op);
int  isOpHigh(const char op1, const char op2);
void postOrder(const char *str, Stack *st);
void help();

#endif
