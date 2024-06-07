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

    ll n;
    cin >> n;

    if (n % 2 != 0) {
        cout << "impossible" << endl;
        return 0;
    }

    vector<pair<ll, ll>> skills(n);
    map<pair<ll, ll>, ll> counts;
    ll sum_first = 0, sum_second = 0, avg_first = 0, avg_second = 0, target_first = 0, target_second = 0;

    rep(i, n) {
        cin >> skills[i].first >> skills[i].second;
        sum_first += skills[i].first;
        sum_second += skills[i].second;
    }

    for (const auto& skill : skills) {
        if (counts.find(skill) == counts.end()) {
            counts[skill] = 1;
        } else {
            counts[skill]++;
        }
    }

    avg_first = sum_first / (n / 2);
    avg_second = sum_second / (n / 2);

    rep(i, n) {
        target_first = avg_first - skills[i].first;
        target_second = avg_second - skills[i].second;
        if (counts.find({target_first, target_second}) != counts.end() && counts[{target_first, target_second}] > 0) {
            counts[{target_first, target_second}]--;
        } else {
            cout << "impossible" << endl;
            return 0;
        }
    }

    cout << "possible" << endl;

    return 0;
}
