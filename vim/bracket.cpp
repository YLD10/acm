
/*************************************************************************
> File Name: bracket.cpp
> Author: YLD10
> Mail: yl1315348050@yahoo.com
> Created Time: 4/14/星期六 8:59:41
> describe: 利用栈实现括号匹配检查
************************************************************************/


#include <iostream>
#include <stack>
#include <limits>
#include <vector>
// using namespace std;

bool bracket(std::vector<char> &arr)
{
    bool result = true; // 检查结果
    std::vector<char>::iterator iter = arr.begin();
    std::stack<char> s; // 存放括号的栈

    for (; iter != arr.end(); ++ iter) {
        char c = *iter;
        if ('(' == c || '[' == c || '{' == c) // 判断括号类型
            s.push(c); // 遇见左括号入栈
        else if (s.empty() && (')' == c || ']' == c || '}' == c)) {
                result = false;
                break;
             }else
                 switch (c){
                    case ')':
                        if('(' == s.top()) // 栈顶元素是否为对应左括号
                            s.pop();
                        else
                            result = false;
                        break;
                    case ']':
                        if('[' == s.top())
                            s.pop();
                        else
                            result = false;
                        break;
                    case '}':
                        if('{' == s.top())
                            s.pop();
                        else
                            result = false;
                }
    }
    if(!s.empty()) result = false; // 结束时栈不为空必出错

    return result; 
}
