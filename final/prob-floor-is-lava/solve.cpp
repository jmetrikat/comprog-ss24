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

    ll n, m, q;
    cin >> n >> m >> q;

    vector<ll> vertical_lines(n);
    vector<ll> horizontal_lines(m);

    rep(i, n) cin >> vertical_lines[i];
    rep(i, m) cin >> horizontal_lines[i];

    sort(all(vertical_lines));
    sort(all(horizontal_lines));

    while (q--) {
        ll a, b;
        cin >> a >> b;

        auto it = lower_bound(all(vertical_lines), a);
        ll nearest_vertical;
        if (it == vertical_lines.end()) {
            nearest_vertical = vertical_lines.back();
        } else if (it == vertical_lines.begin()) {
            nearest_vertical = vertical_lines.front();
        } else {
            ll v1 = *it;
            ll v2 = *(--it);
            nearest_vertical = (abs(v1 - a) < abs(v2 - a)) ? v1 : v2;
        }

        it = lower_bound(all(horizontal_lines), b);
        ll nearest_horizontal;
        if (it == horizontal_lines.end()) {
            nearest_horizontal = horizontal_lines.back();
        } else if (it == horizontal_lines.begin()) {
            nearest_horizontal = horizontal_lines.front();
        } else {
            ll h1 = *it;
            ll h2 = *(--it);
            nearest_horizontal = (abs(h1 - b) < abs(h2 - b)) ? h1 : h2;
        }

        cout << nearest_vertical << " " << nearest_horizontal << endl;
    }

    return 0;
}
