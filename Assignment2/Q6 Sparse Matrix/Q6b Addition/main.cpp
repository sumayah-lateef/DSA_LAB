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

    // Check dimensions
    if (r1 != r2 || c1 != c2)
    {
        cout << "Addition not possible." << endl;
        return 0;
    }

    int C[100][3];

    C[0][0] = r1;
    C[0][1] = c1;

    int i = 1, j = 1, k = 1;

    // Merge both triplets
    while (i <= nz1 && j <= nz2)
    {
        if (A[i][0] < B[j][0] ||
            (A[i][0] == B[j][0] && A[i][1] < B[j][1]))
        {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];

            i++;
            k++;
        }
        else if (B[j][0] < A[i][0] ||
                 (A[i][0] == B[j][0] && B[j][1] < A[i][1]))
        {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];

            j++;
            k++;
        }
        else
        {
            int sum = A[i][2] + B[j][2];

            if (sum != 0)
            {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = sum;
                k++;
            }

            i++;
            j++;
        }
    }

    // Copy remaining elements of A
    while (i <= nz1)
    {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];

        i++;
        k++;
    }

    // Copy remaining elements of B
    while (j <= nz2)
    {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];

        j++;
        k++;
    }

    C[0][2] = k - 1;

    cout << "Sum of sparse matrices in triplet form:" << endl;

    for (int x = 0; x < k; x++)
    {
        cout << C[x][0] << " "
             << C[x][1] << " "
             << C[x][2] << endl;
    }

    return 0;
}