#include <bits/stdc++.h>
using namespace std;


int symbol_to_num(char c) {
    switch (c) {
        case '+':
            return 1;
        case '-':
            return 2;
        case '*':
            return 3;
        case '/':
            return 4;
        case '^':
            return 5;
        case '!':
            return 6;
        case '(':
            return 7;
        case ')':
            return 0;
    }
}

void push_symbol_to_stack(char c, stack<char> &sc, vector<string> &output) {
    if (sc.empty())
        sc.push(c);
    else {
        if (symbol_to_num(c) > symbol_to_num(sc.top()))
            sc.push(c);
        else if (c == ')') {
            while (sc.top() != '(') {
                string temp(1, sc.top());
                output.push_back(temp);
                sc.pop();
            }
            sc.pop();
        }
        else {
            if (sc.top() == '(')
                sc.push(c);
            else {
                string temp(1, sc.top());
                output.push_back(temp);
                sc.pop();
                push_symbol_to_stack(c, sc, output);
            }
        }
    }
}

vector<string> transfer(string s) {
    vector<string> output;
    stack<char> sc;
    string temp;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (isdigit(c) || c == '.') {
            temp += c;
        }
        else {
            if (temp.size())
                output.push_back(temp);
            else if (c == '-' && i > 0 && s[i - 1] != ')') {//deal with negative sign
                temp += c;
                continue;
            }
            temp.clear();
            push_symbol_to_stack(c, sc, output);
        }
    }
    if (temp.size())
        output.push_back(temp);
    temp.clear();
    while (!sc.empty()) {
        temp += sc.top();
        output.push_back(temp);
        temp.clear();
        sc.pop();
    }
    return output;
}

double solution(vector<string> vs) {
    stack<string> NumStack;
    for (auto s : vs) {
        if (s == "+") {
            double b = stod(NumStack.top());
            NumStack.pop();
            double a = stod(NumStack.top());
            NumStack.pop();
            double res = a + b;
            NumStack.push(to_string(res));
        }
        else if (s == "-") {
            double b = stod(NumStack.top());
            NumStack.pop();
            double a = stod(NumStack.top());
            NumStack.pop();
            double res = a - b;
            NumStack.push(to_string(res));
        }
        else if (s == "*") {
            double b = stod(NumStack.top());
            NumStack.pop();
            double a = stod(NumStack.top());
            NumStack.pop();
            double res = a * b;
            NumStack.push(to_string(res));
        }
        else if (s == "/") {
            double b = stod(NumStack.top());
            NumStack.pop();
            double a = stod(NumStack.top());
            NumStack.pop();
            double res = a / b;
            NumStack.push(to_string(res));
        }
        else if (s == "^") {
            double b = stod(NumStack.top());
            NumStack.pop();
            double a = stod(NumStack.top());
            NumStack.pop();
            double res = pow(a, b);
            NumStack.push(to_string(res));
        }
        else {
            NumStack.push(s);
        }
    }
    return stod(NumStack.top());
}
#include "libRPN.h"
