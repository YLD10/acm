#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct point{
    int x;
    int y;
    point() {
        x = 0;
        y = 0;
    }
}Point;

int k = 0; //测试数据组数
int deep = 0;
int check_len = 0; //当前 check 数组的行数
int *R = NULL; //辐射半径数组
int *m = NULL; // M 点集数量组
int *n = NULL; // N 点集数量组
int **check = NULL; //疫情控制幷查集数组，每一行表示二叉树中的一层
Point **M = NULL; //第 i 行表示第 i 组测试数据中的 M 点集
Point **N = NULL; //第 i 行表示第 i 组测试数据中的 N 点集

int Input() {
    int flag = 0;
    scanf("%d", &k);
    if (k >= 1 && k <= 5) {
        R = (int *)malloc(sizeof(int) * k);
        m = (int *)malloc(sizeof(int) * k);
        n = (int *)malloc(sizeof(int) * k);
        M = (Point **)malloc(sizeof(Point *) * k);
        N = (Point **)malloc(sizeof(Point *) * k);

        for (int i = 0; i < k; ++ i) {
            flag = 0;

            scanf("%d%d%d", &m[i], &n[i], &R[i]);
            if (m[i] >= 1 && m[i] <= 100 && n[i] >= 1 && n[i] <= 100 && R[i] >= 1 && R[i] <= 10000) {
                flag = 1;
                M[i] = (Point *)malloc(sizeof(Point) * m[i]);
                N[i] = (Point *)malloc(sizeof(Point) * n[i]);

                for (int j = 0; j < m[i]; ++ j) {
                    scanf("%d%d", &M[i][j].x, &M[i][j].y);
                }

                for (int j = 0; j < n[i]; ++ j) {
                    scanf("%d%d", &N[i][j].x, &N[i][j].y);
                }
            }
        }
    }
    if (flag) {
        return 1;
    }
    return 0;
}

void Free() {
    if (R != NULL) free(R);
    if (m != NULL) free(m);
    if (n != NULL) free(n);
    for (int i = 0; i < check_len; ++ i) {
        if (check[i] != NULL) free(check[i]);
    }
    for (int i = 0; i < k; ++ i) {
        if (M[i] != NULL) free(M[i]);
        if (N[i] != NULL) free(N[i]);
    }
    if (check != NULL) free(check);
    if (M != NULL) free(M);
    if (N != NULL) free(N);
}

void Print() {
    for (int i = 0; i < k; ++ i) {
        printf("\nR: %d", R[i]);
        printf("\ncheck: ");
        for (int j = 0; j < m[i]; ++ j) {
            printf("%d ", check[i][j]);
        }
        printf("\nM: ");
        for (int j = 0; j < m[i]; ++ j) {
            printf("(%d,%d) ", M[i][j].x, M[i][j].y);
        }
        printf("\nN: ");
        for (int j = 0; j < n[i]; ++ j) {
            printf("(%d,%d) ", N[i][j].x, N[i][j].y);
        }

        printf("\n");
    }
}

void Control(int i, int layer) {
    check_len = layer + 1;
    check[layer] = (int *)malloc(sizeof(int) * m[i]);
    memset(check[layer], 0, sizeof(int) * m[i]);

}

void InfectionControl() {
    check = (int **)malloc(sizeof(int *) * k);

    for (int i = 0; i < k; ++ i) {
        Control(i, 0);
        printf("%d\n", deep);
        deep = 0;
        check_len = 0;
    }
}

int main()
{
    if (Input()) {
        //Print();
        InfectionControl();
    }

    Free();

    return 0;
}
