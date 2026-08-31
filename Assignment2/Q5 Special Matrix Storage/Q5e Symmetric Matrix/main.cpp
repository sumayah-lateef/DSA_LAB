#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // Store only the lower triangular part
    int totalElements = n * (n + 1) / 2;

    int elements[totalElements];

    for (int i = 0; i < totalElements; i++)
    {
        cin >> elements[i];
    }

    int row, col;
    cin >> row >> col;

    int value;

    // Lower triangular part
    if (row >= col)
    {
        int index = row * (row - 1) / 2 + (col - 1);
        value = elements[index];
    }
    // Upper triangular part
    else
    {
        // Use the corresponding element from the lower triangle
        int index = col * (col - 1) / 2 + (row - 1);
        value = elements[index];
    }

    cout << "Element at (" << row << ", " << col << "): "
         << value << endl;

    cout << "Space using normal 2D array: "
         << n * n << " elements" << endl;

    cout << "Space using symmetric representation: "
         << totalElements << " elements" << endl;

    return 0;
}