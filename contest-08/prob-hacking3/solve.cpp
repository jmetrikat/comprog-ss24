#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

bool bfs(ll s, ll t, vector<ll> &parent, Graph &capacity, Graph &adj, ll n) {
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

ll edmondsKarp(ll s, ll t, Graph &capacity, Graph &adj, ll n) {
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, m;
    cin >> n >> m;

    Graph capacity(n + 1, vector<ll>(n + 1, 0));
    Graph adj(n + 1);

    vector<tuple<ll, ll, ll>> edges(m);

    rep(i, m) {
        ll u, v, cap;
        cin >> u >> v >> cap;
        edges[i] = {u, v, cap};
        capacity[u][v] += cap;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll maxFlow = edmondsKarp(1, n, capacity, adj, n);

    // Find the minimum cut
    vector<bool> visited(n + 1, false);
    queue<ll> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (ll v : adj[u]) {
            if (capacity[u][v] > 0 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    vector<ll> result;
    rep(i, m) {
        auto [u, v, cap] = edges[i];
        if (visited[u] && !visited[v]) {
            result.push_back(i + 1);
        }
    }

    cout << result.size() << " " << maxFlow << endl;
    for (ll idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
