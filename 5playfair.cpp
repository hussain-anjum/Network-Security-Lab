#include <bits/stdc++.h>
using namespace std;

int main() {
    char matrix[5][5];
    unordered_map<char, pair<int,int>> pos;

    cout << "Enter the 5x5 Playfair Matrix (25 letters, use j instead of i):\n";

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> matrix[i][j];
            matrix[i][j] = tolower(matrix[i][j]);
            if(matrix[i][j] == 'i')
                matrix[i][j] = 'j';
            pos[matrix[i][j]] = {i, j};
        }
    }

    cout << "\nKey Matrix:\n";
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    cout << "\nEnter Plaintext: ";
    string s, text = "";
    getline(cin >> ws, s);

    for(char c : s) {
        if(isalpha(c)) {
            c = tolower(c);
            if(c == 'i')
                c = 'j';
            text += c;
        }
    }

    string plain = "";
    for(int i = 0; i < text.size();) {
        plain += text[i];

        if(i == text.size() - 1) {
            plain += 'z';
            i++;
        }
        else if(text[i] == text[i + 1]) {
            plain += 'z';
            i++;
        }
        else {
            plain += text[i + 1];
            i += 2;
        }
    }

    cout << "Prepared Plaintext: " << plain << endl;

    string enc = "";
    for(int i = 0; i < plain.size(); i += 2) {
        auto [r1, c1] = pos[plain[i]];
        auto [r2, c2] = pos[plain[i + 1]];

        if(r1 == r2) {
            enc += matrix[r1][(c1 + 1) % 5];
            enc += matrix[r2][(c2 + 1) % 5];
        }
        else if(c1 == c2) {
            enc += matrix[(r1 + 1) % 5][c1];
            enc += matrix[(r2 + 1) % 5][c2];
        }
        else {
            enc += matrix[r1][c2];
            enc += matrix[r2][c1];
        }
    }

    cout << "Encrypted Text: " << enc << endl;

    string dec = "";
    for(int i = 0; i < enc.size(); i += 2) {
        auto [r1, c1] = pos[enc[i]];
        auto [r2, c2] = pos[enc[i + 1]];

        if(r1 == r2) {
            dec += matrix[r1][(c1 + 4) % 5];
            dec += matrix[r2][(c2 + 4) % 5];
        }
        else if(c1 == c2) {
            dec += matrix[(r1 + 4) % 5][c1];
            dec += matrix[(r2 + 4) % 5][c2];
        }
        else {
            dec += matrix[r1][c2];
            dec += matrix[r2][c1];
        }
    }

    string ans = "";
    for(int i = 0; i < dec.size(); i++) {
        if(i > 0 && i < dec.size() - 1 &&
           dec[i] == 'z' && dec[i - 1] == dec[i + 1])
            continue;
        ans += dec[i];
    }

    if(!ans.empty() && ans.back() == 'z')
        ans.pop_back();

    cout << "Decrypted Text: " << ans << endl;

    return 0;
}
