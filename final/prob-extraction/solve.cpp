#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

ll query(ll n) {
    cout << "buf[" << n << "]" << endl;
    ll result;
    cin >> result;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    bool foundZero = false;
    ll low = 1, high = 1, mid;

    while (query(high) != 0) {
        low = high + 1;
        high *= 2;
    }

    while (low < high) {
        mid = low + (high - low) / 2;
        if (query(mid) == 0)
            high = mid;
        else
            low = mid + 1;
    }
    cout << "strlen(buf) = " << high << endl;

    return 0;
}
