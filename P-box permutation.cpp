#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input, output = "";

    cout << "Enter a 32-bit binary string: ";
    cin >> input;

    if (input.length() != 32)
    {
        cout << "Error: Input must contain 32 bits." << endl;
        return 0;
    }

    for (int i = 0; i < 32; i++)
    {
        if (input[i] != '0' && input[i] != '1')
        {
            cout << "Error: Only 0 and 1 are allowed." << endl;
            return 0;
        }
    }

    // Standard P-box permutation table
    int P[32] = {
        16, 7, 20, 21,
        29, 12, 28, 17,
        1, 15, 23, 26,
        5, 18, 31, 10,
        2, 8, 24, 14,
        32, 27, 3, 9,
        19, 13, 30, 6,
        22, 11, 4, 25};

    // Rearrange the 32 bits
    for (int i = 0; i < 32; i++)
    {
        output += input[P[i] - 1];
    }

    cout << "P-box output: " << output << endl;

    return 0;
}