#include<bits/stdc++.h>
using namespace std;

int main() {

    int k;
    cout << "Enter key length: ";
    cin >> k;
    cin.ignore();

    cout << "Enter plaintext: ";
    string text;
    getline(cin, text);

    string s = "";
    for (char c : text)
        if (isalpha(c))
            s += tolower(c);

    int n = s.size();

    while (n % k != 0) {
        s += 'x';
        n++;
    }

    string col_enc = "";

    for (int col = 0; col < k; col++) {
        for (int i = col; i < n; i += k) {
            col_enc += s[i];
        }
    }
    string even = "", odd = "";

    for (int i = 0; i < col_enc.size(); i++) {
        if (i % 2 == 0) even += col_enc[i];
        else odd += col_enc[i];
    }

    string encrypted = even + odd;

    cout << "Encrypted text: " << encrypted << endl;

    int len = encrypted.size();
    int half = (len + 1) / 2;

    string first = encrypted.substr(0, half);
    string second = encrypted.substr(half);

    string rail_dec = "";

    for (int i = 0; i < half; i++) {
        rail_dec += first[i];
        if (i < second.size())
            rail_dec += second[i];
    }

    int rows = rail_dec.size() / k;
    string col_dec(rows * k, ' ');

    int idx = 0;

    for (int col = 0; col < k; col++) {
        for (int row = 0; row < rows; row++) {
            col_dec[row * k + col] = rail_dec[idx++];
        }
    }

    cout << "Decrypted text: " << col_dec << endl;

    return 0;
}
