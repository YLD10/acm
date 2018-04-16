/*************************************************************************
	> File Name: find_duplicate.cpp
	> Author: YLD10
	> Mail: yl1315348050@yahoo.com
	> Created Time: 4/14/ĞÇÆÚÁù 21:32:25
	> Describe: An array of length n, with address from 1 to n inclusive,
                contains entries from the set {1,2,...,n-1} and there's
                exactly some elements with the same value. Your task is to
                find out those value.
    > Sample Input:
                    2
                    1 1
                    4
                    1 2 3 2
    > Sample Output:
                    1
                    2
 ************************************************************************/

#include <iostream>
#include <limits>
#include <algorithm>
#include <set>
// using namespace std;

int main()
{
    int n = 0;

    while (std::cin >> n) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        int *arr = new int[n];
        int i = n-1;
        while (i >= 0) {
            std::cin >> arr[i];
            -- i;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::sort(arr, arr+n);
        std::set<int> res;

        i = n-1;
        while (i > 0) {
            if (arr[i] == arr[i-1]) {
                res.insert(arr[i]);
                -- i;
            }
            -- i;
        }

        std::set<int>::iterator iter = res.begin();
        for (; iter != res.end(); ++ iter) {
            std::cout << *iter << '\n';
        }

        delete[] arr;
    }

    return 0;
}
