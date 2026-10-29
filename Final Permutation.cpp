#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input, output = "";

    int FP[64] = {
        40, 8, 48, 16, 56, 24, 64, 32,
        39, 7, 47, 15, 55, 23, 63, 31,
        38, 6, 46, 14, 54, 22, 62, 30,
        37, 5, 45, 13, 53, 21, 61, 29,
        36, 4, 44, 12, 52, 20, 60, 28,
        35, 3, 43, 11, 51, 19, 59, 27,
        34, 2, 42, 10, 50, 18, 58, 26,
        33, 1, 41, 9, 49, 17, 57, 25};

    // cout << "Program: DES Final Permutation (FP)" << endl;
    cout << "Enter 64-bit binary input: ";
    cin >> input;

    if (input.length() != 64)
    {
        cout << "Error: Input must contain exactly 64 bits." << endl;
        return 0;
    }

    for (int i = 0; i < 64; i++)
    {
        if (input[i] != '0' && input[i] != '1')
        {
            cout << "Error: Input must contain only 0 and 1." << endl;
            return 0;
        }
    }

    for (int i = 0; i < 64; i++)
    {
        output += input[FP[i] - 1];
    }

    cout << "FP Output: " << output << endl;

    return 0;
}