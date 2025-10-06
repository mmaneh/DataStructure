#include "bst.hpp"
#include <iostream>
#include <cassert>
int main() {
     BST bt;
     bt.insert(20);
     bt.insert(10);
     bt.insert(15);
     bt.insert(5);
     bt.insert(30);

     std::cout << bt.getHeight() << std::endl;
     
     bt.print();
     bt.remove(5);
     bt.print();	
}
