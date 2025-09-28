#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <deque>

template <typename T>
class Queue{
    private:
        std::deque<T> vec;
    public: 
        Queue() {};
        void push(const T& value);
        void pop();
        const T& top();
        bool empty() {
            return vec.empty;
        }
};
#include "queue.tpp"
#endif