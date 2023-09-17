//
//  HW1_CS2413.cpp
//  HW1_CS2413
//
//  Created by Justin Haddad on 8/28/23.
//

#include <iostream>
using namespace std;

class Student {
public:
    void set_SID(int x);
    void prt_SID();
    void set_GPA(float y);
    void prt_GPA();
    void reset();
    float get_GPA();
    Student();

private:
    int SID;
    float GPA;
};

class University {
public:
    void set_Stu(Student x[]);
    float GPA_Mean();
    float GPA_Max();
    float GPA_Min();
    University();

private:
    Student Sooner[5];
};

// Implementations for Student class member functions
void Student::set_SID(int x) {
    SID = x; //Sets the value of x into SID
}

void Student::prt_SID() {
    cout << SID; // Prints out SID
}

void Student::set_GPA(float y) {
    GPA = y; // Sets the value of y into GPA
}

void Student::prt_GPA() {
    cout << GPA; // Prints out GPA
}

void Student::reset() {
    SID = -1; //Sets SID to -1
    GPA = -1.0; // Sets GPA to -1.0
}

float Student::get_GPA() {
    return GPA; //Returns the value of GPA
}

Student::Student() {
    SID = -1; //Initalizes SID to -1
    GPA = -1.0; //Initalizes GPA to -1.0
}

// Implementations for University class member functions
void University::set_Stu(Student x[]) {
    for (int i = 0; i < 5; i++) { // For loop that goes through the array
        Sooner[i] = x[i]; //Sets the value of
    }
}

float University::GPA_Mean() {
    float totalGPA = 0.0; //Creates a float variable named totalGPA and sets it to 0.0
    for (int i = 0; i < 5; i++) {
        totalGPA += Sooner[i].get_GPA(); // Goes through the array and adds up all the value to total
    }
    return totalGPA / 5.0; // Divdes by the total number of variables to find the mean
}

float University::GPA_Max() {
    float maxGPA = Sooner[0].get_GPA(); //Creates float variable maxGPA and set to first index of array
    for (int i = 1; i < 5; i++) { // Goes through array
        if (Sooner[i].get_GPA() > maxGPA) { // Checks to see if index is bigger than set value
            maxGPA = Sooner[i].get_GPA(); // If bigger, sets that variable as new maxGPA
        }
    }
    return maxGPA; // Returns maxGPa
}

float University::GPA_Min() {
    float minGPA = Sooner[0].get_GPA(); //Creates float variable minGPA and set to first index of array
    for (int i = 1; i < 5; i++) {  // Goes through array
        if (Sooner[i].get_GPA() < minGPA) { // Checks to see if index is smaller than set value
            minGPA = Sooner[i].get_GPA(); //If smaller sets that varibale as new minGPA
        }
    }
    return minGPA; // Returns the min GPA
}

University::University() {
    for (int i = 0; i < 5; i++) { //Goes through the for loop
        Sooner[i].set_SID(-1); //Sets SID to -1 for all indexs in the array
        Sooner[i].set_GPA(-1.0); // Sets GPA to -1.0 for all indexs in the array
    }
}

int main() {
    Student x[5];
    University OU;
    int sid;
    float gpa;

    // Test 1: Constructor, print function, and header files
    for (int i = 0; i < 5; i++) {
        x[i].prt_SID();
        cout << ' ';
        x[i].prt_GPA();
        cout << endl;
    }

    // Task 3: Taking input for SID and GPA
    for (int i = 0; i < 5; i++) { //Irriates  through for loop
        cin >> sid >> gpa; // User input for sid and gpa
        x[i].set_SID(sid); // Sets value of user input for sid
        x[i].set_GPA(gpa); //Sets value of user input for gpa
    }

    // Test 2: Tests set function
    for (int i = 0; i < 5; i++) {
        x[i].prt_SID();
        cout << ' ';
        x[i].prt_GPA();
        cout << endl;
    }

    // Test 3: Tests University class
    OU.set_Stu(x);
    cout << OU.GPA_Mean() << ' ';
    cout << OU.GPA_Max() << ' ';
    cout << OU.GPA_Min() << endl;

    // Test 4: Testing reset function
    for (int i = 0; i < 5; i++) {
        x[i].reset();
        x[i].prt_SID();
        cout << ' ';
        x[i].prt_GPA();
        cout << endl;
    }

    return 0;
}

