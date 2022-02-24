// Default Constructor with no parameters that
// allocates arbitrarily large amount of memory for _stack
// virtually limitless, and initializes _top
template<typename T>
Stack<T>::Stack() {
    _stack = new T [10000];
    _top = -1;
}

// Destructor that destroys and
// deallocates the memory for _stack.
template<typename T>
Stack<T>::~Stack() {
    delete [] _stack;
}

// Copy Constructor with one object parameter, x,
// allocates memory for _stack, copies _top variable,
// then copies all of _stack's elements over.
template<typename T>
Stack<T>::Stack(const Stack<T> &x) {
    _stack = new T [10000];
    _top = x._top;
    for(size_t i = 0; i < _top+1; ++i){
        _stack[i] = x._stack[i];
    }
}

// Move Constructor with one object parameter, x,
// that moves over the respective variables
template<typename T>
Stack<T>::Stack(Stack<T> &&x) {
    _stack = new T [10000];
    _top = std::move(x._top);
    for(size_t i = 0; i < _top+1; ++i){
        _stack[i] = std::move(x._stack[i]);
    }
}

// *****************************************************************
// * Function Name:  operator=()                                  *
// * Description:  Assignment operator overload function that      *
// * will copy the contents of one stack object to another.        *
// * Parameter Description:  One const Stack object parameter, x,  *
// * that will copy this object to another object.                 *
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  No References                                    *
// *****************************************************************
template<typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &x) {
    _stack = new T [10000];
    _top = x._top;
    for(size_t i = 0; i < _top+1; ++i){
        _stack[i] = x._stack[i];
    }
}

// *****************************************************************
// * Function Name:  operator=()                                  *
// * Description:  Assignment operator overload function that      *
// * will move the contents of one stack object to another.        *
// * Parameter Description:  One const Stack object parameter, x,  *
// * that will move this object to another object.                 *
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  No References                                    *
// *****************************************************************
template<typename T>
Stack<T> &Stack<T>::operator=(Stack<T> &&x) {
    _stack = new T [10000];
    _top = std::move(x._top);
    for(size_t i = 0; i < _top+1; ++i){
        _stack[i] = std::move(x._stack[i]);
    }
}

// *****************************************************************
// * Function Name:  empty()                                       *
// * Description:  Will return the truth value on whether          *
// * or not the stack is empty.                                    *
// * Parameter Description:   No parameters                        *
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template<typename T>
bool Stack<T>::empty() const {
    return _top == -1;
}

// *****************************************************************
// * Function Name:  clear()                                       *
// * Description: Deletes all elements from stack.                 *
// * Parameter Description:   No parameters                        *
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template<typename T>
void Stack<T>::clear() {
    // Loop through and pop the top element each time
    for(size_t i = 0; i < _top+1; ++i){
        pop();
    }
}

// *****************************************************************
// * Function Name:  push()                                        *
// * Description: Pushes parameter to top of stack                 *
// * Parameter Description: x, used to push to top of stack        *
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template<typename T>
void Stack<T>::push(const T &x) {
    // Increment top and set parameter to top of stack
    ++_top;
    _stack[_top] = x;
}

// *****************************************************************
// * Function Name:  push()                                        *
// * Description: Pushes parameter to top of stack - move ver.     *
// * Parameter Description: x, used to push to top of stack - move *
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template<typename T>
void Stack<T>::push(T &&x) {
    // Increment top and set parameter to top of stack
    ++_top;
    _stack[_top] = std::move(x);
}

// *****************************************************************
// * Function Name:  pop()                                         *
// * Description: Pops top element from stack                      *
// * Parameter Description: No parameters                          *
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template<typename T>
void Stack<T>::pop() {
    // If the stack is empty, output an error, else decrement top
    if(empty()){
        std::cout << "Error: Empty Stack" << std::endl;
    }
    else{
        _top--;
    }
}

// *****************************************************************
// * Function Name:  top()                                         *
// * Description: Returns top of stack                             *
// * Parameter Description: No parameters                          *
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template<typename T>
T &Stack<T>::top() {
    return _stack[_top];
}
// *****************************************************************
// * Function Name:  top()                                         *
// * Description: Returns top of stack - const ver.                *
// * Parameter Description: No parameters                          *
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template<typename T>
const T &Stack<T>::top() const {
    return _stack[_top];
}

// *****************************************************************
// * Function Name:  size()                                        *
// * Description: Returns size of stack                            *
// * Parameter Description: No parameters                          *
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template<typename T>
int Stack<T>::size() const {
    return _top+1;
}

// *****************************************************************
// * Function Name:  print()                                       *
// * Description: Prints all elements of the stack                 *
// * Parameter Description: os - ostream, ofc - delimiter          *
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template<typename T>
void Stack<T>::print(std::ostream &os, char ofc) const {
    // Loop through stack and print out each element
    for(size_t i = 0; i < _top+1; ++i){
        os << _stack[i] << ofc;
    }
}

// *****************************************************************
// * Function Name:  operator<<()                                  *
// * Description: << operator overload that prints elements        *
// * Parameter Description: os - ostream, ofc - delimiter          *
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template <typename T>
std::ostream& operator<<(std::ostream & os, const Stack<T> & a){
    // Call to print function
    a.print(os);
    return os;
}

// *****************************************************************
// * Function Name:  operator==()                                  *
// * Description: == operator overload that tests if two           *
// * stacks are the same                                           *
// * Parameter Description: a,b - objects to test equality         *
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template <typename T>
bool operator==(const Stack<T> & a, const Stack<T> & b){
    // If size is not equal, then stacks aren't equal, return false
    if(a._top != b._top){
        return false;
    }
    // Loop through stack...
    for(size_t i = 0; i < a._top+1; ++i){
        // If elements don't match, return false
        if(a._stack[i] != b._stack[i]){
            return false;
        }
    }
    // If here, then they must be the same, return true
    return true;
}

// *****************************************************************
// * Function Name:  operator!=()                                  *
// * Description: != operator overload that tests if two           *
// * stacks are the different                                      *
// * Parameter Description: a,b - objects to test difference       *
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template <typename T>
bool operator!=(const Stack<T> & a, const Stack<T> & b){
    // Call to not == function
    return !(a == b);
}

// *****************************************************************
// * Function Name:  operator<=()                                  *
// * Description: <= operator overload that tests if all           *
// * elements in one stack is <= all elements in other stack       *
// * Parameter Description: a,b - objects to test corr. elements   *
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template <typename T>
bool operator<=(const Stack<T> & a, const Stack<T> & b){
    // If size is not equal, then stacks aren't equal, return false
    if(a._top != b._top){
        return false;
    }
    // Loop through stack...
    for(size_t i = 0; i < a._top+1; ++i){
        // If inequality doesn't match pre-conditions, return false
        if(a._stack[i] > b._stack[i]){
            return false;
        }
    }
    // If here, then preconditions were met, return true
    return true;
}