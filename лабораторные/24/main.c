#include "stack.h"
#include "tree.h"

int main() {
    setlocale(LC_ALL, "rus");
    int action; 
    char variable[1];
    char expr[255];
    char reExpr[255];
    Node *root = NULL;
    Stack stPost;
    Stack stVar;
    help();
    while (action != 6) {
        scanf("%d", &action);
        switch (action) {
            case 1:
            {
                printf("Введите выражение: ");
                scanf("%s", expr);
                treeDestroy(&root);
                stackCreate(&stPost);
                postOrder(expr, &stPost);
                treeBuild(&root, &stPost);
                stackDestroy(&stPost);
                help();
                break;
            }
            case 2:
            {
                printf("Выражение: %s\n", expr);
                help();
                break;
            }
            case 3:
            {
                PKL(&root, 0);
                printf("\n");
                help();
                break;
            }
            case 4:
            {
                printf("Переменная: ");
                scanf("%s", variable);
                printf("Замена: ");
                scanf("%s", reExpr);
                Node **tmp = search(&root, variable[0]);
                while (&(*tmp) != NULL) {
                    stackCreate(&stVar);
                    postOrder(reExpr, &stVar);
                    Node* tt = NULL;
                    treeBuild(&tt, &stVar);
                    printf("\n");
                    *tmp = tt;
                    stackDestroy(&stVar);
                    tmp = search(&root, variable[0]);
                }
                help();
                break;
            }
            case 5:
            {
                printExp(root, 0);
                printf("\n");
                help();
                break;
            }
            case 6: break;
            default:
            {
                printf("Данный ключ отсутствует\n");
                help();
                break;                
            }
        } 
    }
    return 0;
}

