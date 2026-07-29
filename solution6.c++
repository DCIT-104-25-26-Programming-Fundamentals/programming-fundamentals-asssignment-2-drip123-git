#include <iostream>
#include <iomanip>
using namespace std;

void printTable(int number) {
    cout << "Multiplication Table for " << number << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << number << "  x  " << left << setw(2) << i
             << " =  " << (number * i) << endl;
    }
}

void printTablesUpTo(int n) {
    for (int number = 1; number <= n; number++) {
        printTable(number);
        if (number != n) {
            cout << string(29, '-') << endl;
        }
    }
}

int main() {
    // ---------------- PART A ----------------
    int num;
    cout << "Enter a number: ";
    cin >> num;
    printTable(num);

    // ---------------- PART B ----------------
    int n;
    cout << "\nEnter N (to print tables 1 to N): ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 0;
    }

    cout << endl;
    printTablesUpTo(n);

    return 0;
}