#ifndef BST_HPP
#define BST_HPP
#include <algorithm>
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val) : val{val}, left{nullptr}, right{nullptr} {}
};
class BST {
    private: 
        Node* root;
        Node* insert_helper(Node * node,int val);
        Node* remove_helper(Node* node, int val); 
        int height_helper(Node* node); 
    	void print_helper(Node* node);
    public: 
        BST() : root{nullptr} {}
        BST(Node* node) : root{node} {}
        ~BST() {}
        Node* insert(int val);
        Node* remove(int val);
        bool search(int val);
        int getHeight();
        Node* getMin(Node* node);
        Node* getMax(Node* node);
        Node* successor(Node* root,Node* node);
        Node* predecessor(Node* root, Node* node);
	void print();
	
};
#endif
