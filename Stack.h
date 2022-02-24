#ifndef STACK_H
#define STACK_H
#include <iostream>

namespace cop4530 {

    template <typename T>
    class Stack {

    public:

        Stack(); // Default Constructor
        ~Stack(); // Destructor
        Stack(const Stack<T> &); // Copy constructor
        Stack(Stack<T> &&); // Move constructor
        Stack<T> & operator=(const Stack<T> &); // Copy assignment operator
        Stack<T> & operator=(Stack<T> &&); // Move assignment operator
        bool empty() const; // Checks if stack is empty
        void clear(); // Deletes all elements from stack
        void push(const T& x); // Adds to stack - Copy vers.
        void push(T && x); // Adds to stack - move vers.
        void pop(); // Removes recently added element from stack
        T& top(); // Returns reference to recently added element from stack
        const T& top() const; // Accessor that returns recently added element from stack
        int size() const; // Returns number of elements stored in stack
        void print(std::ostream& os, char ofc = ' ') const; // Print elements of stack

    public:
        T * _stack;                 // The "stack"
        int _top;                   // Points to the first empty node
    };

    // Invokes print() method
    template <typename T>
    std::ostream & operator<<(std::ostream & os, const Stack<T> & a);
    // Compares two stacks to test if they are equal
    template <typename T>
    bool operator==(const Stack<T> & a, const Stack<T> & b);
    // Opposite of == operator
    template <typename T>
    bool operator!=(const Stack<T> & a, const Stack<T> & b);
    // Returns true if every element in stack A is smaller than or equal to corresponding elements in stack B
    template <typename T>
    bool operator<=(const Stack<T> & a, const Stack<T> & b);

#include "Stack.hpp"

} // end of namespace 4530

#endif