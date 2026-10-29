#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input, output = "";

    cout << "Enter a 64-bit binary string: ";
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
            cout << "Error: Only 0 and 1 are allowed." << endl;
            return 0;
        }
    }

    // Standard Initial Permutation table
    int IP[64] = {
        58, 50, 42, 34, 26, 18, 10, 2,
        60, 52, 44, 36, 28, 20, 12, 4,
        62, 54, 46, 38, 30, 22, 14, 6,
        64, 56, 48, 40, 32, 24, 16, 8,
        57, 49, 41, 33, 25, 17, 9, 1,
        59, 51, 43, 35, 27, 19, 11, 3,
        61, 53, 45, 37, 29, 21, 13, 5,
        63, 55, 47, 39, 31, 23, 15, 7};

    // Apply Initial Permutation
    for (int i = 0; i < 64; i++)
    {
        output += input[IP[i] - 1];
    }

    cout << "IP output: " << output << endl;

    return 0;
}