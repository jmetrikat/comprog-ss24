#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

void dfs(Graph& G, ll start, ll& index, vector<ll>& from, vector<ll>& to, vector<bool>& visited, vector<ll>& preorder) {
    visited[start] = true;
    preorder[index] = start;
    from[start] = index;
    for (auto v : G[start]) {
        if (visited[v]) continue;
        dfs(G, v, ++index, from, to, visited, preorder);
    }
    to[start] = index;
}

void build(Graph& tree, vector<ll>& colors, ll v, ll tl, ll tr, vector<ll>& perm) {
    if (tl == tr) {
        tree[v].push_back(colors[perm[tl]]);
    } else {
        ll tm = tl + (tr - tl) / 2;
        build(tree, colors, 2 * v, tl, tm, perm);
        build(tree, colors, 2 * v + 1, tm + 1, tr, perm);
        merge(all(tree[2 * v]), all(tree[2 * v + 1]), back_inserter(tree[v]));
    }
}

ll query(Graph& tree, ll v, ll tl, ll tr, ll l, ll r, ll color) {
    if (l > r)
        return 0;
    else if (tl == l && tr == r) {
        auto front = lower_bound(all(tree[v]), color);
        if (front == tree[v].end()) return 0;
        auto back = upper_bound(all(tree[v]), color);
        return distance(front, back);
    } else {
        ll tm = tl + (tr - tl) / 2;
        return query(tree, 2 * v, tl, tm, l, min(tm, r), color) +
               query(tree, 2 * v + 1, tm + 1, tr, max(tm + 1, l), r, color);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;
    Graph G(n);
    rep(i, n - 1) {
        ll a, b;
        cin >> a >> b >> ws;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<ll> colors(n);
    cin >> hex;
    rep(i, n) {
        cin.ignore(3, '#');
        cin >> colors[i] >> ws;
    }

    cin >> dec;
    vector<bool> visited(n, false);
    vector<ll> from(n), to(n), preorder(n);
    ll start_index = 0;

    dfs(G, 0, start_index, from, to, visited, preorder);
    vector<vector<ll>> tree(4 * n);
    build(tree, colors, 1, 0, n - 1, preorder);

    rep(i, q) {
        ll p, color;
        cin >> p;
        cin.ignore(3, '#');
        cin >> hex >> color >> dec;
        p--;
        cout << query(tree, 1, 0, n - 1, from[p], to[p], color) << "\n";
    }

    return 0;
}
