#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

vector<int> parent, amountOfNodes, parity;

int find(int v) {
    if (parent[v] == v) return v;
    int root = find(parent[v]);
    parity[v] ^= parity[parent[v]];
    return parent[v] = root;
}

bool union_sets(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA == rootB) {
        if (parity[a] == parity[b]) {
            return false;
        }
        return true;
    }
    if (amountOfNodes[rootA] < amountOfNodes[rootB]) {
        swap(rootA, rootB);
        swap(a, b);
    }
    parent[rootB] = rootA;
    amountOfNodes[rootA] += amountOfNodes[rootB];
    parity[rootB] = parity[a] ^ parity[b] ^ 1;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n, m;
    cin >> n >> m;

    parent.resize(n);
    amountOfNodes.resize(n, 1);
    parity.resize(n, 0);
    iota(parent.begin(), parent.end(), 0);

    string result;
    bool destroyedBefore = false;
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (union_sets(u, v) && !destroyedBefore) {
            result.push_back('1');
        } else {
            result.push_back('0');
            destroyedBefore = true;
        }
    }

    cout << result << endl;

    return 0;
}
