#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Program Title: DES Circular Left Shift (Round 1)

    string key, C0, D0, C1, D1;

    cout << "Program: DES Circular Left Shift (Round 1)" << endl;
    cout << "Enter 56-bit key: ";
    cin >> key;

    if (key.length() != 56)
    {
        cout << "Error: Key must contain exactly 56 bits." << endl;
        return 0;
    }

    for (int i = 0; i < 56; i++)
    {
        if (key[i] != '0' && key[i] != '1')
        {
            cout << "Error: Key must contain only 0 and 1." << endl;
            return 0;
        }
    }

    // Split the 56-bit key into two 28-bit parts
    C0 = key.substr(0, 28);
    D0 = key.substr(28, 28);

    // Circular left shift by one bit
    C1 = C0.substr(1) + C0[0];
    D1 = D0.substr(1) + D0[0];

    cout << "C0: " << C0 << endl;
    cout << "D0: " << D0 << endl;

    cout << "C1 after left shift: " << C1 << endl;
    cout << "D1 after left shift: " << D1 << endl;

    cout << "Combined 56-bit key: " << C1 + D1 << endl;

    return 0;
}