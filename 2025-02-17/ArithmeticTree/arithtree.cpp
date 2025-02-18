#include <iostream>
#include "arithtree.h"

TreeNode::~TreeNode() {}

// Initializes a BinaryOperatorNode object
BinaryOperatorNode::BinaryOperatorNode(char symbol, 
                                       const TreeNode *left, 
                                       const TreeNode *right):
        symbol(symbol), left(left), right(right) {}

// Destroying a BinaryOperatorNode object cleans up its subtrees
BinaryOperatorNode::~BinaryOperatorNode() {
    delete left;
    delete right;
}

// Helper function for drawing
static void tab(int n) {
    for (int i = 0; i < n; i++) {
        std::cout << ' ';
    }
}

void BinaryOperatorNode::draw(char link, int depth) const {
    right->draw('/', depth + 5);
    tab(depth);
    std::cout << link << '(' << symbol << ")\n";
    left->draw('\\', depth + 5);
}

// Initializes an AdditionNode object
AdditionNode::AdditionNode(const TreeNode *left, 
                           const TreeNode *right):
        BinaryOperatorNode('+', left, right) {}

int AdditionNode::evaluate() const {
    return left->evaluate() + right->evaluate();
}

MultiplicationNode::MultiplicationNode(const TreeNode *left, 
                                       const TreeNode *right):
        BinaryOperatorNode('*', left, right) {}

int MultiplicationNode::evaluate() const {
    return left->evaluate() * right->evaluate();
}

SubtractionNode::SubtractionNode(const TreeNode *left, 
                                 const TreeNode *right):
        BinaryOperatorNode('-', left, right) {}

int SubtractionNode::evaluate() const {
    return left->evaluate() - right->evaluate();
}

DivisionNode::DivisionNode(const TreeNode *left, 
                           const TreeNode *right):
        BinaryOperatorNode('/', left, right) {}

int DivisionNode::evaluate() const {
    return left->evaluate() / right->evaluate();
}

NumberNode::NumberNode(int value): value(value) {}

int NumberNode::evaluate() const {
    return value;
}

void NumberNode::draw(char link, int depth) const {
    tab(depth);
    std::cout << link << "[" << value << "]\n";

}
