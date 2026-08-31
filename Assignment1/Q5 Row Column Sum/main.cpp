#include <bits/stdc++.h>
using namespace std;

int main() {
    int matrix[10][10];
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "\nMatrix:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    // Row sums
    cout << "\nRow sums:\n";

    for (int i = 0; i < rows; i++) {
        int sum = 0;

        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }

        cout << "Row " << i + 1 << " = " << sum << "\n";
    }

    // Column sums
    cout << "\nColumn sums:\n";

    for (int j = 0; j < cols; j++) {
        int sum = 0;

        for (int i = 0; i < rows; i++) {
            sum += matrix[i][j];
        }

        cout << "Column " << j + 1 << " = " << sum << "\n";
    }

    return 0;
}