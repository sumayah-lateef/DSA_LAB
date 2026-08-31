#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    string arr[n];

    for (int i = 0; i < n; i++)
    {
        getline(cin, arr[i]);
    }

    // Bubble Sort strings alphabetically
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Strings in alphabetical order:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}