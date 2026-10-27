#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Enter key (no spaces): ";
    string key;
    cin >> key;

    vector<int> k;
    for (char c : key) {
        if (isupper(c)) k.push_back(c - 'A');
        else if (islower(c)) k.push_back(c - 'a');
    }

    int key_len = k.size();

    if (key_len == 0) {
        cout << "Invalid key!" << endl;
        return 0;
    }

    cin.ignore();

    cout << "Enter Plaintext: ";
    string text;
    getline(cin, text);

    string encrypted = text;
    int j = 0;

    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            encrypted[i] = ((text[i] - 'a') + k[j]) % 26 + 'a';
            j = (j + 1) % key_len;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z') {
            encrypted[i] = ((text[i] - 'A') + k[j]) % 26 + 'A';
            j = (j + 1) % key_len;
        }
    }

    cout << "Encrypted text: " << encrypted << endl;

    string decrypted = encrypted;
    j = 0;

    for (int i = 0; i < encrypted.length(); i++) {
        if (encrypted[i] >= 'a' && encrypted[i] <= 'z') {
            decrypted[i] = ((encrypted[i] - 'a') - k[j] + 26) % 26 + 'a';
            j = (j + 1) % key_len;
        }
        else if (encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            decrypted[i] = ((encrypted[i] - 'A') - k[j] + 26) % 26 + 'A';
            j = (j + 1) % key_len;
        }
    }

    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
