#include "calculate.h"
#include "arithmetictree.h"
#include <sstream>
#include <algorithm>
#include <stack>
#include <cctype>

//ignores variable x and operator ^ when converting to postfix
//formats string "coe*x^pow  operator  coe*x^pow"  in form "coe*x^pow  coe*x^pow  operator"
std::string infixToPostfixDifferentiate(const std::string &infix) {

    std::ostringstream outSS;
    std::stack<char> operators;

    bool operatorPossible = true;

    char curr;
    for(auto it = infix.begin(); it != infix.end(); ++it) {
        curr = *it;
        if(isdigit(curr) || curr == 'x' || curr == '^') {
            outSS << curr;
            operatorPossible = true;
        }
        else if(curr == '(') {
            if(!operatorPossible) {
                return "error";
            }
            operatorPossible = false;
            operators.push(curr);
        }
        else if(curr == ')') {
            while(operators.top() != '(') {
                outSS << operators.top() << " ";
                operators.pop();
            }
            operators.pop();
            operatorPossible = true;
        }
        else {
            if(!operatorPossible) {
                return "error";
            }
            operatorPossible = false;
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
        outSS << " " << operators.top();
        operators.pop();
    }
    return outSS.str();

}

//formats in standard postfix
std::string infixToPostfixOperate(const std::string &infix) {

    std::ostringstream outSS;
    std::stack<char> operators;

    bool operatorPossible = true;

    char curr;
    for(auto it = infix.begin(); it != infix.end(); ++it) {
        curr = *it;
        if(isdigit(curr) || curr == '.') {
            outSS << curr;
            operatorPossible = true;
        }
        else if(curr == '(') {
            if(!operatorPossible) {
                return "error";
            }
            operatorPossible = false;
            operators.push(curr);
        }
        else if(curr == ')') {
            while(operators.top() != '(') {
                outSS << operators.top() << " ";
                operators.pop();
            }
            operators.pop();
            operatorPossible = true;
        }
        else {
            if(!operatorPossible) {
                return "error";
            }
            operatorPossible = false;
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
        outSS << " " << operators.top();
        operators.pop();
    }
    return outSS.str();

}

double evaluatePostfix(const std::string &postfix) {
    std::istringstream inSS(postfix);
    std::stack<double> operands;
    double rightOperand;
    double leftOperand;
    std::string next;

    while(inSS >> next) {
        if(std::isdigit(next.at(0))) {
            operands.push(std::stod(next));
        }
        else {
            rightOperand = operands.top();
            operands.pop();
            leftOperand = operands.top();
            operands.pop();
            operands.push(operate(next, leftOperand, rightOperand));
        }
    }
    return operands.top();
}

double operate(const std::string &operand, double leftOperand, double rightOperand) {
    if(operand == "+") {
        return leftOperand + rightOperand;
    }
    else if(operand == "-") {
        return leftOperand - rightOperand;
    }
    else if(operand == "*") {
        return leftOperand * rightOperand;
    }
    else if(operand == "/") {
        return leftOperand / rightOperand;
    }
    else if(operand == "^") {
        int i = static_cast<int>(rightOperand);
        double output = leftOperand;
        for(int j = 1; j < i; j++) {
            output *= leftOperand;
        }
        return output;
    }
    else {
        return -1;
    }
}

std::string integrate(const std::string &input) {
    //TODO
    return "";
}


std::string differentiate(const std::string &input) {
    if(input.empty()) {
        return "error";
    }

    std::string postfix = infixToPostfixDifferentiate(input);

    if(postfix == "error") {
        return postfix;
    }

    ArithmeticTree tree(postfix);
    return tree.differentiate();
}

std::string evaluate(const std::string &input) {
    if(input.empty()) {
        return "error";
    }
    std::string postfix = infixToPostfixOperate(input);
    if(postfix == "error") {
        return postfix;
    }
    else {
        return std::to_string(evaluatePostfix(postfix));
    }
}

std::string removeSpaces(std::string &str) {
    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());
    return str;
}

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
