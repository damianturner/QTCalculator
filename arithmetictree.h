#ifndef ARITHMETICTREE_H
#define ARITHMETICTREE_H

#include <string>
#include <memory>
#include <sstream>

class ArithmeticTree
{
    struct TreeNode {
        std::unique_ptr<TreeNode> right;
        std::unique_ptr<TreeNode> left;

        int coefficient;
        int power;
        char operatorType;

        TreeNode(int coe, int pow):coefficient(coe),power(pow),right(nullptr), left(nullptr),operatorType('\0') {}
        TreeNode(char ch):coefficient(0),power(0),right(nullptr), left(nullptr), operatorType(ch) {}
        bool isLeaf() {
            return left == nullptr && right == nullptr;
        }
        std::string operand() {
            std::ostringstream outSS;
            outSS << coefficient << "x^" << power;
            return outSS.str();
        }
    };
public:
    ArithmeticTree(std::string input);
    std::string differentiate();

private:
    std::unique_ptr<TreeNode> root;
    std::string differentiate(TreeNode* curr);
};

#endif // ARITHMETICTREE_H
