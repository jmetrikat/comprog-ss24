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

    ll l, r;
    cin >> l >> r;

    if (l % 2 == 0 && r % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }

    if (l == r) {
        if (l == 1) {
            cout << l << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }

    if (l % 2 == 1 && r % 2 == 1) {
        cout << l + 2 << " " << l << " " << l + 1;
        l += 3;
    } else {
        cout << l + 1 << " " << l;
        l += 2;
    }

    while (l < r) {
        cout << " " << l + 1 << " " << l;
        l += 2;
    }
    cout << endl;

    return 0;
}
