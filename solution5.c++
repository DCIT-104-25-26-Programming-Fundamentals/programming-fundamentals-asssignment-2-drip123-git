#include <iostream>
using namespace std;

void printFibonacciTerms(int n) {
    long long a = 0, b = 1;
    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; i++) {
        cout << a;
        if (i != n - 1) {
            cout << " ";
        }
        long long next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

bool isFibonacci(long long num) {
    if (num < 0) {
        return false;
    }
    long long a = 0, b = 1;
    while (a <= num) {
        if (a == num) {
            return true;
        }
        long long next = a + b;
        a = b;
        b = next;
    }
    return false;
}

int main() {
    // ---------------- PART A ----------------
    int n;
    cout << "How many terms? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
    } else {
        printFibonacciTerms(n);
    }

    // ---------------- PART B ----------------
    long long num;
    cout << "Enter a number to check: ";
    cin >> num;

    if (isFibonacci(num)) {
        cout << num << " is a Fibonacci number." << endl;
    } else {
        cout << num << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}