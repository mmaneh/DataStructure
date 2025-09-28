#ifndef STACK_TPP
#define STACK_TPP
template <typename T>
void Stack<T>::push(const T& value) {
    vec.push_back(value); 
}

template <typename T>
T Stack<T>::pop() {
    T tmp = vec.top();
    vec.pop_back();
    return tmp;
}

template <typename T>
const T& Stack<T>::top() {
    return vec.back();
}
#include "stack.hpp"
#endif



