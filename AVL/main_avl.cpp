#include "avl.hpp"
#include <iostream>

int main() {
    AVL tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    tree.print();

    std::cout << "height: " << tree.getHeight() << std::endl;

    int searchVal = 25;

    tree.remove(40);

    tree.print();


    return 0;
}

