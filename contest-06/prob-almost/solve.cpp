#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>

using namespace std;

vector<ll> parent, noOfElements, sum;
vector<unordered_set<ll>> elements;

void initialize(ll n) {
    parent.resize(n + 1);
    noOfElements.resize(n + 1, 1);
    sum.resize(n + 1);
    elements.resize(n + 1);
    for (ll i = 1; i <= n; ++i) {
        parent[i] = i;
        sum[i] = i;
        elements[i].insert(i);
    }
}

ll find(ll x) {
    // utilize path compression
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void union_sets(ll p, ll q) {
    ll rootP = find(p);
    ll rootQ = find(q);

    if (rootP != rootQ) {
        // make root of smaller tree point to root of larger tree
        if (noOfElements[rootP] < noOfElements[rootQ]) {
            swap(rootP, rootQ);
        }

        // add elements of smaller tree to larger tree
        parent[rootQ] = rootP;
        noOfElements[rootP] += noOfElements[rootQ];
        sum[rootP] += sum[rootQ];

        for (ll i : elements[rootQ]) {
            elements[rootP].insert(i);
            parent[i] = rootP;
        }
        elements[rootQ].clear();
    }
}

void move(ll p, ll q) {
    ll rootP = find(p);
    ll rootQ = find(q);

    if (rootP != rootQ) {
        // remove element from current set
        elements[rootP].erase(p);
        noOfElements[rootP]--;
        sum[rootP] -= p;

        if (p == rootP) {
            // move root element which has children
            if (noOfElements[rootP] != 0) {
                ll newRoot = *elements[rootP].begin();
                noOfElements[newRoot] = 0;
                sum[newRoot] = 0;
                for (ll i : elements[rootP]) {
                    parent[i] = newRoot;
                    elements[newRoot].insert(i);
                    noOfElements[newRoot]++;
                    sum[newRoot] += i;
                }
                elements[rootP].clear();
            }
        }

        // move element to new set
        elements[rootQ].insert(p);
        noOfElements[rootQ]++;
        sum[rootQ] += p;
        parent[p] = rootQ;
    }
}

void query(ll p) {
    ll rootP = find(p);
    cout << noOfElements[rootP] << " " << sum[rootP] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, m;
    cin >> n >> m;
    initialize(n);

    for (ll i = 0; i < m; ++i) {
        ll type, p, q;
        cin >> type;
        if (type == 1) {
            cin >> p >> q;
            union_sets(p, q);
        } else if (type == 2) {
            cin >> p >> q;
            move(p, q);
        } else if (type == 3) {
            cin >> p;
            query(p);
        }
    }

    return 0;
}
