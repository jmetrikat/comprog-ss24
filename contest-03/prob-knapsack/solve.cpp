#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, M;
    cin >> n >> M;

    vector<ll> items(4, 0);
    ll w;
    for (ll i = 0; i < n; i++) {
        cin >> w;
        items[w]++;
    }

    ll sum = M;

    // take as many 3s as possible, then 2s, then 1s
    ll threes = min(sum / 3, items[3]);
    sum -= 3 * threes;

    ll twos = min(sum / 2, items[2]);
    sum -= 2 * twos;

    ll ones = min(sum, items[1]);
    sum -= ones;

    // if a difference of 1 remains and we've used atleast one 3, we can replace it with 2 twos
    if (sum == 1 && threes && twos + 2 <= items[2]) {
        sum -= 1;
    }

    cout << M - sum << endl;

    return 0;
}
