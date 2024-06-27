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
    ll w, l;
    cin >> w >> l;

    vector<ll> resilience(w - 1);
    for (auto &r : resilience) cin >> r;

    ll source = 0;
    ll sink = 2 * w;  // Adjust sink to accommodate the new nodes

    Graph capacity(2 * w + 1, vector<ll>(2 * w + 1, 0));
    Graph adj(2 * w + 1);

    // Add edges from the source to the stones within jump range
    for (ll i = 1; i <= l && i < w; ++i) {
        if (resilience[i - 1] > 0) {
            capacity[source][2 * i - 1] = resilience[i - 1];
            adj[source].push_back(2 * i - 1);
            adj[2 * i - 1].push_back(source);
        }
    }

    // Add edges between stones within jump range
    for (ll i = 1; i < w; ++i) {
        if (resilience[i - 1] > 0) {
            // Split node into two nodes with capacity resilience[i-1]
            capacity[2 * i - 1][2 * i] = resilience[i - 1];
            adj[2 * i - 1].push_back(2 * i);
            adj[2 * i].push_back(2 * i - 1);

            for (ll j = 1; j <= l && i + j < w; ++j) {
                if (resilience[i + j - 1] > 0) {
                    capacity[2 * i][2 * (i + j) - 1] = resilience[i + j - 1];
                    adj[2 * i].push_back(2 * (i + j) - 1);
                    adj[2 * (i + j) - 1].push_back(2 * i);
                }
            }
        }
    }

    // Add edges from stones within jump range of the end to the sink
    for (ll i = w - l; i < w; ++i) {
        if (resilience[i - 1] > 0) {
            capacity[2 * i][sink] = resilience[i - 1];
            adj[2 * i].push_back(sink);
            adj[sink].push_back(2 * i);
        }
    }

    // Find the maximum flow from source to sink
    cout << edmondsKarp(source, sink, capacity, adj, 2 * w) << endl;

    return 0;
}
