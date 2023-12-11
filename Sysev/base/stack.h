#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include<map>
#include "stack.h"

using namespace std;

class TPostfix
{
    string infix;
    string postfix;
public:
    TPostfix(string s = "0")
    {
        for (auto i : s) if (i != ' ') infix += i;
    }
    string GetInfix() { return infix; }
    string GetPostfix() { return postfix; }
    string ToPostfix()
    {
        map<char, int> pr;
        pr['('] = 0;
        pr[')'] = 0;
        pr['+'] = 1;
        pr['-'] = 1;
        pr['*'] = 2;
        pr['/'] = 2;
        int kol = 0;
        TStack<char> si;
        string s = "";
        for (auto i : infix) if (i != ' ')s += i;

        char last = ' ';

        for (auto i : s)
        {
            if (i >= '0' && i <= '9')
            {
                if (last == ')')
                {
                    if (si.empty()) si.push('*');
                    if (pr[si.get_top()] < pr['*']) si.push('*');
                    else
                    {
                        while (!si.empty() && pr[si.get_top()] >= pr['*']) postfix += si.pop();
                        si.push('*');
               
                    }
                    postfix += i;
                    last = i;
                    continue;
                }
                if (i != '0') postfix += i;
                else
                {
                    if (last == '/') throw "div zero!";
                    else postfix += i;
                }
            }
            else
            {
                if (i == '(')
                {
                    if (last >= '0' && last <= '9')
                    {
                        if (si.empty()) si.push('*');
                        if (pr[si.get_top()] < pr['*']) si.push('*');
                        else
                        {
                            while (!si.empty() && pr[si.get_top()] >= pr['*']) postfix += si.pop();
                            si.push('*');

                        }
                    }
                    si.push(i), ++kol;
                }
                else
                {
                    if (i == ')')
                    {
                        --kol;
                        if (kol < 0) throw "error";
                        while (!si.empty() && si.get_top() != '(') postfix += si.pop();
                        si.pop();
                    }
                    else
                    {
                        if (i == '+' || i == '-' || i == '*' || i == '/')
                        {
                            if (last == '(' || last == ' ')
                            {
                                if (i == '*' || i == '/') throw "error";
                                else
                                {
                                    postfix += '0';
                                    si.push(i);
                                }
                            }
                            else
                            {
                                if (last >= '0' && last <= '9' || last == ')')
                                {
                                    if (si.empty()) { si.push(i); last = i; continue; }
                                    if (pr[si.get_top()] < pr[i]) si.push(i);
                                    else
                                    {
                                        while (!si.empty() && pr[si.get_top()] >= pr[i]) postfix += si.pop();
                                        si.push(i);
                                    }
                                }
                                else throw "error";
                            }
                        }
                    }
                }

            }
            last = i;
        }

        if (kol > 0) throw "error";
        while (!si.empty()) postfix += si.pop();

        return postfix;
    };
    double Calculate()
    {

        double ans = 0;
        TStack<double> si;
        for (auto i : postfix)
        {
            if (i != ' ')
            {
                if (i >= '0' && i <= '9')
                {
                    double a = i - '0';
                    si.push(a);
                }
                else
                {
                    double x, y;
                    if (!si.empty()) x = si.pop();
                    if (!si.empty()) y = si.pop();

                    if (i == '/')
                    {
                        if (y - 0 < 1e-8) throw "error";
                        else si.push(y / x);
                    }
                    if (i == '*') si.push(x * y);
                    if (i == '-') si.push(y - x);
                    if (i == '+') si.push(x + y);
                }
            }
        }

        return si.pop();
    };
};

#endif
