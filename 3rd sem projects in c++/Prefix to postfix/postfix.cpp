#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int main()
{
    map<char, int> op;
    static int expTop;
    int stackTop, i = 9;
    string ExpIn;
    string stack;
    string postfix;
    op.insert({{'(', 1}, {')', 7}, {'/', 5}, {'*', 5}, {'%', 5}, {'+', 4}, {'-', 4}});
    cout << "Enter expression ";
    getline(cin, ExpIn);
    for (char a : ExpIn)
    {
        if (a == '/' || a == '*' || a == '+' || a == '-' || a == '%' || a == '(' || a == ')')
        {
            for (auto o : op)
            {
                if (a == o.first)
                {
                    expTop = o.second;
                }
                if ((stack.back()) == o.first)
                {
                    stackTop = o.second;
                }
            }

            if ((stack.empty() || expTop > stackTop) && a != ')')
            {
                stack.push_back(a);
            }
            else if (expTop <= stackTop)
            {
                if (expTop == 1)
                {
                    stack.push_back(a);
                }
                else
                {
                    postfix.push_back(stack.back());
                    stack.pop_back();
                    stack.push_back(a);
                }
            }
            else if (a == ')')
            {
                while (stack.back() != '(' && i)
                {
                    postfix.push_back(stack.back());
                    stack.pop_back();
                    i--;
                }
                stack.pop_back();
            }
        }
        else
        {
            postfix.push_back(a);
        }
    }
    for (auto g : stack)
    {
        postfix.push_back(stack.back());
        stack.pop_back();
    }

    cout << postfix;

    
    return 0;
}