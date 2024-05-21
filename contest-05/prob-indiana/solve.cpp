#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>

using namespace std;

void solve(ll n, ll h, vector<pair<ll, ll>> &hints) {
    Graph adj(n + 1);
    vector<ll> in_degree(n + 1, 0);

    // build graph with directed edges based on hints
    for (auto &hint : hints) {
        ll a = hint.first;
        ll b = hint.second;

        adj[a].push_back(b);
        in_degree[b]++;
    }

    // find nodes with in-degree 0
    queue<ll> q;
    for (ll i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    // topological sort
    vector<ll> topological_order;
    bool multiple_sequences = false;

    while (!q.empty()) {
        if (q.size() > 1) {
            multiple_sequences = true;
        }
        ll node = q.front();
        q.pop();
        topological_order.push_back(node);

        for (ll neighbor : adj[node]) {
            if (--in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // check if topological sort is valid
    if ((ll)topological_order.size() != n) {
        cout << "recheck hints" << endl;
    } else if (multiple_sequences) {
        cout << "missing hints" << endl;
    } else {
        for (ll i = 0; i < (ll)topological_order.size(); ++i) {
            if (i > 0) cout << " ";
            cout << topological_order[i];
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll testcases;
    cin >> testcases;

    while (testcases--) {
        ll n, h;
        cin >> n >> h;
        vector<pair<ll, ll>> hints(h);
        for (auto &[a, b] : hints) cin >> a >> b;
        solve(n, h, hints);
    }

    return 0;
}
