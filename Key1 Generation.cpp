#include <iostream>
#include <string>
using namespace std;

int main()
{
    string key, key56, C, D, combined, K1 = "";

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

    // cout << "Program: DES Round 1 Key Generation (K1)" << endl;
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

    // Step 1: Apply PC-1 to get 56 bits
    for (int i = 0; i < 56; i++)
    {
        key56 += key[PC1[i] - 1];
    }

    // Step 2: Split into two 28-bit halves
    C = key56.substr(0, 28);
    D = key56.substr(28, 28);

    // Step 3: Circular left shift by one bit
    C = C.substr(1) + C[0];
    D = D.substr(1) + D[0];

    // Step 4: Combine C1 and D1
    combined = C + D;

    // Step 5: Apply PC-2 to generate K1
    for (int i = 0; i < 48; i++)
    {
        K1 += combined[PC2[i] - 1];
    }

    cout << "K1: " << K1 << endl;

    return 0;
}