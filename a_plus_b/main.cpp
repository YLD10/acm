/*************************************************************************
	> File Name: a_plus_b.cpp
	> Author: YLD10
	> Mail: yl1315348050@yahoo.com
	> Created Time: 4/14/ÐÇÆÚÁù 9:32:25
	> Describe: Calculate a + b.
    > Sample Input:
                   1 5
                   2 3
    > Sample Output:
                    6
                    5
 ************************************************************************/

#include <iostream>
#include <limits>

int main()
{
  int a = 0, b = 0;

  while (std::cin >> a >> b) {
    std::cout << a+b << '\n';
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return 0;
}
