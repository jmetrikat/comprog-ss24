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

    ll n, m, s, t, c;
    cin >> n >> m;
    cin >> s >> t >> c;

    WeightedGraph adj(n + 1);
    rep(i, m) {
        ll u, v, p;
        cin >> u >> v >> p;
        adj[u].emplace_back(v, p);
        adj[v].emplace_back(u, p);
    }

    priority_queue<pair<ll, ll>> pq;
    vector<ll> max_diamonds(n + 1, 0);
    pq.push({c, s});
    max_diamonds[s] = c;

    while (!pq.empty()) {
        auto [diamonds, country] = pq.top();
        pq.pop();

        if (diamonds < max_diamonds[country]) continue;

        for (auto &[next_country, toll] : adj[country]) {
            ll next_diamonds = (diamonds - ceil(diamonds * toll) / 100);
            if (next_diamonds > max_diamonds[next_country]) {
                max_diamonds[next_country] = next_diamonds;
                pq.push({next_diamonds, next_country});
            }
        }
    }

    cout << max_diamonds[t] << endl;
    return 0;
}
