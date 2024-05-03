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

    // dp[i] = maximum sum we can make using the first i items
    vector<long long> dp(M + 1, 0);
    for (ll i = 0; i < n; ++i) {
        for (ll j = M; j >= items[i]; --j) {
            dp[j] = max(dp[j], dp[j - items[i]] + items[i]);
        }
    }

    cout << dp[M] << endl;

    return 0;
}
