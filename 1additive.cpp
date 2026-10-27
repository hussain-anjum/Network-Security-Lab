#include <bits/stdc++.h>
using namespace std;

int main() {
    int key;
    string text, encrypted, decrypted;

    cout << "Enter key: ";
    cin >> key;
    cin.ignore();

    cout << "Enter plaintext: ";
    getline(cin, text);

    encrypted = text;

    for (char &c : encrypted) {
        if (c >= 'a' && c <= 'z')
            c = (c - 'a' + key + 26) % 26 + 'a';
        else if (c >= 'A' && c <= 'Z')
            c = (c - 'A' + key + 26) % 26 + 'A';
    }

    cout << "Ciphertext: " << encrypted << endl;

    decrypted = encrypted;

    for (char &c : decrypted) {
        if (c >= 'a' && c <= 'z')
            c = (c - 'a' - key + 26) % 26 + 'a';
        else if (c >= 'A' && c <= 'Z')
            c = (c - 'A' - key + 26) % 26 + 'A';
    }

    cout << "Plaintext: " << decrypted << endl;

    return 0;
}
