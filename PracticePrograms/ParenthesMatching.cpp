#include "ParenthesMatching.h"
#include <stack>
#include <cctype>
//-----------------------------------------------------------------------------

bool ParenthesisMatching(char* expression)
{
    std::stack<char> stack;
    int index = 0;
    while (expression[index] != '\0')
    {
        if (expression[index] == '(')
            stack.push(expression[index]);
        else if (expression[index] == ')')
        {
            if (stack.empty())
                return false;

            stack.pop();
        }
        ++index;
    }

    return stack.empty();
}

//-----------------------------------------------------------------------------

bool Match(const char open, const char close)
{
    if (open == '(' && close == ')')
    {
        return true;
    }
    else if (open == '{' && close == '}')
    {
        return true;
    }
    else if(open == '[' && close == ']')
    {
        return true;
    }

    return false;
}

//-----------------------------------------------------------------------------

bool MultiParenthesisMatching(char* expression)
{
    std::stack<char> stack;
    int index = 0;

    while (expression[index] != '\0')
    {
        if (expression[index] == '(' || expression[index] == '[' || expression[index] == '{')
        {
            stack.push(expression[index]);
        }
        else if (expression[index] == ')' || expression[index] == ']' || expression[index] == '}')
        {
            if (stack.empty())
                return false;

            if (!Match(stack.top(), expression[index]))
                return false;

            stack.pop();
        }
        ++index;
    }

    return stack.empty();
}

//-----------------------------------------------------------------------------

bool IsOperator(char character) {
    return character == '+' || character == '-' || character == '*' || character == '/';
}

//-----------------------------------------------------------------------------


int Precedence(char character) {
    if (character == '*' || character == '/')
        return 3;
    if (character == '+' || character == '-')
        return 2;
    return 0;
}

//-----------------------------------------------------------------------------

char* InfixToPostFix(char* expression) 
{
    std::stack<char> stack;
    size_t size = std::strlen(expression);
    char* postFix = new char[size + 1];
    int i = 0, k = 0;

    while (expression[i] != '\0') {
        if (std::isalnum(expression[i])) 
        {
            postFix[k++] = expression[i++];
        }
        else if (expression[i] == '(') 
        {
            stack.push(expression[i++]);
        }
        else if (expression[i] == ')') 
        {
            while (!stack.empty() && stack.top() != '(') 
            {
                postFix[k++] = stack.top();
                stack.pop();
            }
            if (!stack.empty() && stack.top() == '(') {
                stack.pop();
            }
            i++;
        }
        else if (IsOperator(expression[i])) 
        {
            while (!stack.empty() && Precedence(stack.top()) >= Precedence(expression[i])) {
                postFix[k++] = stack.top();
                stack.pop();
            }
            stack.push(expression[i++]);
        }
    }

    while (!stack.empty()) {
        postFix[k++] = stack.top();
        stack.pop();
    }

    postFix[k] = '\0'; // Null-terminate the postfix expression
    return postFix;
}
//-----------------------------------------------------------------------------

