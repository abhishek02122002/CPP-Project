#include <iostream>
#include <cmath> // For mathematical functions
#include <limits> // For clearing input buffer
using namespace std;

// Function to display the menu
void displayMenu() {
    cout << "\n--- Advanced Calculator ---\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "6. Exponential (x^y)\n";
    cout << "7. Logarithm (Base 10 and Natural)\n";
    cout << "8. Trigonometric Functions (sin, cos, tan)\n";
    cout << "9. Inverse Trigonometric Functions (arcsin, arccos, arctan)\n";
    cout << "10. Degree to Radian Conversion\n";
    cout << "11. Radian to Degree Conversion\n";
    cout << "12. Exit\n";
    cout << "Enter your choice: ";
}

// Function to clear the input buffer
void clearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Basic Operations
void basicOperations(int choice) {
    double a, b;
    cout << "Enter two numbers: ";
    while (!(cin >> a >> b)) {
        cout << "Invalid input. Please enter numbers: ";
        clearBuffer();
    }

    switch (choice) {
        case 1:
            cout << "Result: " << a + b << endl;
            break;
        case 2:
            cout << "Result: " << a - b << endl;
            break;
        case 3:
            cout << "Result: " << a * b << endl;
            break;
        case 4:
            if (b != 0)
                cout << "Result: " << a / b << endl;
            else
                cout << "Error: Division by zero is not allowed.\n";
            break;
        case 5:
            cout << "Result: " << fmod(a, b) << endl; // Using fmod for floating-point modulus
            break;
    }
}

// Exponential Function
void exponential() {
    double base, exp;
    cout << "Enter base and exponent: ";
    while (!(cin >> base >> exp)) {
        cout << "Invalid input. Please enter numbers: ";
        clearBuffer();
    }
    cout << "Result: " << pow(base, exp) << endl;
}

// Logarithmic Function
void logarithms() {
    double num;
    cout << "Enter a positive number: ";
    while (!(cin >> num) || num <= 0) {
        cout << "Invalid input. Please enter a positive number: ";
        clearBuffer();
    }

    cout << "Log base 10: " << log10(num) << endl;
    cout << "Natural log (ln): " << log(num) << endl;
}

// Trigonometric Functions
void trigonometricFunctions() {
    double angle;
    cout << "Enter angle in degrees: ";
    while (!(cin >> angle)) {
        cout << "Invalid input. Please enter a number: ";
        clearBuffer();
    }

    double radians = angle * M_PI / 180.0; // Convert degrees to radians
    cout << "sin(" << angle << "°): " << sin(radians) << endl;
    cout << "cos(" << angle << "°): " << cos(radians) << endl;
    cout << "tan(" << angle << "°): " << tan(radians) << endl;
}

// Inverse Trigonometric Functions
void inverseTrigonometricFunctions() {
    double value;
    cout << "Enter a value between -1 and 1: ";
    while (!(cin >> value) || value < -1 || value > 1) {
        cout << "Invalid input. Enter a value between -1 and 1: ";
        clearBuffer();
    }

    cout << "arcsin(" << value << "): " << asin(value) * 180.0 / M_PI << "°" << endl;
    cout << "arccos(" << value << "): " << acos(value) * 180.0 / M_PI << "°" << endl;
    cout << "arctan(" << value << "): " << atan(value) * 180.0 / M_PI << "°" << endl;
}

// Degree to Radian Conversion
void degreeToRadian() {
    double degrees;
    cout << "Enter degrees: ";
    while (!(cin >> degrees)) {
        cout << "Invalid input. Please enter a number: ";
        clearBuffer();
    }
    cout << degrees << " degrees = " << degrees * M_PI / 180.0 << " radians" << endl;
}

// Radian to Degree Conversion
void radianToDegree() {
    double radians;
    cout << "Enter radians: ";
    while (!(cin >> radians)) {
        cout << "Invalid input. Please enter a number: ";
        clearBuffer();
    }
    cout << radians << " radians = " << radians * 180.0 / M_PI << " degrees" << endl;
}

// Main Function
int main() {
    int choice;

    do {
        displayMenu();
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number between 1 and 12: ";
            clearBuffer();
        }

        switch (choice) {
            case 1 ... 5:
                basicOperations(choice);
                break;
            case 6:
                exponential();
                break;
            case 7:
                logarithms();
                break;
            case 8:
                trigonometricFunctions();
                break;
            case 9:
                inverseTrigonometricFunctions();
                break;
            case 10:
                degreeToRadian();
                break;
            case 11:
                radianToDegree();
                break;
            case 12:
                cout << "Exiting the calculator. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 12);

    return 0;
}
