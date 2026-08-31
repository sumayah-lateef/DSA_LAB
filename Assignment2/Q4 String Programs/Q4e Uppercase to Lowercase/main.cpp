#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char ch;

    cin >> ch;

    if (isupper(ch))
    {
        ch = tolower(ch);
    }

    cout << "Lowercase character: " << ch << endl;

    return 0;
}