#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll testcases;
    cin >> testcases;

    while (testcases--) {
        ll no_of_snoflakes;
        cin >> no_of_snoflakes;

        // read input of snowflakes into a vector
        vector<ll> snoflakes(no_of_snoflakes);
        for (ll i = 0; i < no_of_snoflakes; i++) {
            cin >> snoflakes[i];
        }

        // track the last index of each snowflake
        unordered_map<ll, ll> cnt;
        ll longest_unique_sequence = 0;

        // find the longest unique sequence
        for (ll i = 0, j = 0; i < no_of_snoflakes; i++) {
            j = max(j, cnt[snoflakes[i]]);
            longest_unique_sequence = max(longest_unique_sequence, i - j + 1);
            cnt[snoflakes[i]] = i + 1;
        }

        cout << longest_unique_sequence << endl;
    }

    return 0;
}
