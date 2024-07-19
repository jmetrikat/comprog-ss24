#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    string text;
    getline(cin, text);

    char first, second;
    first = text.front();
    second = text.back();

    if (first != second) {
        cout << first << second << endl;
    }

    else {
        for (auto &c : text) {
            if (c != first) {
                cout << first << c << second << endl;
                return 0;
            }
        }
        cout << first << endl;
    }

    return 0;
}
