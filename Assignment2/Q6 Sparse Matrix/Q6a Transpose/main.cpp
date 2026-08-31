#include <iostream>
using namespace std;

int main()
{
    int rows, cols, nonZero;
    cin >> rows >> cols >> nonZero;

    int matrix[100][3];

    matrix[0][0] = rows;
    matrix[0][1] = cols;
    matrix[0][2] = nonZero;

    for (int i = 1; i <= nonZero; i++)
    {
        cin >> matrix[i][0] >> matrix[i][1] >> matrix[i][2];
    }

    int transpose[100][3];

    transpose[0][0] = cols;
    transpose[0][1] = rows;
    transpose[0][2] = nonZero;

    int k = 1;

    for (int col = 0; col < cols; col++)
    {
        for (int i = 1; i <= nonZero; i++)
        {
            if (matrix[i][1] == col)
            {
                transpose[k][0] = matrix[i][1];
                transpose[k][1] = matrix[i][0];
                transpose[k][2] = matrix[i][2];
                k++;
            }
        }
    }

    cout << "Original triplet representation:" << endl;

    for (int i = 0; i <= nonZero; i++)
    {
        cout << matrix[i][0] << " "
             << matrix[i][1] << " "
             << matrix[i][2] << endl;
    }

    cout << "Transposed triplet representation:" << endl;

    for (int i = 0; i <= nonZero; i++)
    {
        cout << transpose[i][0] << " "
             << transpose[i][1] << " "
             << transpose[i][2] << endl;
    }

    return 0;
}