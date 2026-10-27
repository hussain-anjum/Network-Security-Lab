#include <bits/stdc++.h>
using namespace std;

long long modPow(long long a, long long e, long long m) {
    long long res = 1;
    a %= m;

    while (e > 0) {
        if (e % 2)
            res = (res * a) % m;

        a = (a * a) % m;
        e /= 2;
    }
    return res;
}

long long extGcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }

    long long x1, y1;
    long long g = extGcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

long long modInverse(long long a, long long m) {
    long long x, y;
    long long g = extGcd(a, m, x, y);

    if (g != 1) return -1;

    return (x % m + m) % m;
}

long long hashMsg(const string &msg, long long q) {
    long long h = 0;
    for (char c : msg)
        h = (h * 31 + c) % q;
    return h;
}

int main() {
    long long p = 23, q = 11, g = 4;
    long long x, k;
    string msg;

    cout << "Enter private key x: ";
    cin >> x;

    cout << "Enter nonce k: ";
    cin >> k;

    cin.ignore();
    cout << "Enter message: ";
    getline(cin, msg);

    long long y = modPow(g, x, p);

    long long h = hashMsg(msg, q);

    long long r = modPow(g, k, p) % q;
    long long s = (modInverse(k, q) * (h + x * r)) % q;

    cout << "\nPublic Key (y): " << y << endl;
    cout << "Signature (r, s): (" << r << ", " << s << ")" << endl;

    long long w = modInverse(s, q);
    long long u1 = (h * w) % q;
    long long u2 = (r * w) % q;

    long long v = (modPow(g, u1, p) * modPow(y, u2, p) % p) % q;

    cout << "Verification value v: " << v << endl;

    if (v == r)
        cout << "Signature is VALID\n";
    else
        cout << "Signature is INVALID\n";

    return 0;
}
