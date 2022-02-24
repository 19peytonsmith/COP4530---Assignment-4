#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Stack.h"

using namespace std;
using namespace cop4530;

void in2post(vector<string> &input, vector<string> &output);
void results(vector<string> &output);
bool validoperand(string input);
bool validoperator(string input);
int precedence(string input);
bool variable(string input);

// *****************************************************************
// * Function Name:  main()                                        *
// * Description:  Converts infix to postfix notation and evaluates*
// * Parameter Description:   No parameters                        *
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
int main(){
    // Declare variables
    vector<string> input;
    vector<string> output;
    string expression;
    // Infinite loop
    while(true){
        // Clear vectors to use for another loop
        input.clear();
        output.clear();

        // Read in expression
        cout << "Enter in an expression" << endl;
        getline(cin, expression);

        // While loop breaks by expression keywords
        if(expression == "end" || expression == "END" || expression == "End") {
            break;
        }

        // Display InFix Notation
        cout << "The InFix   Notation is: " << expression << endl;

        // Convert expression into broken-apart pieces for input vector
        stringstream sstream(expression);
        while(sstream >> expression){
            input.push_back(expression);
        }

        // Display PostFix Notation
        cout << "The PostFix Notation is: ";
        in2post(input, output);
        cout << endl;

        // Display Results/evaluation
        cout << "Results are: ";
        results(output);
        cout << endl;

    }
    return 0;
}

// *****************************************************************
// * Function Name:  in2post()                                     *
// * Description:  Converts input vector (infix) to an associated  *
// * output vector (postfix)                                       *
// * Parameter Description: Two parameters, vector<string> to conv.*
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Dijkstra's Shunting Yard Algorithm                *
// *****************************************************************
void in2post(vector<string> &input, vector<string> &output){
    // Declare variables
    Stack<string> stack;
    string last;
    int flag = 0;

     // Loop through expression, piece-by-piece
    for(auto & i : input){
        if(validoperand(i)){ // Check if it is an operand
            // Pushes to output vector and displays
            output.push_back(i);
            cout << i << " ";
        }else if(i == "("){ // If string is (, push to stack
            stack.push(i);
        }else if(validoperator(i)) { // Check if it is an operator
            // Check conditions for pushing to output vector and popping stack
            while (!stack.empty() && (stack.top() != "(") && (precedence(stack.top()) >= precedence(i))) {
                output.push_back(stack.top());
                cout << stack.top() << " ";
                stack.pop();
            }
            stack.push(i); // Push to stack
        }else if(i == ")"){ // If string is )...
            // If previous string is an operator, yield ERROR
            if(validoperator(last)){
                cout << "ERROR" << endl;
                return;
            }else{ // Else no error...
                // Push top of stack to output and pop until top is (
                do {
                    output.push_back(stack.top());
                    cout << stack.top() << " ";
                    stack.pop();
                } while (stack.top() != "(");

                // If top is (, set a flag
                if(stack.top() == "("){
                    flag = 1;
                }
                stack.pop(); // Pop top element

                // If empty and ( is not found, yield ERROR
                if(stack.empty() && (flag == 0)){
                    cout << "ERROR" << endl;
                    return;
                }
            }
        }else{ // Not operand nor operator, thus invalid, yield ERROR
            cout << "ERROR" << endl;
            return;
        }
        last = i; // Update last variable
    }
    if(validoperator(last) || last == "("){ // If previous string is an operator or ( output ERROR
        cout << "ERROR" << endl;
        return;
    }else { // Else...
        // push to output and pop stack until empty
        do {
            output.push_back(stack.top());
            cout << stack.top() << " ";
            stack.pop();
        } while (!stack.empty());
    }
}

// *****************************************************************
// * Function Name:  results()                                     *
// * Description:  Evaluates postfix notation                      *
// * Parameter Description: vector<string> output (postfix expr.)  *
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Canvas Assignment Page                            *
// *****************************************************************
void results(vector<string> &output){
    // Declare variables
    Stack<string> stack;

    // Loop through output vector
    for(auto & i : output) {
        // If there is a variable, just display the output vector, do not evaluate
        if (variable(i)) {
            for (auto & j : output) {
                cout << j << " ";
            }
            return;
        }
    }
    // Loop through output vector
    for(auto & j : output){
        if(validoperand(j)){ // Check if it is an operand and push to stack
            stack.push(j);
        }else if(validoperator(j)){ // Check if it an operator
            // Calculate first and second to top elements
            int calculation = 0;
            float first = stof(stack.top());
            stack.pop();
            float second = stof(stack.top());
            stack.pop();

            // Perform corresponding calculation
            if(j[0] == '*') {
                calculation = second * first;
            }else if(j[0] == '/') {
                calculation = second / first;
            }else if(j[0] == '+') {
                calculation = second + first;
            }else if(j[0] == '-') {
                calculation = second - first;
            }
            stack.push(to_string(calculation)); // Push calculation as string to stack
        }
    }
    // If stack size > 1, too few operands, yield ERROR
    if(stack.size() > 1){
        cout << "Error - Too few operands" << endl;
    }else if(stack.size() == 1){ // Else if stack size = 1, yield top of stack
        cout << stack.top();
    }else{ // Else yield 0
        cout << "0";
    }
}

// *****************************************************************
// * Function Name:  validoperand()                                *
// * Description:  Determines if string is a valid operand         *
// * Parameter Description: string input used to check             *
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
bool validoperand(string input){
    // If character is alphanumeric, return true, else return false
    for(char i: input){
        if(isalnum(i)){
            return true;
        }
    }
    return false;
}

// *****************************************************************
// * Function Name:  validoperator()                                *
// * Description:  Determines if string is a valid operator         *
// * Parameter Description: string input used to check             *
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
bool validoperator(string input){
    // If input is an operator, then it is valid, return true, else false
    if(input == "*" || input == "/" || input == "+" || input == "-"){
        return true;
    }
    return false;
}

// *****************************************************************
// * Function Name:  precedence()                                  *
// * Description:  Checks precedence of operators + parenthesis    *
// * Parameter Description: string input used to check             *
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
int precedence(string input){
    // Associate parenthesis/operator with a integer value according to precedence
    if (input == "(" || input == ")") {
        return 2;
    }else if(input == "*" || input == "/") {
        return 1;
    }else if(input == "+" || input == "-") {
        return 0;
    }else{ // Should never happen
        return 999;
    }
}

// *****************************************************************
// * Function Name:  variable()                                    *
// * Description:  Determines if input is a variable (letter)      *
// * Parameter Description: string input used to check             *
// * Date:  02/08/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
bool variable(string input){
    // If character is numeric, return true, else return false
    for(char i: input){
        if(isalpha(i)){
            return true;
        }
    }
    return false;
}