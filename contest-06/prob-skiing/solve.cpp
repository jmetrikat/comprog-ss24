#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

void topologicalSort(ll v, vector<bool>& visited, stack<ll>& Stack, const WeightedGraph& graph) {
    visited[v] = true;
    for (auto& edge : graph[v]) {
        ll u = edge.first;
        if (!visited[u]) {
            topologicalSort(u, visited, Stack, graph);
        }
    }
    Stack.push(v);
}

ll findLongestPath(ll n, const WeightedGraph& graph) {
    stack<ll> Stack;
    vector<bool> visited(n + 1, false);

    // sort vertices in topological order
    for (ll i = 1; i <= n; ++i) {
        if (!visited[i]) {
            topologicalSort(i, visited, Stack, graph);
        }
    }

    vector<ll> dist(n + 1, LLONG_MIN);

    // find longest path
    while (!Stack.empty()) {
        ll u = Stack.top();
        Stack.pop();

        if (dist[u] == LLONG_MIN) {
            dist[u] = 0;
        }

        for (auto& edge : graph[u]) {
            ll v = edge.first;
            ll weight = edge.second;
            if (dist[v] < dist[u] + weight) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // extract longest path
    ll maxDistance = LLONG_MIN;
    for (ll i = 1; i <= n; ++i) {
        if (dist[i] != LLONG_MIN) {
            maxDistance = max(maxDistance, dist[i]);
        }
    }

    return maxDistance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll testcases;
    cin >> testcases;

    while (testcases--) {
        ll n, m;
        cin >> n >> m;

        WeightedGraph graph(n + 1);
        rep(i, m) {
            ll u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
        }

        cout << findLongestPath(n, graph) << endl;
    }

    return 0;
}
