#include <iostream>
using namespace std;

long long mergeAndCount(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    long long inversions = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;

            // All remaining elements in the left half
            // form inversions with arr[j]
            inversions += (mid - i + 1);
        }

        k++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }

    return inversions;
}

long long mergeSortAndCount(int arr[], int temp[], int left, int right)
{
    long long inversions = 0;

    if (left < right)
    {
        int mid = left + (right - left) / 2;

        inversions += mergeSortAndCount(arr, temp, left, mid);

        inversions += mergeSortAndCount(arr, temp, mid + 1, right);

        inversions += mergeAndCount(arr, temp, left, mid, right);
    }

    return inversions;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    int temp[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long inversions =
        mergeSortAndCount(arr, temp, 0, n - 1);

    cout << "Number of inversions: " << inversions << endl;

    return 0;
}