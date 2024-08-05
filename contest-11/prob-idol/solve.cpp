#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

int main() {
    ll k;
    cin >> k;

    ll n = 2 * k;
    ll m = 2 * k - 1;

    vector<tuple<ll, ll, ll>> edges;

    for (ll i = 1; i < 2 * k; ++i) {
        ll u = i;
        ll v = i + 1;
        ll w = (i <= k / 2 || i >= 1.5 * k) ? 100 : 1;
        edges.push_back({u, v, w});
    }

    cout << n << " " << m << endl;

    for (const auto& edge : edges) {
        ll u, v, w;
        tie(u, v, w) = edge;
        cout << u << " " << v << " " << w << endl;
    }

    return 0;
}
