#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H

#include <string>

std::string infixToPostfix(const std::string &infix);
double evaluatePostfix(const std::string &postfix);
std::string removeSpaces(std::string &input);

std::string integrate(const std::string &input);
std::string differentiate(const std::string &input);
std::string evaluate(const std::string &input);

bool leftAssociative(char c);
int precedence(char c);

#endif // SHUNTINGYARD_H
