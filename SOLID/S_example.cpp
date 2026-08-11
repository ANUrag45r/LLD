#include <bits/stdc++.h>
using namespace std;

class Student {
    // Encapsulation
private:
    string name;
    int marks;

public:
    // Setters
    void setName(string n) {
        name = n;
    }

    void setMarks(int m) {
        marks = m;
    }

    // Getters
    string getName() {
        return name;
    }

    int getMarks() {
        return marks;
    }
};

// Student is responsible only for storing student data.
// GradeCalculator is responsible for calculating grades.
// This follows Single Responsibility Principle (SRP).


//this GradeCalculator class is in HAS-A relationship with Student class. It uses the Student class to calculate the grade based on the marks of the student. This is an example of composition, where GradeCalculator has a Student object to perform its functionality.
class GradeCalculator {
public:
    void calculateGrade(Student& s) {

        if (s.getMarks() > 90) {
            cout << "A" << endl;
        }
        else if (s.getMarks() > 80) {
            cout << "B" << endl;
        }
        else {
            cout << "FAIL" << endl;
        }
    }
};

int main() {

    Student s;

    s.setName("Anurag");
    s.setMarks(94);

    GradeCalculator c;

    c.calculateGrade(s);

    return 0;
}