#include <bits/stdc++.h>
using namespace std;

// No case conversion now
string normalizeText(const string &s) {
    string t;

    for (char ch : s) {
        if (isalpha((unsigned char)ch)) {
            t += ch; // keep original case
        }
    }

    if (t.size() % 2 == 1)
        t += 'X'; // padding (uppercase by default)

    return t;
}

// Case-sensitive shift
char shiftChar(char ch, int key) {
    if (isupper(ch)) {
        return char('A' + (ch - 'A' + key) % 26);
    }
    if (islower(ch)) {
        return char('a' + (ch - 'a' + key) % 26);
    }
    return ch;
}

char unshiftChar(char ch, int key) {
    if (isupper(ch)) {
        return char('A' + (ch - 'A' - key + 26) % 26);
    }
    if (islower(ch)) {
        return char('a' + (ch - 'a' - key + 26) % 26);
    }
    return ch;
}

string shiftText(const string &s, int key) {
    string r = s;
    for (char &ch : r) {
        ch = shiftChar(ch, key);
    }
    return r;
}

string feistelEncrypt(string text) {

    vector<int> keys = {3, 5, 7, 11};

    text = normalizeText(text);

    int half = text.size() / 2;

    string L = text.substr(0, half);
    string R = text.substr(half);

    for (int key : keys) {

        string F = shiftText(R, key);

        string newL = R;
        string newR = L;

        for (int i = 0; i < half; i++) {
            newR[i] = shiftChar(L[i], (F[i] - 'A') % 26);
        }

        L = newL;
        R = newR;
    }

    return L + R;
}

string feistelDecrypt(string text) {

    vector<int> keys = {3, 5, 7, 11};

    int half = text.size() / 2;

    string L = text.substr(0, half);
    string R = text.substr(half);

    for (int idx = keys.size() - 1; idx >= 0; idx--) {

        int key = keys[idx];

        string F = shiftText(L, key);

        string prevR = L;
        string prevL = R;

        for (int i = 0; i < half; i++) {
            prevL[i] = unshiftChar(R[i], (F[i] - 'A') % 26);
        }

        L = prevL;
        R = prevR;
    }

    string plain = L + R;

    if (!plain.empty() && plain.back() == 'X')
        plain.pop_back();

    return plain;
}

int main() {

    string text;

    cout << "Enter plaintext: ";
    getline(cin, text);

    string encrypted = feistelEncrypt(text);

    cout << "Encrypted text: " << encrypted << endl;

    string decrypted = feistelDecrypt(encrypted);

    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
