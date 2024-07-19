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

    ll n;
    cin >> n;
    vector<ll> strengths(n);
    rep(i, n) {
        cin >> strengths[i];
    }

    sort(all(strengths));

    ll max_sum = 0;
    for (ll i = n / 3; i < n; i += 2) {
        max_sum += strengths[i];
    }
    cout << max_sum << endl;

    return 0;
}
