#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

struct Edge {
    ll from, to;
    double weight;
};

bool bellmanFord(ll n, const vector<Edge>& edges, vector<int>& parent, ll& start) {
    vector<double> distance(n, numeric_limits<double>::max());
    distance[0] = 0;
    start = -1;

    // go through all edges n times
    rep(i, n) {
        for (const Edge& edge : edges) {
            // relax edge if possible
            if (distance[edge.from] + edge.weight < distance[edge.to]) {
                distance[edge.to] = distance[edge.from] + edge.weight;
                parent[edge.to] = edge.from;

                // if we can relax any edge in the last iteration, we have a negative cycle
                if (i == n - 1) {
                    start = edge.to;
                }
            }
        }
    }

    // return true if we found a negative cycle
    return start != -1;
}

vector<int> findNegativeCycle(ll start, const vector<int>& parent) {
    vector<int> cycle;
    ll current = start;

    // go n steps back to find the start of the cycle
    rep(i, (ll)parent.size()) {
        current = parent[current];
    }

    // go through the cycle and add all nodes to the cycle, but don't add the start node twice
    for (ll v = current;; v = parent[v]) {
        if (v == current && cycle.size() > 1) break;
        cycle.push_back(v);
    }

    reverse(all(cycle));
    return cycle;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n;
    cin >> n;

    // read currencies
    vector<string> currencies(n);
    rep(i, n) {
        cin >> currencies[i];
    }

    // read exchange rates (edges) between currencies (nodes)
    vector<Edge> edges;
    rep(i, n) {
        rep(j, n) {
            double logRate;
            cin >> logRate;
            if (i != j) {
                // add edge from i to j with weight -logRate
                // (negative value as finding glitch is equal to finding positive cycle)
                // (by inverting we can use standard Bellman-Ford algorithm and find negative cycle)
                edges.push_back({i, j, -logRate});
            }
        }
    }

    // run bellman-ford to check for glitch
    vector<int> parent(n, -1);
    ll start;
    if (!bellmanFord(n, edges, parent, start)) {
        cout << "noglitch" << endl;
    } else {
        // reconstruct negative cycle
        vector<int> cycle = findNegativeCycle(start, parent);
        cout << "money!" << endl;
        cout << cycle.size() << endl;
        for (int v : cycle) {
            cout << currencies[v] << " ";
        }
        cout << endl;
    }

    return 0;
}
