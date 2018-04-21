/*************************************************************************
	> File Name: chess.cpp
	> Author: YLD10 
	> Mail: yl1315348050@yahoo.com
	> Created Time: 4/21/星期六 14:44:33
    > Describe: 马踏棋盘问题。国际象棋的棋盘为 8*8 的方格棋盘，现将"马"放在
    任意指定的方格中，按照"马"走棋的规则将"马"进行移动。要求每个方格只能进入
    一次，最终使得"马"走遍棋盘 64 个方格。
    >reference: fishc.com
 ************************************************************************/

#include <iostream>
#include <ctime>
// using namespace std;

#define X 8
#define Y 8

int chess[X][Y];

// 找到基于 (x,y) 坐标的下一个可走的位置
int nextxy(int *x, int *y, int count)
{
    switch(count) {
        case 0:
        if (*x-1 >= 0 && *y-2 >= 0 && !chess[*x-1][*y-2]) {
            *x -= 1;
            *y -= 2;
            return 1;
        }
        break;
        case 1:
        if (*x+1 <= X-1 && *y-2 >= 0 && !chess[*x+1][*y-2]) {
            *x += 1;
            *y -= 2;
            return 1;
        }
        break;
        case 2:
        if (*x+2 <= X-1 && *y-1 >= 0 && !chess[*x+2][*y-1]) {
            *x += 2;
            *y -= 1;
            return 1;
        }
        break;
        case 3:
        if (*x+2 <= X-1 && *y+1 <= Y-1 && !chess[*x+2][*y+1]) {
            *x += 2;
            *y += 1;
            return 1;
        }
        break;
        case 4:
        if (*x+1 <= X-1 && *y+2 <= Y-1 && !chess[*x+1][*y+2]) {
            *x += 1;
            *y += 2;
            return 1;
        }
        break;
        case 5:
        if (*x-1 >= 0 && *y+2 <= Y-1 && !chess[*x-1][*y+2]) {
            *x -= 1;
            *y += 2;
            return 1;
        }
        break;
        case 6:
        if (*x-2 >= 0 && *y+1 <= Y-1 && !chess[*x-2][*y+1]) {
            *x -= 2;
            *y += 1;
            return 1;
        }
        break;
        case 7:
        if (*x-2 >= 0 && *y-1 >= 0 && !chess[*x-2][*y-1]) {
            *x -= 2;
            *y -= 1;
            return 1;
        }
        break;
    }
    return 0;
}

void print()
{
    int i = 0, j = 0;

    for (i = 0; i < X; ++ i) {
        for (j = 0; j < Y; ++ j)
            std::cout << chess[i][j] << '\t';
        std::cout << '\n';
    }
}

//深度优先遍历棋盘
//(x,y) 为位置坐标
//tag 是标记变量，每走一步，tag+1
int TravelChessBoard(int x, int y, int tag)
{
    int x1 = x, y1 = y, count = 0, flag = 0;
    chess[x][y] = tag;

    if (X*Y == tag) {
        // 打印棋盘
        print();
        return 1;
    }

    //找到马的下一个可走的坐标 (x1,y1)，如果找到 flag=1，否则为 0
    flag = nextxy(&x1, &y1, count);
    while (0 == flag && count < 7) {
        ++ count;
        flag = nextxy(&x1, &y1, count);
    }

    while (flag) {
        if (TravelChessBoard(x1, y1, tag+1)) 
            return 1;

        // 继续找到马的下一个可走的坐标 (x1,y1)，如果找到 flag=1，否则为 0
        flag = nextxy(&x1, &y1, count);
        while (0 == flag && count < 7) {
            ++ count;
            flag = nextxy(&x1, &y1, count);
        }

    }

    chess[x][y] = 0;

    return 0;
}

int main()
{
    int i = 0, j = 0;
    clock_t start, finish;

    start = clock();
    for (i = 0; i < X; ++ i)
        for (j = 0; j < Y; ++ j)
            chess[i][j] = 0;

    if (!TravelChessBoard(2, 0, 1)) // 起始位置坐标 (2,0)，这个耗时比较少
        std::cout << "\n抱歉，马踏棋盘失败了\n";

    finish = clock();
    
    std::cout << "\n总共耗时：" << (double)(finish-start)/CLOCKS_PER_SEC << " 秒\n";

    return 0;
}
