#ifndef CALCULATE_H
#define CALCULATE_H

#include <string>

std::string infixToPostfixOperate(const std::string &infix);
std::string infixToPostfixDifferentiate(const std::string &infix);
double evaluatePostfix(const std::string &postfix);
std::string removeSpaces(std::string &input);

std::string integrate(const std::string &input);
std::string differentiate(const std::string &input);
std::string evaluate(const std::string &input);

bool leftAssociative(char c);
int precedence(char c);
double operate(const std::string &operand, double leftOperand, double rightOperand);

#endif // CALCULATE_H
