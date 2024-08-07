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

    ll a, b, c, result;
    cin >> a >> b >> c;

    result = 2 * a;
    if (c >= 2) {
        result += 3 + 2 * b;
        c -= 2;
    }

    result += floor(c / 2) * 3;
    cout << result << endl;

    return 0;
}
