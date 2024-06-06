#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

vector<long long> dijkstraMaxWeight(ll n, WeightedGraph& adj) {
    vector<ll> dist(n, LLONG_MAX);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[0] = 0;
    pq.push({0, 0});

    // explore all edges, starting with cheapest node
    while (!pq.empty()) {
        ll maxObservedDistance = pq.top().first;
        ll currentNode = pq.top().second;
        pq.pop();

        // skip if we have already found a better path
        if (maxObservedDistance > dist[currentNode]) continue;

        // relax all edges
        for (auto& edge : adj[currentNode]) {
            ll neighbour = edge.first;
            ll distanceToNeighbour = edge.second;

            ll maxWeight = max(maxObservedDistance, distanceToNeighbour);
            if (maxWeight < dist[neighbour]) {
                dist[neighbour] = maxWeight;
                pq.push({maxWeight, neighbour});
            }
        }
    }

    return dist;
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
        WeightedGraph adj(n);

        // create weighted graph
        rep(i, m) {
            ll a, b, w;
            cin >> a >> b >> w;
            adj[a].emplace_back(b, w);
            adj[b].emplace_back(a, w);
        }

        vector<ll> dist = dijkstraMaxWeight(n, adj);

        // find cost to reach 75% of cities while minimizing cost
        sort(all(dist));
        ll requiredCities = ceil((n - 1) * 0.75);
        cout << dist[requiredCities] << endl;
    }

    return 0;
}
