#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long

#define Graph vector<vector<ll>>
#define MOD 998244353

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll testcases;
    cin >> testcases;

    Graph dp(2001, vector<ll>(2001, 0));
    dp[0][0] = 1;

    // precompute the number of ways to arrange i planks into j sections
    for (ll i = 1; i <= 2000; i++) {
        for (ll j = 1; j <= i; j++) {
            // either add the plan as new section and rearrange or add the plank to an existing section
            dp[i][j] = ((i - j + 1) * dp[i - 1][j - 1] + (j * dp[i - 1][j])) % MOD;
        }
    }

    while (testcases--) {
        ll numberOfPlanks, amountOfSections;
        cin >> numberOfPlanks >> amountOfSections;
        cout << dp[numberOfPlanks][amountOfSections] << endl;
    }

    return 0;
}
