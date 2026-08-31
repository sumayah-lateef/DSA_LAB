#include <iostream>
using namespace std;

// Method 1: Linear Time
int findMissingLinear(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != i + 1)
        {
            return i + 1;
        }
    }

    return n;
}

// Method 2: Binary Search
int findMissingBinary(int arr[], int n)
{
    int low = 0;
    int high = n - 2;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == mid + 1)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low + 1;
}

int main()
{
    int n;
    cin >> n;

    int arr[n - 1];

    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }

    int missingLinear = findMissingLinear(arr, n);
    int missingBinary = findMissingBinary(arr, n);

    cout << "Missing number using Linear Search: "
         << missingLinear << endl;

    cout << "Missing number using Binary Search: "
         << missingBinary << endl;

    return 0;
}