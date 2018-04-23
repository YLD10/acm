/*************************************************************************
    > File Name: kmp.cpp
    > Author: YLD10 
    > Mail: yl1315348050@yahoo.com
    > Created Time: 4/23/星期一 23:00:57
    > Describe: match substring and return index.
 ************************************************************************/

#include <iostream>
#include <string.h>
// using namespace std;

// 计算 next 数组
void get_next(char* ptr, int *next)
{
    int len = strlen(ptr); // len 存放模式串长度。

    int j = -1; // 前缀锚点
    int i = 0; // 后缀锚点
    next[0] = -1; // 表示无需回溯
    while (i < len-1) {
        if (-1 == j || ptr[j] == ptr[i]) {
            ++ i;
            ++ j;
            if (ptr[j] != ptr[i])
                next[i] = j;
            else
                next[i] = next[j];
        }
        else
            j = next[j];
    }
}

// 返回从 pos 位置起匹配到的起始下标
int kmp(char *str, char *ptr, int pos)
{
    int i = pos;
    int j = 0;
    int slen = strlen(str);
    int plen = strlen(ptr);
    int next[plen];
    get_next(ptr, next);

    while (i < slen && j < plen) {
        if (-1 == j || str[i] == ptr[j]) {
            ++ i;
            ++ j;
        }else {
            j = next[j];
        }
    }
    if (j == plen)
        return i - plen;
    return -1;
}

int main()
{
    char str[] = "ababaccababacabbbb";
    char ptr[] = "ababaca";

    std::cout << kmp(str, ptr, 0) << '\n'; 

    return 0;
}

