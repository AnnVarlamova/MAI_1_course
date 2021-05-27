#include "stack.h"
#include "tree.h"

void help()
{
    printf("Меню:\n");
    printf("1) Ввести выражение\n");
    printf("2) Печать исходного выражения\n");
    printf("3) Печать дерева\n");
    printf("4) Замена переменной\n");
    printf("5) Печать преобразованного выражения\n");
    printf("6) Выход\n");
    printf("Выберите действие: ");
}

Node *treeNodeCreate(void)
{
    Node *tmpNode = (Node *)malloc(sizeof(Node));
    tmpNode->_varOp = '\0';
    tmpNode->_num = 0;
    tmpNode->_left = NULL;
    tmpNode->_right = NULL;
    return tmpNode;
}

void treeDestroy(Node **node)
{
    if (*node == NULL)
        return;
    if ((*node)->_left != NULL)
        treeDestroy(&(*node)->_left);
    if ((*node)->_right != NULL)
        treeDestroy(&(*node)->_right);
    free(*node);
    *node = NULL;
}

int isLetter(const char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

int isNumber(const char ch)
{
    return (ch >= '0' && ch <= '9');
}

int isOp(const char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')');
}

int opPrior(const char op)
{
    if (op == '^')
        return 4;
    if (op == '*' || op == '/')
        return 3;
    if (op == '+' || op == '-')
        return 2;
    return 1;
}

int isOpHigh(const char op1, const char op2)
{
    if (op1 == '(' || op2 == '(' || op2 == ')')
    return 0;
    if (op1 == op2 && op2 == '^')
        return 0;
    return (opPrior(op1) >= opPrior(op2));
}

void postOrder(const char *str, Stack *st)
{
    int i = 0, isBracket = 0;
    char tmpCh;
    Token tk;
    Stack stOp;
    stackCreate(&stOp);
    tk._varOp = '\0';
    tk._num = 0;
    while (str[i] != '\0') {    
        if (isLetter(str[i]))
        {
            tk._varOp = str[i];
            stackPush(st, tk);
        } else if (isNumber(str[i])) {
            tk._varOp = '\0';
            tk._num = tk._num * 10 + str[i] - '0';
            if (str[i + 1] != '.' && !isNumber(str[i + 1]))
            {
                stackPush(st, tk);
            tk._num = 0;
            }
        } else if (isOp(str[i])) {
            tk._varOp = str[i];
            if (str[i] == ')')
                isBracket = 1;
            else if (str[i] == '-' && (i == 0 || str[i - 1] == '(')) {
                tmpCh = tk._varOp;
                tk._varOp = '\0';
                tk._num = 0;
                stackPush(st, tk);
                tk._varOp = tmpCh;
            }
            while (!stackEmpty(&stOp) && (isOpHigh(stackTop(&stOp)._varOp, str[i]) || isBracket)) {
                if (stackTop(&stOp)._varOp == '(')
                    isBracket = 0;
                else
                    stackPush(st, stackTop(&stOp));
                stackPop(&stOp);
            }
            if (str[i] != ')')
                stackPush(&stOp, tk);
        }
        i++;
    }
    while (!stackEmpty(&stOp)) {
        stackPush(st, stackTop(&stOp));
        stackPop(&stOp);
    }
    stackDestroy(&stOp);
}

void treeBuild(Node **node, Stack *st)
{
    Token token;
    if (stackEmpty(st))
        return;
    token = stackTop(st);
    stackPop(st);
    (*node) = treeNodeCreate();
    (*node)->_varOp = token._varOp;
    (*node)->_num = token._num;
    if (isOp((*node)->_varOp)) {
        treeBuild(&(*node)->_right, st);
        treeBuild(&(*node)->_left, st);
    }
}

void PKL(Node **node, const int level)
{
    if (*node == NULL)
        return;
    if ((*node)->_right != NULL)
        PKL(&(*node)->_right, level + 1);
    if ((*node)->_varOp != '\0')
        printf("%*s%c\n", level * 4, "", (*node)->_varOp);
    else
        printf("%*s%d\n", level * 4, "", (*node)->_num);
    if ((*node)->_left != NULL)
        PKL(&(*node)->_left, level + 1);
}

Node **search(Node **node, char value)
{
    Node **tmpNode = NULL;
    if ((*node)->_varOp == value)
        tmpNode = node;
    else if ((*node)->_right != NULL)
        tmpNode = search(&(*node)->_right, value);
    if (tmpNode == NULL && (*node)->_left != NULL)
        tmpNode = search(&(*node)->_left, value);
    return tmpNode;
}

void printExp(Node *tree, int i)
{
    if (tree==NULL)
        return;
    if ((tree->_left != NULL || tree->_right != NULL) && (i != 0))
    printf("(");
    printExp(tree->_left, i+1);
    if(tree->_num!=0) {
        printf("%d",tree->_num);
    } else if(tree->_varOp!='\0') {
        printf("%c",tree->_varOp);
    }
    printExp(tree->_right, i+1);
    if ((tree->_left != NULL || tree->_right != NULL) && (i != 0))
    printf(")");    
}
