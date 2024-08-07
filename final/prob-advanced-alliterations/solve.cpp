#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;
ll NUM_OF_CHARS = 26;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<vector<int>> prefix_freq(n + 1, vector<int>(NUM_OF_CHARS, 0));

    rep(i, n) {
        if (i > 0) {
            rep(j, NUM_OF_CHARS) {
                prefix_freq[i + 1][j] = prefix_freq[i][j];
            }
        }
        prefix_freq[i + 1][s[i] - 'a']++;
    }

    while (q--) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;

        vector<int> freq(NUM_OF_CHARS, 0);
        rep(i, NUM_OF_CHARS) {
            freq[i] = prefix_freq[b + 1][i] - prefix_freq[a][i];
        }

        char most_frequent_char = 'a';
        int max_freq = 0;
        rep(i, NUM_OF_CHARS) {
            if (freq[i] > max_freq || (freq[i] == max_freq && 'a' + i < most_frequent_char)) {
                max_freq = freq[i];
                most_frequent_char = 'a' + i;
            }
        }

        cout << most_frequent_char << endl;
    }

    return 0;
}
