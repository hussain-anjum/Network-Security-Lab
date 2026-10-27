#include<bits/stdc++.h>
using namespace std;

int main() {

    cout << "Enter key size: ";
    int k;
    cin >> k;
    cin.ignore();

    cout << "Enter plaintext: ";
    string text;
    getline(cin, text);

    string s = "";
    for (char c : text)
        if (isalpha(c))
            s += tolower(c);

    while (s.size() % k != 0)
        s += 'x';

    int rows = s.size() / k;

    string encrypted = "";

    for (int col = 0; col < k; col++) {
        for (int row = 0; row < rows; row++) {
            encrypted += s[row * k + col];
        }
    }

    cout << "Encrypted text: " << encrypted << endl;

    string decrypted(s.size(), ' ');

    int index = 0;

    for (int col = 0; col < k; col++) {
        for (int row = 0; row < rows; row++) {
            decrypted[row * k + col] = encrypted[index++];
        }
    }

    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
