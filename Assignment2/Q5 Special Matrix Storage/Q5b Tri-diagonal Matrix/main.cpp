#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int elements[3 * n - 2];

    // Store the non-zero elements row by row
    for (int i = 0; i < 3 * n - 2; i++)
    {
        cin >> elements[i];
    }

    int row, col;
    cin >> row >> col;

    int value = 0;

    // Main diagonal
    if (row == col)
    {
        value = elements[2 * row - 2];
    }
    // Lower diagonal
    else if (row == col + 1)
    {
        value = elements[2 * col - 1];
    }
    // Upper diagonal
    else if (col == row + 1)
    {
        value = elements[2 * row - 1];
    }

    cout << "Element at (" << row << ", " << col << "): "
         << value << endl;

    cout << "Space using normal 2D array: "
         << n * n << " elements" << endl;

    cout << "Space using tri-diagonal representation: "
         << 3 * n - 2 << " elements" << endl;

    return 0;
}