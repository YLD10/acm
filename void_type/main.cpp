/*************************************************************************
	> File Name: void_type.cpp
	> Author: YLD10
	> Mail: yl1315348050@yahoo.com
	> Created Time: 4/15/ÐÇÆÚÈÕ 23:52:38
	> Describe: void type test.
 ************************************************************************/

#include <iostream>
#include <typeinfo>
// using namespace std;

enum{
  a
}b;

int main()
{
    std::cin >> b;
    typeid(std::cin.peek()) == typeid(char) ? std::cout << '1' : std::cout << '0';
    return 0;
}
