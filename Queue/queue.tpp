#ifndef QUEUE_TPP
#define QUEUE_TPP
#include "queue.hpp"

template <typename T> 
void Queue<T>::push(const T& value) {
    vec.push_back(value);
}

template <typename T>
void Queue<T>::pop() {
    vec.pop_front();
} 

template <typename T>
const T& Queue<T>::top() {
    return vec.front();
}
 
#endif