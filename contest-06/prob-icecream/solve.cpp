#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>

using namespace std;

struct Edge {
    ll u, v;
    long long cost;
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

ll find(vector<ll>& parent, ll x) {
    // utilize path compression
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

void union_sets(vector<ll>& parent, vector<ll>& rank, ll x, ll y) {
    ll rootX = find(parent, x);
    ll rootY = find(parent, y);

    // union by rank
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, m;
    cin >> n >> m;

    // read freezer costs
    vector<ll> freezerCost(n);
    for (auto& cost : freezerCost) cin >> cost;

    // read weighted edges
    vector<Edge> edges;
    rep(i, m) {
        ll a, b, p;
        cin >> a >> b >> p;
        edges.push_back({a, b, p});
    }

    // add virtual node edges for freezer costs
    rep(i, n) edges.push_back({n, i, freezerCost[i]});

    // run kruskal's algorithm
    sort(all(edges));

    vector<ll> parent(n + 1);
    vector<ll> rank(n + 1, 0);
    iota(all(parent), 0);

    // calculate minimum cost to connect all nodes
    ll minCost = 0;
    for (const auto& edge : edges) {
        ll u = edge.u;
        ll v = edge.v;
        if (find(parent, u) != find(parent, v)) {
            union_sets(parent, rank, u, v);
            minCost += edge.cost;
        }
    }

    cout << minCost << endl;

    return 0;
}
