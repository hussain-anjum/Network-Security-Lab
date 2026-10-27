#include <bits/stdc++.h>
using namespace std;

// Function to find modular inverse
int modInverse(int a, int m) {
    a %= m;
    if (a < 0) a += m;

    for (int i = 1; i < m; i++) {
        if ((a * i) % m == 1)
            return i;
    }

    return -1;
}

int main() {
    int a, b, c, d, det, detInv;

    // Take valid key matrix input
    while (true) {
        cout << "Enter the 2x2 key matrix:\n";
        cin >> a >> b;
        cin >> c >> d;

        det = (a * d - b * c) % 26;
        if (det < 0)
            det += 26;

        detInv = modInverse(det, 26);

        if (detInv != -1)
            break;

        cout << "Invalid key matrix! Determinant has no inverse modulo 26.\n";
        cout << "Please enter another matrix.\n\n";
    }

    cin.ignore();

    cout << "Enter plaintext: ";
    string text;
    getline(cin, text);

    // Remove spaces and convert to lowercase
    string s = "";
    for (char ch : text) {
        if (isalpha(ch))
            s += tolower(ch);
    }

    // Encryption
    string enc = "";

    for (int i = 0; i < s.size(); i += 2) {
        int p1 = s[i] - 'a';
        int p2 = (i + 1 < s.size()) ? s[i + 1] - 'a' : 'x' - 'a';

        int c1 = (a * p1 + b * p2) % 26;
        int c2 = (c * p1 + d * p2) % 26;

        enc += char(c1 + 'a');
        enc += char(c2 + 'a');
    }

    cout << "Encrypted text: " << enc << endl;

    // Inverse key matrix
    int invA = (d * detInv) % 26;
    int invB = (-b * detInv) % 26;
    int invC = (-c * detInv) % 26;
    int invD = (a * detInv) % 26;

    if (invB < 0) invB += 26;
    if (invC < 0) invC += 26;

    // Decryption
    string dec = "";

    for (int i = 0; i < enc.size(); i += 2) {
        int c1 = enc[i] - 'a';
        int c2 = enc[i + 1] - 'a';

        int p1 = (invA * c1 + invB * c2) % 26;
        int p2 = (invC * c1 + invD * c2) % 26;

        dec += char(p1 + 'a');
        dec += char(p2 + 'a');
    }

    cout << "Decrypted text: " << dec << endl;

    return 0;
}
