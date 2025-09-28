#include "stack.hpp"
#include <iostream>

int main() {
    Stack<int> st;
    st.push(1);
    st.push(3);
    std::cout << st.top() << std::endl;
    st.pop();
    std::cout << st.top() << std::endl;
}