#ifndef STACK_HPP
#define STACK_HPP
#include <vector>
template <typename T>
class Stack {
    private:
        std::vector<T> vec;
    public: 
        Stack() {};
        void push(const T& value);
        T pop();
        const T& top();
        bool empty() const {
            return vec.empty();
        };
};
#include "stack.tpp"
#endif