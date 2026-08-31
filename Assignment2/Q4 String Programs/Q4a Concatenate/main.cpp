#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1, str2;

    getline(cin, str1);
    getline(cin, str2);

    string result = str1 + str2;

    cout << "Concatenated string: " << result << endl;

    return 0;
}