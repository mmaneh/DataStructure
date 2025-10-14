#include "avl.hpp"
#include <iostream>

int AVL::height_helper(Node* node) {
    if (!node) return 0;
    return 1 + std::max(height_helper(node->left), height_helper(node->right));
}

int AVL::getHeight(Node* node) {
    return height_helper(node);
}

int AVL::getHeight() {
    return height_helper(root);
}

Node* AVL::rightRotate(Node* node) {
    Node* y = node->left;
    Node* t3 = y->right;
    y->right = node;
    node->left = t3;
    return y; 
}

Node* AVL::leftRotate(Node* node) {
    Node* y = node->right;
    Node* t3 = y->left;
    y->left = node;
    node->right = t3;
    return y;
}

int AVL::getBalanceFactor(Node* node) {
    return getHeight(node->left) - getHeight(node->right);
}

void AVL::print_helper(Node* root) {
    if (!root) return;
    print_helper(root->left);
    std::cout << root->val << " ";
    print_helper(root->right);
}

Node* AVL::insert_helper(Node* node, int val) {
    if (!node) return new Node(val);
    if (val < node->val)
        node->left = insert_helper(node->left, val);
    else if (val > node->val)
        node->right = insert_helper(node->right, val);
    else
        return node;

    int bf = getBalanceFactor(node);
    if (bf > 1 && val < node->left->val)
        return rightRotate(node);
    if (bf < -1 && val > node->right->val)
        return leftRotate(node);
    if (bf > 1 && val > node->left->val) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (bf < -1 && val < node->right->val) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

Node* AVL::insert(int val) {   
    root = insert_helper(root, val);
    return root;   
}

bool AVL::search(int val) {
    if(!root) return false;
    Node* curr = root;
    while(curr) {
        if(curr->val == val) return true;
        if(curr->val < val) curr = curr->right;
        else curr = curr->left;
    }
    return false;
}

Node* AVL::getMin(Node* node) {
    if(!node || !node->left) return node;
    while(node->left) node = node->left;
    return node;
}

Node* AVL::getMax(Node* node) {
    if(!node || !node->right) return node;
    while(node->right) node = node->right;
    return node;
}

Node* AVL::predecessor(Node* root, Node* node) {
    if(node->left) return getMax(node->left);
    Node* pr = nullptr;
    while(root) {
        if(node->val > root->val) {
            pr = root;
            root = root->right;
        } else {
            root = root->left;
        }
    } 
    return pr;
}

Node* AVL::successor(Node* root, Node* node) {
    if(node->right) return getMin(node->right);
    Node* sc = nullptr;
    while(root) {
        if (node->val < root->val) {
            sc = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return sc;
}

Node* AVL::remove_helper(Node* node, int val) {
    if(!node) return nullptr;
    if (node->val < val)
        node->right = remove_helper(node->right, val);
    else if (node->val > val)
        node->left = remove_helper(node->left, val);
    else {
        if (!node->left) return node->right;
        if (!node->right) return node->left;
        Node* tmp = getMin(node->right);
        node->val = tmp->val;
        node->right = remove_helper(node->right, tmp->val);
    }
    int bf = getBalanceFactor(node);
    if (bf > 1 && getBalanceFactor(node->left) >= 0)
        return rightRotate(node);
    else if (bf > 1 && getBalanceFactor(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    else if (bf < -1 && getBalanceFactor(node->right) <= 0)
        return leftRotate(node);
    else if (bf < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

Node* AVL::remove(int val) {
    root = remove_helper(root, val);
    return root;
}

void AVL::print() {
    print_helper(root);
    std::cout << std::endl;
}

