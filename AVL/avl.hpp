#ifndef AVL_HPP
#define AVL_HPP
#include <algorithm>

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

class AVL {
private: 
    Node* root;
    Node* insert_helper(Node* node, int val);
    Node* remove_helper(Node* node, int val); 
    int height_helper(Node* node); 
    void print_helper(Node* node);

public: 
    AVL() : root{nullptr} {}
    AVL(Node* node) : root{node} {}
    ~AVL() {}

    Node* insert(int val);
    Node* remove(int val);
    bool search(int val);

    int getHeight();
    int getHeight(Node* node);

    Node* getMin(Node* node);
    Node* getMax(Node* node);
    Node* successor(Node* root, Node* node);
    Node* predecessor(Node* root, Node* node);

    void print();

    int getBalanceFactor(Node* node);
    Node* rightRotate(Node* node);
    Node* leftRotate(Node* node);
};

#endif

