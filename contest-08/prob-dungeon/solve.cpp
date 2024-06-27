#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

struct Edge {
    ll to, capacity, flow, rev;
};

const ll MAXN = 5002;
Graph adj(MAXN);
Graph capacity(MAXN, vector<ll>(MAXN, 0));

bool bfs(ll s, ll t, vector<ll>& parent) {
    vector<bool> visited(MAXN, false);
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

long long edmondsKarp(ll s, ll t) {
    long long max_flow = 0;
    vector<ll> parent(MAXN);

    while (bfs(s, t, parent)) {
        long long path_flow = LLONG_MAX;
        for (ll v = t; v != s; v = parent[v]) {
            ll u = parent[v];
            path_flow = min(path_flow, capacity[u][v]);
        }

        for (ll v = t; v != s; v = parent[v]) {
            ll u = parent[v];
            capacity[u][v] -= path_flow;
            capacity[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

void add_edge(ll u, ll v, ll cap) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    capacity[u][v] = cap;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll s;
    cin >> s;
    while (s--) {
        ll w, h, p;
        cin >> w >> h >> p;

        vector<pair<ll, ll>> members(p);
        for (auto& [x, y] : members) {
            cin >> x >> y;
        }

        // Use a super source and a super sink in flow network
        ll source = 0;
        ll sink = 1;
        ll node_count = 2;
        map<pair<ll, ll>, pair<ll, ll>> node_map;

        // Model nodes as in- and out-nodes to enforce node capacity constraint
        auto get_node_in = [&](ll x, ll y) {
            if (node_map.find({x, y}) == node_map.end()) {
                node_map[{x, y}] = {node_count, node_count + 1};
                node_count += 2;
            }
            return node_map[{x, y}].first;
        };

        auto get_node_out = [&](ll x, ll y) {
            if (node_map.find({x, y}) == node_map.end()) {
                node_map[{x, y}] = {node_count, node_count + 1};
                node_count += 2;
            }
            return node_map[{x, y}].second;
        };

        // Connect the source to the members
        for (const auto& member : members) {
            ll x = member.first;
            ll y = member.second;
            add_edge(source, get_node_in(x, y), 1);
        }

        // Connect nodes in the grid
        for (ll i = 1; i <= w; ++i) {
            for (ll j = 1; j <= h; ++j) {
                ll in_node = get_node_in(i, j);
                ll out_node = get_node_out(i, j);
                add_edge(in_node, out_node, 1);

                // Connect nodes to their neighbors
                if (i > 1) add_edge(out_node, get_node_in(i - 1, j), 1);
                if (i < w) add_edge(out_node, get_node_in(i + 1, j), 1);
                if (j > 1) add_edge(out_node, get_node_in(i, j - 1), 1);
                if (j < h) add_edge(out_node, get_node_in(i, j + 1), 1);

                // Connect the edges of the grid to the sink
                if (i == 1 || i == w || j == 1 || j == h) {
                    add_edge(get_node_out(i, j), sink, 1);
                }
            }
        }

        // Check if all members can escape the grid
        long long maxFlow = edmondsKarp(source, sink);
        if (maxFlow == p) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        for (ll i = 0; i < MAXN; ++i) {
            adj[i].clear();
            fill(capacity[i].begin(), capacity[i].end(), 0);
        }
    }

    return 0;
}
