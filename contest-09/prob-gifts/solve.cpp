#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

ll largestPrimeFactor(ll n) {
    ll maxPrime = -1;

    // divide n by 2 to remove all even factors
    while (n % 2 == 0) {
        maxPrime = 2;
        n /= 2;
    }

    // n must be odd at this point, so we can skip even numbers
    for (ll i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            maxPrime = i;
            n /= i;
        }
    }

    // check if n is a prime number greater than 2
    if (n > 2) {
        maxPrime = n;
    }

    return maxPrime;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n;
    cin >> n;

    cout << largestPrimeFactor(n) << endl;

    return 0;
}
