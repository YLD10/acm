/*************************************************************************
	> File Name: infix2suffix.cpp
	> Author: YLD10 
	> Mail: yl1315348050@yahoo.com
	> Created Time: 4/18/星期三 16:40:21
    > Describe: infix transform to suffix.
 ************************************************************************/

#include <iostream>
#include <limits>
#include <vector>
#include <stack>
// using namespace std;

typedef char Elemtype;

bool bracket(std::vector<Elemtype> &arr); 

bool infix2suffix(std::vector<Elemtype> &arr)
{
    std::stack<Elemtype> suf;
    std::stack<Elemtype> opchar;
    std::vector<Elemtype>::iterator iter = arr.begin();

    for (; iter != arr.end(); ++ iter) {
        if (*iter >= '0' && *iter <= '9')
            suf.push(*iter);
        else if (*iter == '(')
            opchar.push(*iter);
        else if (*iter == ')') {
            while (opchar.top() != '(') {
                suf.push(opchar.top());
                opchar.pop();
            }
            opchar.pop();
        }
        else if (*iter == '+' || *iter == '-' || *iter == '*' || *iter == '/') {
            if (opchar.empty())
                opchar.push(*iter);
            else {
                if ((*iter == '*' || *iter == '/') && (opchar.top() == '+' || opchar.top() == '-'))
                    opchar.push(*iter);
                else { 
                    while (!opchar.empty() && opchar.top() != '(') {
                        suf.push(opchar.top());
                        opchar.pop();
                    }
                    opchar.push(*iter);
                }
            }
        }
        else
            return false;
    }
    while (!opchar.empty()) {
        suf.push(opchar.top());
        opchar.pop();
    }
    while (!suf.empty()) { 
        opchar.push(suf.top());
        suf.pop(); 
    } 

    std::cout << '\n'; 
    while (!opchar.empty()) {
        std::cout << opchar.top();
        opchar.pop();
    }

    return true;
}

int main()
{

    std::vector<Elemtype> arr;
    Elemtype tmp = 0;

    while (std::cin >> tmp) {
        while (' ' == std::cin.peek()) // 屏蔽空格
           std::cin.get();

        arr.push_back(tmp);
        if ('\n' == std::cin.peek())
            break;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<Elemtype>::iterator iter = arr.begin();
    for (; iter != arr.end(); ++ iter)
        std::cout << *iter;
    
    if (bracket(arr)) {
        if (!infix2suffix(arr))
            std::cout << "\nFalse";
    }else
        std::cout << "\nBracket no match!";
    
    return 0;
}
