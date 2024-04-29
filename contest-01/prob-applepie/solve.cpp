#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long

using namespace std;

int main() {
    ll testcases, households, pies, count;
    cin >> testcases;

    while (testcases--) {
        priority_queue<tuple<ll, ll, ll>> ponies;
        cin >> households >> pies;
        pies -= households;

        for (ll j = 0; j < households; j++) {
            cin >> count;
            ponies.push(make_tuple(count, count, 1));
        }

        for (ll k = 0; k < pies; k++) {
            tuple<ll, ll, ll> pony = ponies.top();
            ponies.pop();
            ponies.push(make_tuple(ceil(static_cast<double>(get<1>(pony)) / (static_cast<double>(get<2>(pony)) + 1.0)), get<1>(pony), get<2>(pony) + 1));
            pony = ponies.top();
        }

        tuple<ll, ll, ll> result = ponies.top();
        cout << get<0>(result) << endl;
    }

    return 0;
}
