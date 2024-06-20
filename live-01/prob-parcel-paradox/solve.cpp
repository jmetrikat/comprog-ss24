#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

pair<ll, ll> bfs(vector<vector<ll>> &adj, ll start) {
    ll n = adj.size();
    vector<ll> dist(n, -1);
    queue<ll> q;

    q.push(start);
    dist[start] = 0;

    ll farthest_node = start;
    ll max_dist = 0;

    while (!q.empty()) {
        ll node = q.front();
        q.pop();

        for (ll neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
                if (dist[neighbor] > max_dist) {
                    max_dist = dist[neighbor];
                    farthest_node = neighbor;
                }
            }
        }
    }

    return {farthest_node, max_dist};
}

int main() {
    ll n;
    cin >> n;

    vector<vector<ll>> adj(n + 1);

    for (ll i = 0; i < n - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    pair<ll, ll> p1 = bfs(adj, 1);
    pair<ll, ll> p2 = bfs(adj, p1.first);
    ll diameter = p2.second;

    ll result = ceil(static_cast<double>(diameter + 1) / 2);

    cout << result << endl;

    return 0;
}
