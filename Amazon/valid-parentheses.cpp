#include <stack>
#include <iostream>

using namespace std;

/*
    Solução boa em runtime, mas pode melhorar em espaço:

    1 - usar uma stack baseada em vector: std::stack<char, std::vector<char>> stack;
    2 - usar uma string como stack: push_back() e pop_back()

    Um early return para string de tamanho ímpar também faz sentido
*/


class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack;

        for(char c : s){
            if(c == '(' || c == '{' || c == '[')
                stack.push(c);
            else if(isMatch(stack, c))
                stack.pop();
            else
                return false;
        }

        if(!stack.empty())
            return false;
        return true;
    }

private:
    bool isMatch(std::stack<char> &s, char c)
    {
        if(s.empty())
            return false;

        if (s.top() == '(' && c == ')')
            return true;

        if (s.top() == '[' && c == ']')
            return true;

        if (s.top() == '{' && c == '}')
            return true;

        return false;
    }
};