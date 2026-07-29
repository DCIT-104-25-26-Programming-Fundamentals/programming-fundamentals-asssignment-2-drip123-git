#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transpose(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols,
               int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                  int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                       int m, int n, int p, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int total = 0;
            for (int k = 0; k < n; k++) {
                total += a[i][k] * b[k][j];
            }
            result[i][j] = total;
        }
    }
}

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    // ---------------- PART A: Transpose ----------------
    cout << "=== PART A: Transpose a Matrix ===" << endl;
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter Matrix:" << endl;
    readMatrix(matrixA, rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrixA, rows, cols);

    transpose(matrixA, rows, cols, result);
    cout << "\nTransposed Matrix:" << endl;
    printMatrix(result, cols, rows);

    // ---------------- PART B: Addition ----------------
    cout << "\n=== PART B: Add Two Matrices ===" << endl;
    int addRows, addCols;
    cout << "Enter number of rows for both matrices: ";
    cin >> addRows;
    cout << "Enter number of columns for both matrices: ";
    cin >> addCols;

    cout << "Matrix A:" << endl;
    readMatrix(matrixA, addRows, addCols);
    cout << "Matrix B:" << endl;
    readMatrix(matrixB, addRows, addCols);

    addMatrices(matrixA, matrixB, addRows, addCols, result);
    cout << "\nSum:" << endl;
    printMatrix(result, addRows, addCols);

    // ---------------- PART C: Multiplication ----------------
    cout << "\n=== PART C: Multiply Two Matrices ===" << endl;
    int m, n, p;
    cout << "Enter rows of Matrix A: ";
    cin >> m;
    cout << "Enter columns of Matrix A (= rows of Matrix B): ";
    cin >> n;
    cout << "Enter columns of Matrix B: ";
    cin >> p;

    cout << "Matrix A:" << endl;
    readMatrix(matrixA, m, n);
    cout << "Matrix B:" << endl;
    readMatrix(matrixB, n, p);

    multiplyMatrices(matrixA, matrixB, m, n, p, result);
    cout << "\nProduct (A x B):" << endl;
    printMatrix(result, m, p);

    return 0;
}