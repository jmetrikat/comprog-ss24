#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

struct Point {
    ll x, y;
    Point(ll x = 0, ll y = 0) : x(x), y(y) {}
};

double distance(const Point &a, const Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    ll n;
    cin >> n;
    vector<Point> points(n);
    rep(i, n) {
        cin >> points[i].x >> points[i].y;
    }

    double total_distance = 0.0;
    for (ll i = 0; i < n / 2; ++i) {
        total_distance += distance(points[i], points[i + n / 2]);
    }

    cout << fixed << total_distance << endl;

    return 0;
}
