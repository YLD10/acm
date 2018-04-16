/*************************************************************************
	> File Name: drop_duplicate.cpp
	> Author: YLD10
	> Mail: yl1315348050@yahoo.com
	> Created Time: 4/15/星期日 22:22:44
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
        while (' ' == std::cin.peek())  // 吸收掉换行符前的空格
            std::cin.get();

        arr.push_back(a);

        if ('\n' == std::cin.peek())
            break;
    }

    std::cout << "\n原数组为：" << '\n';
    std::vector<Elemtype>::iterator iter = arr.begin();
    for (; iter != arr.end(); ++ iter) {
        std::cout << *iter << ' ';
    }
    std::cout << '\n';

    if (!is_sorted(arr.begin(), arr.end())) {
        std::sort(arr.begin(), arr.end());  // 进行排序

        std::cout << "\n排序后数组为：" << '\n';
        iter = arr.begin();
        for (; iter != arr.end(); ++ iter) {
            std::cout << *iter << ' ';
        }
        std::cout << '\n';
    }

#if 0
    tmp 指向遇到的一组重复元素的第一个数，cur 往后走直到走出这组重复元素
    tmp 与 cur 不同的时候保留 tmp 的值到数组下标为 k 的位置，每保存一次 k 自增
    k 最后会是去重后数组的大小
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

    std::cout << "\n去重后数组为：" << '\n';
    iter = arr.begin();
    while (k >= 0) {
        std::cout << *(iter++) << ' ';
        -- k;
    }
    std::cout << '\n';

    return 0;
}
