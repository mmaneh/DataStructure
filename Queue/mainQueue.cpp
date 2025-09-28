#include "queue.hpp"
#include <iostream>

int main() {
    Queue<int> queue;
    queue.push(5);
    queue.push(4);
    queue.push(6);
    queue.push(8);
    std::cout << queue.top() << std::endl;
    queue.pop();
    std::cout << queue.top() << std::endl;
}