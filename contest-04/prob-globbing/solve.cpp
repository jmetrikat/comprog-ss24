#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define ll long long

using namespace std;

bool machtes(const string &pattern, const string &text) {
    size_t textLength = text.size();

    // pattern contains the structure <prefix>*<suffix>, * means 0 or more characters
    if (pattern.find('*') != string::npos) {
        string prefix = pattern.substr(0, pattern.find('*'));
        string suffix = pattern.substr(pattern.find('*') + 1);

        // check that text is not shorter than prefix and suffix
        if (suffix.size() + prefix.size() > textLength) return false;

        // prefix and suffix need to match the text
        if (text.substr(0, prefix.size()) != prefix || text.substr(textLength - suffix.size()) != suffix) {
            return false;
        }

        return true;
    }

    // pattern contains the structure <prefix>+<suffix>, + means at least one character
    if (pattern.find('+') != string::npos) {
        string prefix = pattern.substr(0, pattern.find('+'));
        string suffix = pattern.substr(pattern.find('+') + 1);

        // check there is at least one character between prefix and suffix
        if (suffix.length() + prefix.size() + 1 > textLength) return false;

        // prefix and suffix need to match the text
        if (text.substr(0, prefix.size()) != prefix || text.substr(textLength - suffix.size()) != suffix) {
            return false;
        }

        // check if at least one character is between prefix and suffix
        return (textLength > prefix.size() + suffix.size());
    }

    // no special characters in the pattern
    return pattern == text;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll testcases;
    cin >> testcases;
    cin.ignore();

    while (testcases--) {
        string pattern, text;
        getline(cin, pattern);
        getline(cin, text);

        if (machtes(pattern, text)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
