#include <bits/stdc++.h>
using namespace std;

long long extGcd(long long a, long long b, long long &x, long long &y) {
    if (!b) return x = 1, y = 0, a;

    long long x1, y1;
    long long g = extGcd(b, a % b, x1, y1);

    return x = y1, y = x1 - (a / b) * y1, g;
}

long long modInverse(long long a, long long m) {
    long long x, y;
    return extGcd(a, m, x, y) == 1 ? (x % m + m) % m : -1;
}

int main() {
    vector<long long> priv = {2, 3, 7, 14, 30, 57, 120, 251};
    long long M = 491, W = 41;

    vector<long long> pub;
    for (auto a : priv)
        pub.push_back((W * a) % M);

    cout << "Public key: ";
    for (auto v : pub) cout << v << " ";
    cout << endl;

    string text;
    cout << "Enter plaintext: ";
    getline(cin, text);

    vector<long long> cipher;

    for (unsigned char ch : text) {
        long long sum = 0;

        for (int i = 0; i < 8; i++)
            if (ch & (1 << (7 - i)))
                sum += pub[i];

        cipher.push_back(sum);
    }

    cout << "Ciphertext: ";
    for (auto c : cipher) cout << c << " ";
    cout << endl;

    long long Winv = modInverse(W, M);

    string plain;

    for (auto c : cipher) {
        long long s = (c * Winv) % M;

        vector<int> bits(8, 0);

        for (int i = 7; i >= 0; i--) {
            if (priv[i] <= s) {
                bits[i] = 1;
                s -= priv[i];
            }
        }

        int val = 0;
        for (int i = 0; i < 8; i++)
            val = (val << 1) | bits[i];

        plain.push_back((char)val);
    }

    cout << "Decrypted text: " << plain << endl;
}
