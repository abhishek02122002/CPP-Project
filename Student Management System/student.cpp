#include <iostream>
#include <vector>
#include <string>
#include <limits> // Include this for numeric_limits
using namespace std;

// Student structure to hold data
struct Student {
    string name;
    int rollNumber;
    float marks;
};

// Function to add a new student
void addStudent(vector<Student> &students) {
    Student s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
    cout << "Enter Student Name: ";
    getline(cin, s.name);

    cout << "Enter Roll Number: ";
    while (!(cin >> s.rollNumber)) {
        cout << "Invalid input. Please enter a valid Roll Number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter Marks: ";
    while (!(cin >> s.marks)) {
        cout << "Invalid input. Please enter valid Marks: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    students.push_back(s);
    cout << "Student added successfully!\n\n";
}

// Function to display all students
void displayStudents(const vector<Student> &students) {
    if (students.empty()) {
        cout << "No records to display.\n\n";
        return;
    }

    cout << "\nStudent Records:\n";
    for (const auto &s : students) {
        cout << "Name: " << s.name << " | Roll Number: " << s.rollNumber << " | Marks: " << s.marks << "\n";
    }
    cout << "\n";
}

// Function to search for a student by roll number
void searchStudent(const vector<Student> &students) {
    int roll;
    cout << "Enter Roll Number to search: ";
    while (!(cin >> roll)) {
        cout << "Invalid input. Please enter a valid Roll Number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (const auto &s : students) {
        if (s.rollNumber == roll) {
            cout << "\nStudent Found:\n";
            cout << "Name: " << s.name << " | Roll Number: " << s.rollNumber << " | Marks: " << s.marks << "\n\n";
            return;
        }
    }
    cout << "Student with Roll Number " << roll << " not found.\n\n";
}

// Main function
int main() {
    vector<Student> students; 
    int choice;

    do {
        cout << "Student Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a valid choice: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                searchStudent(students);
                break;
            case 4:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n\n";
        }
    } while (choice != 4);

    return 0;
}
