#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

void dfs(ll node, Graph &boss, vector<ll> &funFactors, vector<vector<ll>> &dp) {
    dp[node][0] = 0;                 // fun factor if node is not invited
    dp[node][1] = funFactors[node];  // fun factor if node is invited

    // maximize the fun factor by computing best score for inviting/not inviting each child
    for (ll child : boss[node]) {
        dfs(child, boss, funFactors, dp);
        dp[node][0] += max(dp[child][0], dp[child][1]);
        dp[node][1] += dp[child][0];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll numberOfColleagues;
    cin >> numberOfColleagues;

    vector<ll> funFactors(numberOfColleagues + 1);
    for (ll i = 1; i <= numberOfColleagues; ++i) {
        cin >> funFactors[i];
    }

    Graph boss(numberOfColleagues + 1);
    for (ll i = 2; i <= numberOfColleagues; i++) {
        ll directBoss;
        cin >> directBoss;
        boss[directBoss].push_back(i);
    }

    vector<vector<ll>> dp(numberOfColleagues + 1, vector<ll>(2));
    dfs(1, boss, funFactors, dp);

    cout << max(dp[1][0], dp[1][1]) << endl;

    return 0;
}
