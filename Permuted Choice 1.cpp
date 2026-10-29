#include <iostream>
#include <string>
using namespace std;

int main()
{
    string key, output = "";

    int PC1[56] = {
        57, 49, 41, 33, 25, 17, 9,
        1, 58, 50, 42, 34, 26, 18,
        10, 2, 59, 51, 43, 35, 27,
        19, 11, 3, 60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15,
        7, 62, 54, 46, 38, 30, 22,
        14, 6, 61, 53, 45, 37, 29,
        21, 13, 5, 28, 20, 12, 4};

    cout << "Program: DES Permuted Choice 1 (PC-1)" << endl;
    cout << "Enter 64-bit binary key: ";
    cin >> key;

    if (key.length() != 64)
    {
        cout << "Error: Key must contain exactly 64 bits." << endl;
        return 0;
    }

    for (int i = 0; i < 64; i++)
    {
        if (key[i] != '0' && key[i] != '1')
        {
            cout << "Error: Key must contain only 0 and 1." << endl;
            return 0;
        }
    }

    for (int i = 0; i < 56; i++)
    {
        output += key[PC1[i] - 1];
    }

    cout << "PC-1 Output (56-bit key): " << output << endl;

    return 0;
}