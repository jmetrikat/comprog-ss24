#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

struct Class {
    ll sword, sorcery;
};

ll squaredDifference(ll a, ll b) {
    return pow(a - b, 2);
}

vector<ll> dijkstra(int source, const WeightedGraph &graph, int n) {
    vector<ll> dist(n + 1, numeric_limits<ll>::max());
    dist[source] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [distance, node] = pq.top();
        pq.pop();

        if (distance > dist[node]) continue;

        for (auto [neighbour, weight] : graph[node]) {
            if (dist[node] + weight < dist[neighbour]) {
                dist[neighbour] = dist[node] + weight;
                pq.push({dist[neighbour], neighbour});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n;
    cin >> n;

    // read class stats
    vector<Class> classes(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> classes[i].sword >> classes[i].sorcery;
    }

    ll m;
    cin >> m;

    // create weighted graph
    WeightedGraph graph(n + 1);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        ll d = squaredDifference(classes[a].sword, classes[b].sword) + squaredDifference(classes[a].sorcery, classes[b].sorcery);
        graph[a].emplace_back(b, d);
        graph[b].emplace_back(a, d);
    }

    // run dijkstra starting from each node
    vector<vector<ll>> dist(n + 1);
    for (ll i = 1; i <= n; ++i) {
        dist[i] = dijkstra(i, graph, n);
    }

    // answer queries
    ll q;
    cin >> q;

    rep(i, q) {
        ll start, end;
        cin >> start >> end;
        if (dist[start][end] != numeric_limits<ll>::max()) {
            cout << dist[start][end] << endl;
        } else {
            cout << "BRIBE DM WITH FOOD" << endl;
        }
    }

    return 0;
}
