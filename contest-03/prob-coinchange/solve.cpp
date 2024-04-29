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
        ll debt, numberOfCoins;
        cin >> debt >> numberOfCoins;

        vector<ll> coins(numberOfCoins);
        for (auto& e : coins) cin >> e;

        ll maxSize = debt + 1.5 * pow(10, 6);
        vector<ll> dp(maxSize + 1, LONG_LONG_MAX);
        dp[0] = 0;
        dp[1] = 1;

        // classical upwards coin change dp calculation
        for (ll i = 2; i <= maxSize; ++i) {
            rep(j, numberOfCoins) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                } else {
                    break;
                }
            }
        }

        // downwards coin change dp calculation to consider solution with change
        for (ll i = maxSize; i > 1; --i) {
            rep(j, numberOfCoins) {
                if (coins[j] <= i) {
                    dp[i - coins[j]] = min(dp[i - coins[j]], dp[i] + 1);
                } else {
                    break;
                }
            }
        }

        cout << dp[debt] << endl;
    }

    return 0;
}
