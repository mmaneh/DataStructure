#include "bst.hpp"
#include <iostream>
Node* BST::insert_helper(Node* node, int val) {
    if (!node) return new Node(val);
    if (node->val > val) {
        node->left = insert_helper(node->left, val);
    }else {
        node->right = insert_helper(node->right, val);
    }
    return node;
}
Node* BST::insert(int val) {

    
    root = insert_helper(root,val);
    return root;   
}

bool BST::search(int val) {
    if(!root) return false;
    Node* curr = root;
    while(curr) {
        if(curr->val == val) return true;
        if(curr->val < val) curr = curr->right;
        else curr = curr->left;
    }
    return false;
}
Node* BST::getMin(Node* node) {
    if(!node || !node->left) return node;
    while(node->left) node = node->left;
    return node;
}
Node* BST::getMax(Node* node) {
    if(!node || !node->right) return node;
    while(node->right) node = node->right;
    return node;
}
Node* BST::predecessor(Node* root,Node* node) {
    if(node->left) return getMax(node->left);
    Node* pr = nullptr;
    while(root) {
        if(node->val > root->val) {
            pr = root;
            root = root->right;
        }else {
            root = root->left;
        }
    } 
    return pr;
}
Node* BST::successor(Node* root, Node* node) {
    if(node->right) return getMin(node->right);
    Node* sc = nullptr;
    while(root) {
        if (node->val < root->val) {
            sc = root;
            root = root->left;
        }else {
            root = root->right;
        }
    }
    return sc;
}
Node* BST::remove_helper(Node* node, int val) {
    if(!node) return nullptr;
    if (node->val < val) {
        node->right = remove_helper(node->right,val);
    }
    else if (node->val > val) {
        node->left = remove_helper(node->left,val);
    }
    else {
        if (!node->left) return node->right;
        if(!node->right) return node->left;
        Node* tmp = getMin(node->right);
        node->val = tmp->val;
        node->right = remove_helper(node->right,tmp->val);
    }
    return node;
}
Node* BST::remove(int val) {
    root =  remove_helper(root,val);
    return root;
}
int BST::height_helper(Node* node) {
    if (!node) return 0;
    return 1 + std::max(height_helper(node->left), height_helper(node->right));
}

int BST::getHeight() {
    return height_helper(root);
}
void BST::print_helper(Node* root) {
    if (!root) return;
    print_helper(root->left);
    std::cout << root->val << " ";
    print_helper(root->right);
}
void BST::print() {
    print_helper(root);
    std::cout << std::endl;
}
