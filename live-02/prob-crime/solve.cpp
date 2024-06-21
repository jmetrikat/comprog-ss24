#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

void dfs(const Graph &tree, vector<ll> &leaf_count, ll v, ll parent) {
    leaf_count[v] = (tree[v].size() == 1 && v != 1) ? 1 : 0;
    for (ll u : tree[v]) {
        if (u != parent) {
            dfs(tree, leaf_count, u, v);
            leaf_count[v] += leaf_count[u];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n;
    cin >> n;

    Graph tree(n + 1);
    vector<ll> leaf_count(n + 1, 0);

    rep(i, n - 1) {
        ll u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(tree, leaf_count, 1, -1);

    ll q;
    cin >> q;
    while (q--) {
        ll xj, yj;
        cin >> xj >> yj;
        cout << leaf_count[xj] * leaf_count[yj] << endl;
    }

    return 0;
}
