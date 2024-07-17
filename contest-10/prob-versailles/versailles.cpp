#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

ll cross(const pair<ll, ll>& O, const pair<ll, ll>& A, const pair<ll, ll>& B) {
    return (A.first - O.first) * (B.second - O.second) - (A.second - O.second) * (B.first - O.first);
}

// Function to compute the convex hull using Andrew's monotone chain algorithm
vector<pair<ll, ll>> convexHull(vector<pair<ll, ll>> points) {
    if (points.size() <= 1) return points;

    // Sort the points lexicographically
    sort(all(points));

    vector<pair<ll, ll>> hull;

    // Build the lower hull
    for (const auto& p : points) {
        while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull[hull.size() - 1], p) < 0) {
            hull.pop_back();
        }
        hull.push_back(p);
    }

    // Build the upper hull
    size_t lower_size = hull.size() + 1;
    for (ll i = points.size() - 2; i >= 0; --i) {
        const auto& p = points[i];
        while (hull.size() >= lower_size && cross(hull[hull.size() - 2], hull[hull.size() - 1], p) < 0) {
            hull.pop_back();
        }
        hull.push_back(p);
    }

    // Remove the last point because it's the same as the first point in the lower hull
    hull.pop_back();

    return hull;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> points(n);
        rep(i, n) {
            cin >> points[i].first >> points[i].second;
        }

        ll age = 0;
        while (!points.empty()) {
            age++;
            if (points.size() == 1) break;
            vector<pair<ll, ll>> hull = convexHull(points);
            // Remove points on the hull from the original set
            set<pair<ll, ll>> hull_set(all(hull));
            points.erase(remove_if(all(points), [&](const pair<ll, ll>& p) { return hull_set.find(p) != hull_set.end(); }),
                         points.end());
        }

        cout << age << endl;
    }

    return 0;
}
