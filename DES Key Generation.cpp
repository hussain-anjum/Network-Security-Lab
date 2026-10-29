#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Program Title: DES Key Generation (16 Round Keys)

    string key, key56, C, D;

    int PC1[56] = {
        57, 49, 41, 33, 25, 17, 9,
        1, 58, 50, 42, 34, 26, 18,
        10, 2, 59, 51, 43, 35, 27,
        19, 11, 3, 60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15,
        7, 62, 54, 46, 38, 30, 22,
        14, 6, 61, 53, 45, 37, 29,
        21, 13, 5, 28, 20, 12, 4};

    int PC2[48] = {
        14, 17, 11, 24, 1, 5,
        3, 28, 15, 6, 21, 10,
        23, 19, 12, 4, 26, 8,
        16, 7, 27, 20, 13, 2,
        41, 52, 31, 37, 47, 55,
        30, 40, 51, 45, 33, 48,
        44, 49, 39, 56, 34, 53,
        46, 42, 50, 36, 29, 32};

    int shifts[16] = {
        1, 1, 2, 2, 2, 2, 2, 2,
        1, 2, 2, 2, 2, 2, 2, 1};

    cout << "Program: DES Key Generation" << endl;
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

    // Step 1: Apply PC-1 to get a 56-bit key
    for (int i = 0; i < 56; i++)
    {
        key56 += key[PC1[i] - 1];
    }

    // Step 2: Split into two 28-bit halves
    C = key56.substr(0, 28);
    D = key56.substr(28, 28);

    // Step 3: Generate 16 round keys
    for (int round = 0; round < 16; round++)
    {

        // Circular left shift
        int shift = shifts[round];

        C = C.substr(shift) + C.substr(0, shift);
        D = D.substr(shift) + D.substr(0, shift);

        // Combine C and D into a 56-bit key
        string combined = C + D;

        // Apply PC-2 to get a 48-bit round key
        string roundKey = "";

        for (int i = 0; i < 48; i++)
        {
            roundKey += combined[PC2[i] - 1];
        }

        cout << "Round Key K" << round + 1
             << ": " << roundKey << endl;
    }

    return 0;
}