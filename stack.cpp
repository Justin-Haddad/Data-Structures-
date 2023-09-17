
//
//  main.cpp
//  Stack1.cpp
//
//  Created by Justin Haddad on 9/16/23.
//

#include <iostream>
using namespace std;
class MyStack {
private:
int* stack;
int itop;
public:
// This function pushes x into the stack.
// Push should always be successful even
// if the stack array is currently "full".
void push(int x);
// This function removes the top element
// in the stack. It does nothing if the
// stack is empty.
void pop();
// This function returns the top element
// in the stack. It returns -1 if the stack
// is empty.
int top();
// This function returns number of elements
// in the stack. Note this means it should
// return 0 if the stack is empty.
int Ssize();
// This function is given to you.
// It initializes a small array.
// Do not modify it.
MyStack();
};
MyStack::MyStack() {
stack = new int[2];
itop = -1;
};



void MyStack::push(int x) {
    
    if (itop + 1 >= (2 * Ssize()))
    {
        // Create a new stack with twice the size
        int newSize = (itop + 1) * 2;
        int* newStack = new int[newSize];
        
        // Copy elements from the old stack to the new stack
        for (int i = 0; i <= itop; i++)
        {
            newStack[i] = stack[i];
        }
        
        // Delete the old stack and update the pointer to the new stack
        delete[] stack;
        stack = newStack;
    }
    
    // Increment itop and add the new element to the top of the stack
    itop++;
    stack[itop] = x;
}

void MyStack::pop() {
    // Check if the stack is not empty
    if (itop >= 0)
    {
        // Simply decrement itop to remove the top element
        itop--;
    }
}

int MyStack::top()
{
    // Check if the stack is not empty
    if (itop >= 0)
    {
        // Return the top element
        return stack[itop];
    }
    else
    {
        // Return -1 if the stack is empty
        return -1;
    }
}

int MyStack::Ssize() {
    // Return the number of elements in the stack
    return itop + 1;
}


int main()
{
    MyStack x;
    int temp;
    int input_size = 0;  // Variable to store the input size
    
    // Read input and push elements onto the stack
    while (cin >> temp) {
        x.push(temp);
        input_size++;  // Increment the input size
    }
    
    // Use input_size as the stopping condition in the loop
    for (int i = 0; i < input_size; i++) {
        cout << x.top() << '\n';
        x.pop();
    }
    
    return 0;
}
