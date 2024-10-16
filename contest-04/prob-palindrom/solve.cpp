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

    string s;
    getline(cin, s);

    ll n = s.size();
    Graph dp(s.size(), vector<ll>(n, 0));

    // dynamically fill the dp table
    for (ll len = 2; len <= n; ++len) {
        for (ll i = 0; i <= n - len; ++i) {
            ll j = i + len - 1;
            if (s[i] == s[j]) {
                // 'aa' has costs of 0, as this is alread a palindrom
                // 'a…a' has cost of '…', as only the inner part needs to be turned into a palindrom
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                // 3 possible ways to turn the substring into a palindrom
                // we never add a character as it's equal to removing one: ab…b -> ab…ba = b…b
                dp[i][j] = 1 + min({
                                   dp[i + 1][j],     // remove the first character: ab…b -> b…b
                                   dp[i][j - 1],     // remove the last character: b…ba -> b…b
                                   dp[i + 1][j - 1]  // replace one of the characters with the other: a…b -> a…a or b…b
                               });
            }
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}
