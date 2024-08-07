#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

bool canBeSplitIntoTwoEqualTeams(const vector<ll>& differences) {
    ll totalSum = accumulate(differences.begin(), differences.end(), 0);

    if (totalSum % 2 != 0) {
        return false;
    }

    ll target = totalSum / 2;

    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (ll num : differences) {
        for (ll i = target; i >= num; --i) {
            dp[i] = dp[i] || dp[i - num];
        }
    }

    return dp[target];
}

bool isBipartite(Graph& graph, ll n) {
    vector<ll> color(n, -1);
    queue<ll> q;

    vector<ll> diff(n, 0);

    for (ll i = 0; i < n; ++i) {
        if (color[i] == -1) {
            if (graph[i].empty()) continue;
            ll colored0 = 1, colored1 = 0;

            color[i] = 0;
            q.push(i);

            while (!q.empty()) {
                ll u = q.front();
                q.pop();

                for (ll v : graph[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];

                        if (color[v] == 0) {
                            ++colored0;
                        } else {
                            ++colored1;
                        }
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
            diff[i] = abs(colored0 - colored1);
        }
    }

    ll c0 = 0, c1 = 0, c2 = 0;
    rep(i, n) {
        if (color[i] == 0) {
            ++c0;
        } else if (color[i] == 1) {
            ++c1;
        } else {
            ++c2;
        }
    }

    rep(i, c2) {
        diff.push_back(1);
    }
    return canBeSplitIntoTwoEqualTeams(diff);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, m;
    cin >> n >> m;

    Graph graph(n);
    rep(i, m) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (n % 2 == 0 && isBipartite(graph, n)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
