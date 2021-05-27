#ifndef __STACK_H__
#define __STACK_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct _Token
{
    char _varOp;
    double _num;
} Token;

typedef Token MYSTACK_TYPE;
typedef struct _ItemStack

{
    MYSTACK_TYPE _data;
    struct _ItemStack *_prev;
} ItemStack;

typedef struct _Stack
{
    int _size;
    struct _ItemStack *_top;
} Stack;

void         stackCreate(Stack *s);
int          stackEmpty(const Stack *s);
int          stackSize(const Stack *s);
int          stackPush(Stack *s, const MYSTACK_TYPE value);
int          stackPop(Stack *s);
MYSTACK_TYPE stackTop(const Stack *s);
void         stackDestroy(Stack *s);

#endif
