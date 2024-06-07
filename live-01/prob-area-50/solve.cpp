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

    ll x, y, r;
    cin >> x >> y >> r;

    cout << x - r << " " << y + r << endl;
    cout << x + r << " " << y + r << endl;
    cout << x + r << " " << y - r << endl;
    cout << x - r << " " << y - r << endl;

    return 0;
}
