#include <iostream>
using namespace std;

int arr[100];
int n = 0;

void createArray()
{
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Array created successfully.\n";
}

void displayArray()
{
    if (n == 0)
    {
        cout << "Array is empty.\n";
        return;
    }

    cout << "Array elements: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void insertElement()
{
    if (n == 100)
    {
        cout << "Array is full.\n";
        return;
    }

    int position, value;

    cout << "Enter position (1 to " << n + 1 << "): ";
    cin >> position;

    cout << "Enter value: ";
    cin >> value;

    if (position < 1 || position > n + 1)
    {
        cout << "Invalid position.\n";
        return;
    }

    for (int i = n; i >= position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position - 1] = value;
    n++;

    cout << "Element inserted successfully.\n";
}

void deleteElement()
{
    if (n == 0)
    {
        cout << "Array is empty.\n";
        return;
    }

    int position;

    cout << "Enter position to delete (1 to " << n << "): ";
    cin >> position;

    if (position < 1 || position > n)
    {
        cout << "Invalid position.\n";
        return;
    }

    for (int i = position - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    cout << "Element deleted successfully.\n";
}

void linearSearch()
{
    if (n == 0)
    {
        cout << "Array is empty.\n";
        return;
    }

    int value;

    cout << "Enter element to search: ";
    cin >> value;

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            cout << "Element found at position " << i + 1 << ".\n";
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Element not found.\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "========== ARRAY MENU ==========\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createArray();
            break;

        case 2:
            displayArray();
            break;

        case 3:
            insertElement();
            break;

        case 4:
            deleteElement();
            break;

        case 5:
            linearSearch();
            break;

        case 6:
            cout << "Program exited.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}