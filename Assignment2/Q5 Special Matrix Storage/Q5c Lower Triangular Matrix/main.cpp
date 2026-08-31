#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // Number of elements required for lower triangular matrix
    int totalElements = n * (n + 1) / 2;

    int elements[totalElements];

    // Store only elements on and below the main diagonal
    for (int i = 0; i < totalElements; i++)
    {
        cin >> elements[i];
    }

    int row, col;
    cin >> row >> col;

    int value;

    if (row >= col)
    {
        // Row-major mapping using 1-based indexing
        int index = row * (row - 1) / 2 + (col - 1);

        value = elements[index];
    }
    else
    {
        value = 0;
    }

    cout << "Element at (" << row << ", " << col << "): "
         << value << endl;

    cout << "Space using normal 2D array: "
         << n * n << " elements" << endl;

    cout << "Space using lower triangular representation: "
         << totalElements << " elements" << endl;

    return 0;
}