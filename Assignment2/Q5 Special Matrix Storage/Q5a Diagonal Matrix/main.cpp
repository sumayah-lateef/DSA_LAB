#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // Only n elements are required to store a diagonal matrix
    int diagonal[n];

    for (int i = 0; i < n; i++)
    {
        cin >> diagonal[i];
    }

    int row, col;
    cin >> row >> col;

    cout << "Diagonal matrix:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << diagonal[i] << " ";
            else
                cout << "0 ";
        }

        cout << endl;
    }

    // Retrieve element from compact representation
    int value;

    if (row == col)
        value = diagonal[row - 1];
    else
        value = 0;

    cout << "Element at (" << row << ", " << col << "): "
         << value << endl;

    cout << "Space using normal 2D array: "
         << n * n << " elements" << endl;

    cout << "Space using diagonal representation: "
         << n << " elements" << endl;

    return 0;
}