#pragma once

// Base class for all arithmetic tree nodes
class TreeNode {
public:
    // Virtual destructor is necessary so derived classes
    // are properly destroyed.
    virtual ~TreeNode() = 0;
    // Computes the value of this node
    virtual int evaluate() const = 0;
    // Displays this node at depth
    virtual void draw(char link, int depth) const = 0;
};

class BinaryOperatorNode: public TreeNode {
protected:
    char symbol;            // Printable symbol (+, *, -, /)
    const TreeNode *left;   // Points to left subtree
    const TreeNode *right;  // Points to right subtree
public:
    // Initializes a BinaryOperatorNode object
    BinaryOperatorNode(char symbol, const TreeNode *left, const TreeNode *right);
    ~BinaryOperatorNode() override;
    void draw(char link, int depth) const override;
};

class AdditionNode: public BinaryOperatorNode {
public:
    AdditionNode(const TreeNode *left, const TreeNode *right);
    int evaluate() const override;
};

class MultiplicationNode: public BinaryOperatorNode {
public:
    MultiplicationNode(const TreeNode *left, const TreeNode *right);
    int evaluate() const override;
};

class SubtractionNode: public BinaryOperatorNode {
public:
    SubtractionNode(const TreeNode *left, const TreeNode *right);
    int evaluate() const override;
};

class DivisionNode: public BinaryOperatorNode {
public:
    DivisionNode(const TreeNode *left, const TreeNode *right);
    int evaluate() const override;
};

class NumberNode: public TreeNode {
protected:
    int value;
public:
    NumberNode(int value);
    int evaluate() const override;
    void draw(char link, int depth) const override;

};
