#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

// Function to calculate the squared distance between two points
ll dist2(pair<ll, ll> p1, pair<ll, ll> p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

// Recursive function to find the closest pair of points
ll closest_pair(vector<pair<ll, ll>>& points, ll left, ll right) {
    // base case
    if (right - left <= 3) {
        ll min_dist = LLONG_MAX;
        for (ll i = left; i < right; ++i) {
            for (ll j = i + 1; j < right; ++j) {
                min_dist = min(min_dist, dist2(points[i], points[j]));
            }
        }
        sort(points.begin() + left, points.begin() + right, [](pair<ll, ll> a, pair<ll, ll> b) {
            return a.second < b.second;
        });
        return min_dist;
    }

    // divide recursively
    ll mid = (left + right) / 2;
    ll mid_x = points[mid].first;
    ll d = min(closest_pair(points, left, mid), closest_pair(points, mid, right));

    // check points near the middle line
    vector<pair<ll, ll>> temp;
    for (ll i = left; i < right; ++i) {
        if ((points[i].first - mid_x) * (points[i].first - mid_x) < d) {
            temp.push_back(points[i]);
        }
    }

    sort(temp.begin(), temp.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
        return a.second < b.second;
    });

    for (ll i = 0; i < (ll)temp.size(); ++i) {
        for (ll j = i + 1; j < (ll)temp.size() && (temp[j].second - temp[i].second) * (temp[j].second - temp[i].second) < d; ++j) {
            d = min(d, dist2(temp[i], temp[j]));
        }
    }

    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n;
    cin >> n;
    vector<pair<ll, ll>> points(n);
    for (auto& p : points) cin >> p.first >> p.second;

    sort(all(points));
    cout << closest_pair(points, 0, n) << endl;

    return 0;
}
