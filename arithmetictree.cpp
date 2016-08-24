#include "arithmetictree.h"
#include <sstream>
#include <stack>
#include <cctype>

ArithmeticTree::ArithmeticTree(std::string input)
{
    std::istringstream inSS;
    std::stack<std::unique_ptr<TreeNode> > nodes;

    std::string curr;
    std::unique_ptr<TreeNode> currPtr;
    int coe;
    int pow;
    while(inSS >> curr) {
        coe = 0;
        pow = 0;
        if(curr.at(0) != 'x' || !std::isdigit(curr.at(0))) {
            currPtr = std::make_unique<TreeNode>(curr.at(0));
            currPtr->right = std::move(nodes.top());
            nodes.pop();
            currPtr->left = std::move(nodes.top());
            nodes.pop();
        }
        else {
            int i = 0;
            while(std::isdigit(curr.at(i))) {
                ++i;
            }
            if(i > 0) {
                coe = std::stoi(curr.substr(0,i));
                curr = curr.substr(i, curr.size()-i);
            }
            else {
                coe = 1;
            }
            if(curr.size() == 1) {
                pow = 1;
            }
            else {
                pow = std::stoi(curr.substr(2));
            }
            currPtr = std::make_unique<TreeNode>(coe, pow);
        }
        nodes.push(currPtr);
    }
    root = std::move(nodes.top());
}

std::string ArithmeticTree::differentiate() {
    return differentiate(root.get());
}

std::string ArithmeticTree::differentiate(TreeNode* curr) {
    std::ostringstream outSS;
    if(!curr->isLeaf()) {
        if(curr->operatorType == '+') {
            outSS << differentiate(curr->left.get()) << " + " << differentiate(curr->right.get());
        }
        else if(curr->operatorType == '-') {
            outSS << differentiate(curr->left.get()) << " - " << differentiate(curr->right.get());
        }
        else if(curr->operatorType == '*') {
            outSS << differentiate(curr->left.get()) << " * " << curr->right->operand() << " + " << differentiate(curr->right.get())
                  << " * " << curr->left->operand();
        }
        else {
            outSS << "(" << differentiate(curr->left.get()) << " * " << curr->right->operand() << ") - (" <<
                     differentiate(curr->right.get()) << " * " << curr->left->operand()
                                             << ") / (" << curr->right->operand() << ")^2";
        }
    }
    else {
        if(curr->power == 0) {
            outSS << "0";
        }
        if(curr->power == 1) {
            outSS << std::to_string(curr->coefficient);
        }

        outSS << curr->power * curr->coefficient << "x^" << curr->power - 1;
    }
    return outSS.str();
}
