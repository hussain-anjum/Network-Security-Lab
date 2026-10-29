#include <iostream>
#include <string>
using namespace std;

int main()
{
    string key, roundKey = "";

    int PC2[48] = {
        14, 17, 11, 24, 1, 5,
        3, 28, 15, 6, 21, 10,
        23, 19, 12, 4, 26, 8,
        16, 7, 27, 20, 13, 2,
        41, 52, 31, 37, 47, 55,
        30, 40, 51, 45, 33, 48,
        44, 49, 39, 56, 34, 53,
        46, 42, 50, 36, 29, 32};

    // cout << "Program: DES Permuted Choice 2 (PC-2)" << endl;
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

    for (int i = 0; i < 48; i++)
    {
        roundKey += key[PC2[i] - 1];
    }

    cout << "48-bit Round Key: " << roundKey << endl;

    return 0;
}