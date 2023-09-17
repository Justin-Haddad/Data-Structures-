//
//  main.cpp
//  HW3_CS2413.cpp
//
//  Created by Justin Haddad on 9/7/23.
//


//
// ========================================
// HW3: Implement a Vector Class
// ========================================
//
// In this assignment, we will implement
// a vector class based on array, pointer
// and dynamic memory allocation.
//
// The class has two private member
// variables and some member functions.
// Their designs are explained below.
//
// You can add new member functions
// but not new member variables. In
// addition, you cannot use any existing
// vector-related library or function.
//
//
#include <iostream>
using namespace std;
//
// ======= Task =======
// Design and implement all member
// functions of the MyVector class.
//
class MyVector {
public:
// The "vsize" function returns the size
// of the current vector.
int vsize();
// The "empty" function returns 1 if the
// current vector has no element and 0 otherwise.
int empty();
// The "at" function returns the idx_th element
// of the vector. It also returns -1 if "idx"
// is outside the range of the current vector.
int at(int idx);
// The "resize" function resizes the current
// vector into a vector of size n. Note there
// are two scenarios (in lecture slides) which
// may need to be addressed separately.
void resize(int n);
// The "push_back" function adds a new element
// "x" to the end of the current vector. Note
// the vector size increases after addition.
void push_back(int x);
// The "pop_back" function removes the last
// element from the current vector, but does
// nothing if the current vector is empty.
// Note the vector size decreases after pop.
void pop_back();
// The "insert" function inserts a new element
// "x" as the idx_th element in the current vector.
// It also does nothing if "idx" is outside the
// range of the current vector.
void insert(int idx, int x);
// The "erase" function removes the idx_th element
// from the vector. It also does nothing if the
// current vector is empty or if "idx" is outside
// the range of the current vector.
void erase(int idx);
// The constructor should initialize
// pointer "p" to NULL and "size" to 0.
MyVector();
private:
int* p; // This pointer holds the vector (or,essentially,
// address of an array that holds the vector elements.)
// Do remember to update it after some vector operations.
int size; // This integer holds the size of the current
// vector. Do remember to update it after some
// vector operations.
};
 
// Constructor
MyVector::MyVector() {
    p = nullptr; //makes the pointer null
    size = 0; // Sets size to 0
}

int MyVector::vsize() {
    return size; //Returns size
}

int MyVector::empty() {
    return size == 0; // Returns 0 of size is 0 and 1 otherwise
}

int MyVector::at(int idx) {
    if (idx < 0 || idx >= size) { //Checks to see if idx is outside the range of vector
        return -1; // Index out of range
    }
    return p[idx]; // Returns the
}

void MyVector::resize(int n) {
    if (n < 0) { // Checks to see if the variable is less than 0
        return; // if so, then invalid size
    }
    
    int* p2 = new int[n]; // Create a new array with the new size
    
    if (n > size) // if new vector is bigger than orignial
    {
        for (int i = 0; i < n; i++) {
            p2[i] = p[i]; // Copy elements to the new array
        }
        for (int i = size; i < n; i++)
        {
            p2[i] = 0;
        }
    }
        
    if (n < size) //if original is bigger than next vector
    {
        for (int i = 0; i < n; i++) {
                p2[i] = p[i]; // Copy elements to the new array
            }
    }
    p = p2; // Update the pointer
       size = n; // Update the size
    }
   


void MyVector::push_back(int x) {
    int* p2 = new int[size + 1]; // Create a new array with increased size
    
    for (int i = 0; i < size; i++) // Create a for loop that goes through the vector
    {
        p2[i] = p[i]; // Copy elements to the new array
    }
    
    p2[size] = x; // Add the new element at the end
    
    delete[] p; // Delete the old array
    
    p = p2; // Update the pointer
    size++; // Increase the size
}

void MyVector::pop_back() {
    if (size > 0) {
        size--; // Decrease the size to remove the last element
    }
}


void MyVector::insert(int idx, int x) {
    if (idx < 0 || idx > size) {
        return; // Invalid index
    }
    
    int* p2 = new int[size + 1]; // Create a new array with increased size
        
    
    for (int i = 0; i < idx; i++) { // Create a for loop
            p2[i] = p[i]; // Copy elements before the insertion point
        }
        
        p2[idx] = x; // Insert the new element
        
        for (int i = idx; i < size; i++) {
            p2[i + 1] = p[i]; // Copy elements after the insertion point
        }
        
        delete[] p; // Delete the old array
        
        p = p2; // Update the pointer
        size++; // Increase the size
    
}

void MyVector::erase(int idx) {
    if (idx < 0 || idx >= size) { //Chcks to see if idx is outside of range
        return; // Invalid index
    }
    
    int* new_p = new int[size - 1]; // Create a new array with decreased size
    
    for (int i = 0; i < idx; i++) {
        new_p[i] = p[i]; // Copy elements before the deletion point
    }
    
    for (int i = idx + 1; i < size; i++) {
        new_p[i - 1] = p[i]; // Copy elements after the deletion point
    }
    
    delete[] p; // Delete the old array
    
    p = new_p; // Update the pointer
    size--; // Decrease the size
}

// The main function has been completed for you.
// It is used to test your implmentation.
// You should not modify it (unless there is typo).
int main()
{
    MyVector x;
    int mode;
    int new_size, idx, data;
    int temp;
    cin >> mode; // This decides which function to test.
    cin >> new_size >> idx >> data;
    // Mode 0: test push_back(), vsize() and at()
    if (mode == 0) {
        while (cin >> temp) {
            x.push_back(temp);
        }
        cout << x.vsize() << '\n';
        for (int i = 0; i < x.vsize(); i++) {
            cout << x.at(i) << '\n';
        }
    }
    // Mode 1: test resize()
    else if (mode == 1)
    {
        while (cin >> temp) {
            x.push_back(temp);
        }
        x.resize(new_size);
        cout << x.vsize() << '\n';
        for (int i = 0; i < x.vsize(); i++) {
            cout << x.at(i) << '\n';
        }
    }
    // Mode 2: test pop_back()
    else if (mode == 2) {
        while (cin >> temp) {
            x.push_back(temp);
        }
        x.pop_back();
        cout << x.vsize() << '\n';
        for (int i = 0; i < x.vsize(); i++) {
            cout << x.at(i) << '\n';
        }
    }
    // Mode 3: test insert()
    else if (mode == 3) {
        while (cin >> temp) {
            x.push_back(temp);
        }
        x.insert(idx, data);
        cout << x.vsize() << '\n';
        for (int i = 0; i < x.vsize(); i++) {
            cout << x.at(i) << '\n';
        }
    }
    // Mode 4: test erase()
    else if (mode == 4) {
        while (cin >> temp) {
            x.push_back(temp);
        }
        x.erase(idx);
        cout << x.vsize() << '\n';
        for (int i = 0; i < x.vsize(); i++) {
            cout << x.at(i) << '\n';
        }
    }
    else {
        cout << "Wrong Mode Input!";
    }
    return 0;
}
