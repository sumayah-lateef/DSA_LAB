#include <iostream>
using namespace std;

int main()
{
    int r1, c1, nz1;
    int r2, c2, nz2;

    // Read first sparse matrix
    cin >> r1 >> c1 >> nz1;

    int A[100][3];

    A[0][0] = r1;
    A[0][1] = c1;
    A[0][2] = nz1;

    for (int i = 1; i <= nz1; i++)
    {
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }

    // Read second sparse matrix
    cin >> r2 >> c2 >> nz2;

    int B[100][3];

    B[0][0] = r2;
    B[0][1] = c2;
    B[0][2] = nz2;

    for (int i = 1; i <= nz2; i++)
    {
        cin >> B[i][0] >> B[i][1] >> B[i][2];
    }

    // Multiplication is possible only when
    // columns of A = rows of B
    if (c1 != r2)
    {
        cout << "Multiplication not possible." << endl;
        return 0;
    }

    int result[100][100] = {0};

    // Multiply using non-zero elements only
    for (int i = 1; i <= nz1; i++)
    {
        for (int j = 1; j <= nz2; j++)
        {
            if (A[i][1] == B[j][0])
            {
                result[A[i][0]][B[j][1]] +=
                    A[i][2] * B[j][2];
            }
        }
    }

    // Convert result into triplet form
    int C[100][3];
    int k = 1;

    C[0][0] = r1;
    C[0][1] = c2;

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            if (result[i][j] != 0)
            {
                C[k][0] = i;
                C[k][1] = j;
                C[k][2] = result[i][j];
                k++;
            }
        }
    }

    C[0][2] = k - 1;

    cout << "Product of sparse matrices in triplet form:"
         << endl;

    for (int i = 0; i < k; i++)
    {
        cout << C[i][0] << " "
             << C[i][1] << " "
             << C[i][2] << endl;
    }

    return 0;
}