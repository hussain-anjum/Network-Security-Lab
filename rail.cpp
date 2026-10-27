#include <bits/stdc++.h>
using namespace std;

int main() {

    cout << "Enter plaintext: ";
    string text;
    getline(cin, text);
    string s = "";
    for (char c : text)
        if (isalpha(c))
            s += tolower(c);

    string even = "", odd = "";

    for (int i = 0; i < s.size(); i++) {
        if (i % 2 == 0) even += s[i];
        else odd += s[i];
    }

    string encrypted = even + odd;

    cout << "Encrypted text: " << encrypted << endl;

    int n = encrypted.size();
    int half = (n + 1) / 2;

    string first = encrypted.substr(0, half);
    string second = encrypted.substr(half);

    string decrypted = "";

    for (int i = 0; i < half; i++) {
        decrypted += first[i];
        if (i < second.size())
            decrypted += second[i];
    }

    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
