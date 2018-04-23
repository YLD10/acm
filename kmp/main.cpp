/*************************************************************************
    > File Name: kmp.cpp
    > Author: YLD10
    > Mail: yl1315348050@yahoo.com
    > Created Time: 4/23/����һ 23:00:57
    > Describe: match substring and return index.
 ************************************************************************/

#include <iostream>
#include <string.h>
// using namespace std;

// ���� next ����
void get_next(char* ptr, int *next)
{
    int len = strlen(ptr); // len ���ģʽ�����ȡ�

    int j = -1; // ǰ׺ê��
    int i = 0; // ��׺ê��
    next[0] = -1; // ��ʾ�������
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

// ���ش� pos λ����ƥ�䵽����ʼ�±�
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
    char str[] = "abcccababacabbbb";
    char ptr[] = "ababaca";

    std::cout << kmp(str, ptr, 0);

    return 0;
}

