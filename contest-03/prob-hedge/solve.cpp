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
            // (i) either add the plan as new section and rearrange or (ii) add the plank to an existing section
            // for first case there are i + 1 points to place the new section, aka the new largest plank
            // but, at j points it wouldn't create a new section as the large plank would just extent an already existing section
            // therfore i - j + 1 points are valid to place the new section
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
