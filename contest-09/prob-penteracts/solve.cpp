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

    ll x;
    cin >> x;

    ll result, difference;
    vector<ll> penta_powers;
    unordered_map<ll, ll> penta_root;

    // precompute powers of 5
    rep(i, 4000) {
        result = pow(i, 5);
        penta_powers.push_back(result);
        penta_root[result] = i;
    }

    // find the two numbers that sum to x
    rep(i, 4000) {
        difference = penta_powers[i] - x;
        if (penta_root.find(abs(difference)) != penta_root.end()) {
            cout << i << " " << (difference > 0 ? "" : "-") << penta_root[abs(difference)] << endl;
            break;
        }
    }

    return 0;
}
