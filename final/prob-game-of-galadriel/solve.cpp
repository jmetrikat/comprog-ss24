#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

struct Operation {
    ll a, b, c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll m, s, t, n;
    cin >> m >> s >> t >> n;

    vector<Operation> operations(n);
    rep(i, n) {
        cin >> operations[i].a >> operations[i].b >> operations[i].c;
    }

    vector<ll> dist(m, LLONG_MAX);
    dist[s] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [current_cost, current_remainder] = pq.top();
        pq.pop();

        if (current_cost > dist[current_remainder]) continue;

        for (const auto& op : operations) {
            ll next_remainder = (op.a * current_remainder + op.b) % m;
            ll next_cost = current_cost + op.c;

            if (next_cost < dist[next_remainder]) {
                dist[next_remainder] = next_cost;
                pq.push({next_cost, next_remainder});
            }
        }
    }

    if (dist[t] == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << dist[t] << endl;
    }

    return 0;
}
