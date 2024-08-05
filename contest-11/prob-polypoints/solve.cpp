#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

struct Event {
    // type: 1 = starting rectangle, -1 = ending rectangle, 0 = point query
    ll x, y1, y2, type, idx;
    bool operator<(const Event& other) const {
        if (x == other.x) return type > other.type;
        return x < other.x;
    }
};

vector<ll> tree;
ll n;

void init_segment_tree(ll size) {
    n = size;
    tree.assign(4 * size, 0);
}

void update(ll idx, ll l, ll r, ll ul, ll ur, ll val) {
    if (ul > r || ur < l) return;  // out of range
    if (ul <= l && r <= ur) {
        tree[idx] += val;
        return;
    }
    ll mid = (l + r) / 2;
    update(2 * idx, l, mid, ul, ur, val);
    update(2 * idx + 1, mid + 1, r, ul, ur, val);
}

ll query(ll idx, ll l, ll r, ll pos) {
    if (l == r) return tree[idx];
    ll mid = (l + r) / 2;
    if (pos <= mid)
        return tree[idx] + query(2 * idx, l, mid, pos);
    else
        return tree[idx] + query(2 * idx + 1, mid + 1, r, pos);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<tuple<ll, ll, ll, ll>> rectangles(n);
    vector<pair<ll, ll>> points(m);
    vector<ll> y_coords;

    for (ll i = 0; i < n; ++i) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        rectangles[i] = {x1, y1, x2, y2};
        y_coords.push_back(y1);
        y_coords.push_back(y2);
    }

    for (ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        points[i] = {x, y};
        y_coords.push_back(y);
    }
    sort(all(y_coords));
    y_coords.erase(unique(all(y_coords)), y_coords.end());

    map<ll, ll> y_compress;
    for (ll i = 0; i < (ll)y_coords.size(); ++i) {
        y_compress[y_coords[i]] = i + 1;
    }

    vector<Event> events;
    for (ll i = 0; i < n; ++i) {
        auto [x1, y1, x2, y2] = rectangles[i];
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        events.push_back({x1, y_compress[y1], y_compress[y2], 1, -1});
        events.push_back({x2, y_compress[y1], y_compress[y2], -1, -1});
    }

    for (ll i = 0; i < m; ++i) {
        auto [x, y] = points[i];
        events.push_back({x, y_compress[y], y_compress[y], 0, i});
    }

    sort(all(events));
    init_segment_tree(y_coords.size());
    vector<ll> result(m);
    for (const auto& event : events) {
        if (event.type == 0) {
            result[event.idx] = query(1, 1, y_coords.size(), event.y1);
        } else {
            update(1, 1, y_coords.size(), event.y1, event.y2, event.type);
        }
    }
    for (const auto& res : result) {
        cout << res << '\n';
    }

    return 0;
}
