#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

// BFS to find an augmenting path and store the path in parent array
bool bfs(ll s, ll t, vector<ll> &parent, vector<vector<ll>> &capacity, vector<vector<ll>> &adj, ll n) {
    vector<bool> visited(n + 1, false);
    queue<ll> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        ll u = q.front();
        q.pop();

        for (ll v : adj[u]) {
            if (!visited[v] && capacity[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
                if (v == t) {
                    return true;
                }
            }
        }
    }
    return false;
}

// max flow algorithm adding path flows to sum until no more augmenting paths can be found
ll edmondsKarp(ll s, ll t, vector<vector<ll>> &capacity, vector<vector<ll>> &adj, ll n) {
    ll max_flow = 0;
    vector<ll> parent(n + 1);

    while (bfs(s, t, parent, capacity, adj, n)) {
        ll path_flow = LLONG_MAX;
        for (ll v = t; v != s; v = parent[v]) {
            ll u = parent[v];
            path_flow = min(path_flow, capacity[u][v]);
        }

        for (ll v = t; v != s; v = parent[v]) {
            ll u = parent[v];
            capacity[u][v] -= path_flow;  // forward flow
            capacity[v][u] += path_flow;  // backward flow
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    ll n, m;
    cin >> n >> m;

    Graph capacity(n + 1, vector<ll>(n + 1, 0));
    Graph adj(n + 1);

    rep(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;

        // graph is undirected
        capacity[a][b] += c;
        capacity[b][a] += c;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // find maximum flow from node 1 to node 2
    cout << edmondsKarp(1, 2, capacity, adj, n) << endl;

    return 0;
}
