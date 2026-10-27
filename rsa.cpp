#include <bits/stdc++.h>
using namespace std;

long long modPow(long long a, long long e, long long m) {
    long long r = 1 % m;
    a %= m;

    while (e > 0) {
        if (e & 1)
            r = (r * a) % m;

        a = (a * a) % m;
        e >>= 1;
    }

    return r;
}

long long extGcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
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

    if (g != 1)
        return -1;

    x %= m;

    if (x < 0)
        x += m;

    return x;
}

bool isPrime(long long n) {
    if (n < 2)
        return false;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main() {
    long long p, q;

    cout << "Enter prime p: ";
    cin >> p;

    cout << "Enter prime q: ";
    cin >> q;

    if (!isPrime(p) || !isPrime(q)) {
        cout << "Both numbers must be prime." << endl;
        return 0;
    }

    long long n = p * q;

    if (n <= 255) {
        cout << "Choose larger primes so that n > 255." << endl;
        return 0;
    }

    long long phi = (p - 1) * (q - 1);

    long long e = 3;

    while (e < phi && gcd(e, phi) != 1) {
        e += 2;
    }

    if (e >= phi) {
        cout << "No valid public exponent found." << endl;
        return 0;
    }

    long long d = modInverse(e, phi);

    cin.ignore();

    string text;

    cout << "Enter plaintext: ";
    getline(cin, text);

    cout << "Public key (e, n): ("
         << e << ", " << n << ")" << endl;

    cout << "Private key (d, n): ("
         << d << ", " << n << ")" << endl;

    vector<long long> cipher;

    for (unsigned char ch : text) {
        cipher.push_back(modPow((long long)ch, e, n));
    }

    cout << "Ciphertext: ";

    for (long long c : cipher) {
        cout << c << " ";
    }

    cout << endl;

    string plain;

    for (long long c : cipher) {
        plain.push_back((char)modPow(c, d, n));
    }

    cout << "Decrypted text: "
         << plain << endl;

    return 0;
}
