#include <bits/stdc++.h>
using namespace std;

long long modPow(long long a, long long e, long long m) {
    long long r = 1;
    while (e) {
        if (e & 1) r = (r * a) % m;
        a = (a * a) % m;
        e >>= 1;
    }
    return r;
}

long long extGcd(long long a, long long b, long long &x, long long &y) {
    if (!b) return x = 1, y = 0, a;
    long long x1, y1, g = extGcd(b, a % b, x1, y1);
    return x = y1, y = x1 - (a / b) * y1, g;
}

long long modInverse(long long a, long long m) {
    long long x, y;
    return extGcd(a, m, x, y) == 1 ? (x % m + m) % m : -1;
}

long long crt(long long ap, long long aq, long long p, long long q) {
    long long t = ((aq - ap) % q + q) % q;
    long long pInv = modInverse(p, q);
    return (ap + p * (t * pInv % q)) % (p * q);
}

int main() {
    long long p = 383, q = 503, n = p * q;
    string text;

    cout << "Enter plaintext: ";
    getline(cin, text);

    vector<long long> cipher;

    for (char ch : text) {
        long long m = ch * 100 + 19;
        cipher.push_back((m * m) % n);
    }

    cout << "Ciphertext: ";
    for (auto c : cipher) cout << c << " ";
    cout << endl;

    string plain;

    for (auto c : cipher) {
        long long rp = modPow(c, (p + 1) / 4, p);
        long long rq = modPow(c, (q + 1) / 4, q);

        vector<long long> cand = {
            crt(rp, rq, p, q),
            crt(rp, (q - rq) % q, p, q),
            crt((p - rp) % p, rq, p, q),
            crt((p - rp) % p, (q - rq) % q, p, q)
        };

        char decoded = '?';

        for (long long m : cand) {
            if (m % 100 == 19) {
                long long ch = m / 100;
                if (ch >= 0 && ch <= 255) {
                    decoded = (char)ch;
                    break;
                }
            }
        }

        plain += decoded;
    }

    cout << "Decrypted text: " << plain << endl;
}
