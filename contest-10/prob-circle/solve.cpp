#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll t;
    cin >> t;
    while (t--) {
        ll x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;

        // Calculate the distance between the centers of the circles
        ll dx = x2 - x1;
        ll dy = y2 - y1;
        ll d2 = dx * dx + dy * dy;

        ll r_sum_squared = (r1 + r2) * (r1 + r2);
        ll r_diff_squared = (r1 - r2) * (r1 - r2);

        if (d2 == 0 && r1 == r2 && r1 != 0 && r2 != 0) {
            // Circles coincide
            cout << "oo" << endl;
        } else if (d2 > r_sum_squared || d2 < r_diff_squared) {
            // Circles are too far apart or one circle is inside the other without touching
            cout << 0 << endl;
        } else if (d2 == r_sum_squared || d2 == r_diff_squared) {
            // Circles touch at exactly one point (externally or internally)
            cout << 1 << endl;
        } else {
            // Circles intersect at two points
            cout << 2 << endl;
        }
    }

    return 0;
}
