#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long

using namespace std;

// construct the longest prefix suffix / partial match table
vector<ll> constructLPS(const string& pattern, ll n) {
    vector<ll> lps(n, 0);
    ll length = 0;
    ll i = 1;

    while (i < n) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// Knuth-Morris-Pratt algorithm
bool KMP(const string& text, const string& pattern, ll n, ll m) {
    vector<ll> lps = constructLPS(pattern, m);

    ll i = 0;
    ll j = 0;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        // check if the pattern is found
        if (j == m) {
            return true;
            // mismatch after j matches, update j using lps
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, m;
    cin >> n >> m;

    // read pattern and text sequences
    string str_a, str_b;
    char c;
    rep(i, n) {
        cin >> c;
        str_a += c;
    }
    rep(i, m) {
        cin >> c;
        str_b += c;
    }

    // determine shorter string
    string shorter = str_a, longer = str_b;
    if (str_a.size() > str_b.size()) {
        swap(shorter, longer);
    }

    // double the longer one
    longer += longer;

    // double the originally shorter one until it is longer than the doubled longer one
    while (shorter.size() <= longer.size()) {
        shorter += shorter;
    }

    // swap back to order: text, pattern
    swap(shorter, longer);

    if (KMP(longer, shorter, longer.size(), shorter.size())) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
