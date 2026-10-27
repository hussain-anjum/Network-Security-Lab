#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    cout << "Enter a character key: ";
    cin >> c;

    while (!isalpha(c)) {
        cout << "Key must be an alphabet. Enter again: ";
        cin >> c;
    }

    int key;
    if (isupper(c)) key = c - 'A';
    else key = c - 'a';

    cin.ignore();
    cout << "Key is: " << c << endl;

    cout << "Enter Plaintext: ";
    string text;
    getline(cin, text);

    string encrypted = text;
    int current_key = key;

    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            encrypted[i] = ((text[i] - 'a') + current_key) % 26 + 'a';
            current_key = text[i] - 'a';
        }
        else if (text[i] >= 'A' && text[i] <= 'Z') {
            encrypted[i] = ((text[i] - 'A') + current_key) % 26 + 'A';
            current_key = text[i] - 'A';
        }
    }

    cout << "Encrypted text: " << encrypted << endl;

    string decrypted = encrypted;
    current_key = key;

    for (int i = 0; i < encrypted.length(); i++) {
        if (encrypted[i] >= 'a' && encrypted[i] <= 'z') {
            decrypted[i] = ((encrypted[i] - 'a') - current_key + 52) % 26 + 'a';
            current_key = decrypted[i] - 'a';
        }
        else if (encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            decrypted[i] = ((encrypted[i] - 'A') - current_key + 52) % 26 + 'A';
            current_key = decrypted[i] - 'A';
        }
    }

    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
