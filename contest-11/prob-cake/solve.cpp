#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

vector<ll> cakes;
vector<ll> segTree;

// build array based segment tree in linear time
void build_tree(ll node, ll start, ll end) {
    if (start == end) {
        segTree[node] = cakes[start];
    } else {
        ll mid = (start + end) / 2;
        build_tree(2 * node, start, mid);
        build_tree(2 * node + 1, mid + 1, end);
        segTree[node] = gcd(segTree[2 * node], segTree[2 * node + 1]);
    }
}

// update tree in logarithmic time when pieces of cake are eaten
void update_tree(ll node, ll start, ll end, ll idx, ll value) {
    if (start == end) {
        cakes[idx] -= value;
        segTree[node] = cakes[idx];
    } else {
        ll mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update_tree(2 * node, start, mid, idx, value);
        } else {
            update_tree(2 * node + 1, mid + 1, end, idx, value);
        }
        segTree[node] = gcd(segTree[2 * node], segTree[2 * node + 1]);
    }
}

// query a range of the tree in logarithmic time to find the gcd of the pieces of cake
ll query_tree(ll node, ll start, ll end, ll left, ll right) {
    if (right < start || end < left) {
        return 0;  // GCD with 0 is the other number
    }
    if (left <= start && end <= right) {
        return segTree[node];
    }
    ll mid = (start + end) / 2;
    ll left_gcd = query_tree(2 * node, start, mid, left, right);
    ll right_gcd = query_tree(2 * node + 1, mid + 1, end, left, right);
    return gcd(left_gcd, right_gcd);
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, q;
    cin >> n >> q;
    cakes.resize(n);
    segTree.resize(4 * n);

    // read in the cakes and build the segment tree
    rep(i, n) cin >> cakes[i];
    build_tree(1, 0, n - 1);

    rep(i, q) {
        string query;
        cin >> query;
        if (query[0] == '!') {
            string name;
            ll i, x;
            cin >> name >> i >> x;
            update_tree(1, 0, n - 1, i - 1, x);
        } else if (query[0] == '?') {
            ll left, right;
            cin >> left >> right;
            cout << query_tree(1, 0, n - 1, left - 1, right - 1) << endl;
        }
    }

    return 0;
}
