#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int numberOfMonsters;
    cin >> numberOfMonsters;

    vector<long long> monsters(numberOfMonsters), dp(numberOfMonsters + 1);
    for (auto &monster : monsters) cin >> monster;
    dp[0] = 0, dp[1] = monsters[0];

    for (int i = 2; i <= numberOfMonsters; i++) {
        dp[i] = max(dp[i - 2] + monsters[i - 1], dp[i - 1]);
    }

    cout << dp[numberOfMonsters] << endl;
    return 0;
}
