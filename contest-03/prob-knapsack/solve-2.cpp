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

    long long n, M;
    cin >> n >> M;

    vector<long long> items(n);
    for (auto &item : items) cin >> item;

    vector<bool> dp(M + 1, false);
    dp[0] = true;

    // dp[i] = true if we can make a sum of i using the items
    for (ll i = 0; i < n; ++i) {
        for (ll j = M - items[i]; j >= 0; --j) {
            if (dp[j]) {
                dp[j + items[i]] = true;
            }
        }
    }

    // check the maximum sum we can make
    for (ll i = M; i >= 0; --i) {
        if (dp[i]) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
