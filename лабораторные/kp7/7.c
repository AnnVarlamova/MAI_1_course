#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct vector {
    int number_of_elements;
    int capacity;
    int *elem;
} vector;

void vector_create(vector *v)
{
    v->capacity = 0;
    v->number_of_elements = 0;
    v->elem = (int*)malloc(sizeof(int) * v->capacity);
}

void resize(vector *v)
{
    v->capacity++;
    v->elem = (int*)realloc(v->elem, sizeof(int) * (v->capacity));
}

void vector_add(vector *v, int c)
{
    if (v->number_of_elements == v->capacity) {
        resize(v);
    }
    v->elem[v->number_of_elements] = c;
    v->number_of_elements++;
}

int main(int argc, char *argv[])
{
    FILE *f;
    char name[30];
    int i, j, k;
    if (argc > 1) {
        f = fopen(argv[1], "r");
    } else {
        printf("Enter the file's name:\n");
        scanf("%s", name);
        f = fopen(name, "r");
    }
    if (f == NULL) {
        printf("This file doesn't exist in this directory\n");
    } else{
        fscanf(f, "%d%d", &i, &j);
        // Создаю массив из индексов начала строк, затем вектор для номеров столбцов, значений и индексов сл эл
        int M[i];
        vector A;
        vector_create(&A);
        int id = 1, count = 0;
        // Считываю матрицу
        for (int a = 1; a <= i; a++) {
            int tmp = 0;
            for (int b = 1; b <= j; b++) {
                fscanf(f, "%d", &k);
                if (k != 0) {
                    if (tmp == 0) {
                        M[a] = id;
                    }
                    if ((count != 0) && (tmp != 0)) {
                        vector_add(&A, id);
                    } else if ((count != 0) && (tmp == 0)) {
                        vector_add(&A, 0);
                    }
                    vector_add(&A, b);
                    vector_add(&A, k);
                    id += 3;
                    count++;
                    tmp++;
                }
            }
            if (tmp == 0) {
                M[a] = 0;
            }
        }
        vector_add(&A, 0);
        fclose(f);
        // Вывод матрицы в этом способе представления
        printf("Massiv of number of beginning lines\n");
        for (int p = 1; p <= i; p++) {
            printf("%d ", M[p]);
        }
        printf("\nVector of column's number, value, index of next element in line\n");
        for (int q = 0; q < count * 3; q++) {
            printf("%d ", A.elem[q]);
        }
        printf("\n");

        //Вывод матрицы в обычном виде
        printf("Usual matrix\n");
        for (int p = 1; p <= i; p++) {
            if (M[p] == 0) {
                for (int g = 0; g < j; g++)
                    printf("0       ");
                printf("\n");
            } else {
                int smth = M[p] - 1;
                for (int q = 1; q <= j; q++) {
                    if (q != A.elem[smth])
                        printf("0       ");
                    else {
                        printf("%-7d ", A.elem[smth+1]);
                        if (A.elem[smth + 2] != 0) {
                            smth += 3;
                        }
                    }
                }
                printf("\n");
            }
        }

        //Ввод вектора-столбца
        vector B;
        vector_create(&B);
        int element;
        printf("Enter vector-colomn consisted of %d elements\n", j);
        for (int g = 0; g < j; g++) {
            scanf("%d", &element);
            vector_add(&B, element);
        }
        //Функция
        printf("Result\n");
        int sum = 0, flag = 0;
        for (int p = 1; p <= i; p++) {
            int rez = 0;
            if (M[p] != 0) {
                int smth = M[p] - 1;
                for (int q = 1; q <= j; q++) {
                    if (q == A.elem[smth]) {
                        rez += (A.elem[smth + 1] * B.elem[q - 1]);
                        if (A.elem[smth + 2] != 0) {
                            smth += 3;
                        }
                    }
                } 
            }
            printf("%d\n", rez);
               if (rez != 0)
                    sum++;
        }
        printf("The amount of non-zero elements is %d\n", sum);
    }
    return 0;
} 
