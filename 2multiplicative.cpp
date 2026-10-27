#include <bits/stdc++.h>
using namespace std;

int main() {
    int key;
    cout << "Enter a preferred key: ";
    cin >> key;

    while (__gcd(26, key) != 1) {
        cout << "Key is not coprime to 26. Enter a new key: ";
        cin >> key;
    }

    cin.ignore();
    cout << "Key is: " << key << endl;

    int inverse_key = -1;
    for (int i = 1; i < 26; i++) {
        if ((key * i) % 26 == 1) {
            inverse_key = i;
            break;
        }
    }

    cout << "Enter Plaintext: ";
    string text;
    getline(cin, text);

    string encrypted = text;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            encrypted[i] = ((text[i] - 'a') * key) % 26 + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            encrypted[i] = ((text[i] - 'A') * key) % 26 + 'A';
        }
    }

    cout << "Ciphertext: " << encrypted << endl;

    string decrypted = encrypted;
    for (int i = 0; i < encrypted.length(); i++) {
        if (encrypted[i] >= 'a' && encrypted[i] <= 'z') {
            decrypted[i] = ((encrypted[i] - 'a') * inverse_key) % 26 + 'a';
        } else if (encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            decrypted[i] = ((encrypted[i] - 'A') * inverse_key) % 26 + 'A';
        }
    }

    cout << "Plaintext: " << decrypted << endl;

    return 0;
}
