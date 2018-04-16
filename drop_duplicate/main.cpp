/*************************************************************************
	> File Name: drop_duplicate.cpp
	> Author: YLD10
	> Mail: yl1315348050@yahoo.com
	> Created Time: 4/15/������ 22:22:44
	> Describe: Give a sort array, make some elements which has duplicate
                values turn to single value.
 ************************************************************************/

#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
// using namespace std;

typedef char Elemtype;

template <class ForwardIterator>
bool is_sorted (ForwardIterator first, ForwardIterator last)
{
    if (first == last) return true;
    ForwardIterator next = first;
    while (++next != last) {
        if (*next < *first)     // or, if (comp(*next,*first)) for version (2)
            return false;
        ++first;
    }
    return true;
}

int main()
{
//    int n = 0;
//    std::cin >> n;
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Elemtype a;
    std::vector<Elemtype> arr;
    while (std::cin >> a) {
        while (' ' == std::cin.peek())  // ���յ����з�ǰ�Ŀո�
            std::cin.get();

        arr.push_back(a);

        if ('\n' == std::cin.peek())
            break;
    }

    std::cout << "\nԭ����Ϊ��" << '\n';
    std::vector<Elemtype>::iterator iter = arr.begin();
    for (; iter != arr.end(); ++ iter) {
        std::cout << *iter << ' ';
    }
    std::cout << '\n';

    if (!is_sorted(arr.begin(), arr.end())) {
        std::sort(arr.begin(), arr.end());  // ��������

        std::cout << "\n���������Ϊ��" << '\n';
        iter = arr.begin();
        for (; iter != arr.end(); ++ iter) {
            std::cout << *iter << ' ';
        }
        std::cout << '\n';
    }

#if 0
    tmp ָ��������һ���ظ�Ԫ�صĵ�һ������cur ������ֱ���߳������ظ�Ԫ��
    tmp �� cur ��ͬ��ʱ���� tmp ��ֵ�������±�Ϊ k ��λ�ã�ÿ����һ�� k ����
    k ������ȥ�غ�����Ĵ�С
#endif // 0
    int tmp = arr[0], cur = arr[1], i = 0, k = 0, n = arr.size();
    for (; i < n-1; ) {
        if (tmp != cur) {
            arr[k++] = tmp;
            tmp = cur;
            cur = arr[++i];
        }else
            cur = arr[++i];
    }
    if (tmp != cur) {
        arr[k] = tmp;
        arr[++k] = cur;
    }else
        arr[k] = tmp;

    std::cout << "\nȥ�غ�����Ϊ��" << '\n';
    iter = arr.begin();
    while (k >= 0) {
        std::cout << *(iter++) << ' ';
        -- k;
    }
    std::cout << '\n';

    return 0;
}
