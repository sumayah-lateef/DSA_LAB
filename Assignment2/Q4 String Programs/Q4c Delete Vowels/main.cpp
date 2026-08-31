#include <iostream>
#include <string>
using namespace std;

bool isVowel(char ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' ||
           ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' ||
           ch == 'O' || ch == 'U';
}

int main()
{
    string str;

    getline(cin, str);

    cout << "String after deleting vowels: ";

    for (char ch : str)
    {
        if (!isVowel(ch))
        {
            cout << ch;
        }
    }

    cout << endl;

    return 0;
}