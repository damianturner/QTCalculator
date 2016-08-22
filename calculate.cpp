#include "calculate.h"
#include <sstream>
#include <algorithm>
#include <stack>
#include <cctype>



std::string infixToPostfix(const std::string &infix) {

    std::ostringstream outSS;
    std::stack<char> operators;

    char curr;
    for(auto it = infix.begin(); it != infix.end(); ++it) {
        curr = *it;
        if(isdigit(curr)) {
            outSS << curr;
        }
        else if(curr == '(') {
            operators.push(curr);
        }
        else if(curr == ')') {
            while(operators.top() != '(') {
                outSS << operators.top() << " ";
                operators.pop();
            }
            operators.pop();
        }
        else {
            outSS << " "; //will seperate digits greater than 9 with space
            if(operators.empty() || operators.top() == '(') {
                operators.push(curr);
            }
            else {
                while(!operators.empty() && operators.top() != '('
                    && (leftAssociative(curr) && precedence(curr) <= precedence(operators.top())) || (!leftAssociative(curr) && precedence(curr) < precedence(operators.top()))) {
                            outSS << operators.top() << " ";
                            operators.pop();
                    }
                operators.push(curr);
            }
        }
    }
    while(!operators.empty()) {
        outSS << " " <<operators.top();
        operators.pop();
    }
    return outSS.str();

}

double evaluatePostfix(const std::string &postfix) {

}

std::string removeSpaces(std::string &str) {
    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());
    return str;
}

std::string integrate(const std::string &input);
std::string differentiate(const std::string &input);
std::string evaluate(const std::string &input);

bool leftAssociative(char c) {
    if(c == '^') return false;
    return true;
}

int precedence(char c) {
    if(c == '^') {
        return 4;
    }
    if(c == '*' || c == '/') {
        return 3;
    }
    if(c == '+' || c == '-') {
        return 2;
    }
    return -1;
}
