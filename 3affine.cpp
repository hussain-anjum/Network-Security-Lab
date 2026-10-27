#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two keys (additive, multiplicative): ";
    cin >> a >> b;

    while (gcd(26, b) != 1) {
        cout << "Multiplicative key must be coprime with 26. Enter again: ";
        cin >> b;
    }

    cin.ignore();
    cout << "Keys are: " << a << " " << b << endl;

    int inv_b = -1;
    for (int i = 1; i < 26; i++) {
        if ((b * i) % 26 == 1) {
            inv_b = i;
            break;
        }
    }

    cout << "Enter Plaintext: ";
    string text;
    getline(cin, text);

    string encrypted = text;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            encrypted[i] = ((text[i] - 'a') * b + a) % 26 + 'a';
        }
        else if (text[i] >= 'A' && text[i] <= 'Z') {
            encrypted[i] = ((text[i] - 'A') * b + a) % 26 + 'A';
        }
    }

    cout << "Ciphertext: " << encrypted << endl;

    string decrypted = encrypted;
    for (int i = 0; i < encrypted.length(); i++) {
        if (encrypted[i] >= 'a' && encrypted[i] <= 'z') {
            decrypted[i] = ((encrypted[i] - 'a' - a + 26) * inv_b) % 26 + 'a';
        }
        else if (encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            decrypted[i] = ((encrypted[i] - 'A' - a + 26) * inv_b) % 26 + 'A';
        }
    }

    cout << "Plaintext: " << decrypted << endl;

    return 0;
}
