#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>

using namespace std;

void dfs(ll node, Graph& adj, vector<bool>& visited) {
    stack<ll> s;
    s.push(node);
    while (!s.empty()) {
        ll v = s.top();
        s.pop();
        if (!visited[v]) {
            visited[v] = true;
            for (ll u : adj[v]) {
                if (!visited[u]) {
                    s.push(u);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll numberOfPuddles, numberOfMoats;
    cin >> numberOfPuddles >> numberOfMoats;

    Graph adj(numberOfPuddles);
    while (numberOfMoats--) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(numberOfPuddles, false);
    dfs(0, adj, visited);

    bool allConnected = true;
    rep(i, numberOfPuddles) {
        if (!visited[i]) {
            allConnected = false;
            break;
        }
    }

    if (allConnected) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
