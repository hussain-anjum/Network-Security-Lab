#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a, b, result = "";

    cout << "1st 32-bit binary string: ";
    cin >> a;

    cout << "2nd 32-bit binary string: ";
    cin >> b;

    if (a.length() != 32 || b.length() != 32)
    {
        cout << "Both inputs must contain 32 bits" << endl;
        return 0;
    }

    for (int i = 0; i < 32; i++)
    {
        if ((a[i] != '0' && a[i] != '1') ||
            (b[i] != '0' && b[i] != '1'))
        {
            cout << "Inputs must contain only 0,1" << endl;
            return 0;
        }
    }

    for (int i = 0; i < 32; i++)
    {
        if (a[i] == b[i])
        {
            result += '0';
        }
        else
        {
            result += '1';
        }
    }
    cout << endl;
    cout << "XOR: " << result << endl;

    return 0;
}