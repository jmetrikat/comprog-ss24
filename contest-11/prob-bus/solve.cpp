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

    ll components, queries;
    cin >> components >> queries;
    vector<uint64_t> converter_sum(components + 1);

    for (int i = 1; i <= components; ++i) {
        string hexValue;
        cin >> hexValue;
        converter_sum[i] = converter_sum[i - 1] ^ stoull(hexValue, nullptr, 16);
    }

    ll first, second;
    while (queries--) {
        cin >> first >> second;
        if (second >= first) {
            cout << (converter_sum[first - 1] ^ converter_sum[second - 1]) << endl;
        } else {
            cout << ((converter_sum[first - 1] ^ converter_sum[second - 1]) ^ converter_sum[components]) << endl;
        }
    }

    return 0;
}
