#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input, output = "";

    cout << "Enter a 6-bit binary string: ";
    cin >> input;

    if (input.length() != 6)
    {
        cout << "Error: Input must contain exactly 6 bits." << endl;
        return 0;
    }

    for (int i = 0; i < 6; i++)
    {
        if (input[i] != '0' && input[i] != '1')
        {
            cout << "Error: Only 0 and 1 are allowed." << endl;
            return 0;
        }
    }

    // Standard DES S1 box
    int S1[4][16] = {
        {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
        {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
        {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
        {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}};

    // Row: first and last bits
    int row = (input[0] - '0') * 2 + (input[5] - '0');

    // Column: middle four bits
    int col = 0;

    for (int i = 1; i <= 4; i++)
    {
        col = col * 2 + (input[i] - '0');
    }

    // Get the S-box value
    int value = S1[row][col];

    // Convert decimal value to 4-bit binary
    for (int bit = 8; bit >= 1; bit = bit / 2)
    {
        if (value >= bit)
        {
            output += '1';
            value -= bit;
        }
        else
        {
            output += '0';
        }
    }

    cout << "S-box output: " << output << endl;

    return 0;
}