#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

struct Edge {
    ll to, length, id;
};

vector<ll> dijkstra(ll source, const vector<vector<Edge>>& adj, ll n) {
    vector<ll> dist(n + 1, numeric_limits<ll>::max());
    dist[source] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [distance, node] = pq.top();
        pq.pop();

        if (distance > dist[node]) continue;

        for (const Edge& e : adj[node]) {
            if (dist[node] + e.length < dist[e.to]) {
                dist[e.to] = dist[node] + e.length;
                pq.push({dist[e.to], e.to});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, m;
    cin >> n >> m;

    // read edges between cities with lengths and ids
    vector<vector<Edge>> adj(n + 1);
    for (ll i = 1; i <= m; ++i) {
        ll c1, c2, l;
        cin >> c1 >> c2 >> l;
        adj[c1].push_back({c2, l, i});
        adj[c2].push_back({c1, l, i});
    }

    // run dijkstra from both directions to find all shortest paths
    vector<ll> dist_from_1 = dijkstra(1, adj, n);
    vector<ll> dist_from_2 = dijkstra(2, adj, n);
    ll shortest_path_length = dist_from_1[2];

    // collect essential edges
    vector<ll> essential_edges;
    for (ll u = 1; u <= n; ++u) {
        for (const Edge& e : adj[u]) {
            if (dist_from_1[u] + e.length + dist_from_2[e.to] == shortest_path_length) {
                essential_edges.push_back(e.id);
            }
        }
    }

    // print the number of essential edges and their ids in ascending order
    sort(all(essential_edges));
    cout << essential_edges.size() << endl;
    for (ll id : essential_edges) {
        cout << id << ' ';
    }
    cout << endl;

    return 0;
}
