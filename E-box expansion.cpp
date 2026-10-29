
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

    // Standard expansion table
    int E[48] = {
        32, 1, 2, 3, 4, 5,
        4, 5, 6, 7, 8, 9,
        8, 9, 10, 11, 12, 13,
        12, 13, 14, 15, 16, 17,
        16, 17, 18, 19, 20, 21,
        20, 21, 22, 23, 24, 25,
        24, 25, 26, 27, 28, 29,
        28, 29, 30, 31, 32, 1};

    // Perform E-box expansion
    for (int i = 0; i < 48; i++)
    {
        output += input[E[i] - 1];
    }

    cout << "E-box output: " << output << endl;

    return 0;
}
