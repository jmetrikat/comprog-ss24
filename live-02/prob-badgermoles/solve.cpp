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

    ll length, blocks, k, possible = 1, firstPhase;
    cin >> length >> blocks >> k;
    blocks -= length;

    firstPhase = min(k, length - k + 1);

    for (ll i = 1; i <= firstPhase; i++) {
        blocks -= 2 * i - 1;
        if (blocks < 0) break;
        possible++;
    }

    for (ll i = 2 * firstPhase - 1; i < length; i++) {
        blocks -= i + 1;
        if (blocks < 0) break;
        possible++;
    }

    if (blocks > 0) {
        possible += floor(blocks / length);
    }

    cout << possible << endl;
    return 0;
}
