#include <bits/stdc++.h>
using namespace std;

void leftRotate(int arr[], int n, int k) {
    k = k % n;

    for (int r = 0; r < k; r++) {
        int first = arr[0];

        for (int i = 0; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        arr[n - 1] = first;
    }
}

void rightRotate(int arr[], int n, int k) {
    k = k % n;

    for (int r = 0; r < k; r++) {
        int last = arr[n - 1];

        for (int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = last;
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[100], n, k;

    cout << "Enter number of elements: "<<endl;
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter K: ";
    cin >> k;

    int leftArr[100], rightArr[100];

    for (int i = 0; i < n; i++) {
        leftArr[i] = arr[i];
        rightArr[i] = arr[i];
    }

    leftRotate(leftArr, n, k);
    rightRotate(rightArr, n, k);

    cout << "\nOriginal array: ";
    display(arr, n);

    cout << "\nLeft rotation by " << k << ": ";
    display(leftArr, n);

    cout << "\nRight rotation by " << k << ": ";
    display(rightArr, n);

    cout << "\n";

    return 0;
}