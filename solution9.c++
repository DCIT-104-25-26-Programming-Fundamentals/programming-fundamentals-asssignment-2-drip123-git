#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

double modulus(double a, double b) {
    return fmod(a, b);
}

double power(double a, double b) {
    return pow(a, b);
}

void showMenu() {
    cout << "============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
}

int main() {
    while (true) {
        showMenu();
        int choice;
        cout << "Select an operation (1-7): ";
        cin >> choice;

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 7) {
            cout << "Error: Please enter a number between 1 and 7." << endl;
            cout << endl;
            continue;
        }

        double a, b;
        cout << "Enter first number : ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;

        if ((choice == 4 || choice == 5) && b == 0) {
            cout << "Error: Cannot divide by zero." << endl;
            cout << endl;
            continue;
        }

        double result;
        char symbol;

        switch (choice) {
            case 1:
                result = add(a, b);
                symbol = '+';
                break;
            case 2:
                result = subtract(a, b);
                symbol = '-';
                break;
            case 3:
                result = multiply(a, b);
                symbol = '*';
                break;
            case 4:
                result = divide(a, b);
                symbol = '/';
                break;
            case 5:
                result = modulus(a, b);
                symbol = '%';
                break;
            case 6:
                result = power(a, b);
                symbol = '^';
                break;
        }

        cout << fixed << setprecision(2);
        cout << "Result: " << a << " " << symbol << " " << b
             << " = " << result << endl;
        cout << endl;
    }

    return 0;
}