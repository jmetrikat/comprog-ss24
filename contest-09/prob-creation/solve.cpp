#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

const ll MOD = 1000000007;
const ll MAX_N = 2 * 100000;

// Function to compute x^y % p in O(log y) time
ll power(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// Function to compute factorials and inverse factorials
void computeFactorialsAndInverses(vector<ll>& fact, vector<ll>& inv_fact) {
    fact[0] = 1;
    for (ll i = 1; i <= MAX_N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    // Fermat's Little Theorem
    inv_fact[MAX_N] = power(fact[MAX_N], MOD - 2, MOD);
    for (ll i = MAX_N - 1; i >= 0; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}

// Function to compute binomial coefficient nCr % p
ll binomialCoefficient(ll n, ll r, const vector<ll>& fact, const vector<ll>& inv_fact) {
    if (r > n || r < 0) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll testcases;
    cin >> testcases;

    vector<ll> fact(MAX_N + 1);
    vector<ll> inv_fact(MAX_N + 1);
    computeFactorialsAndInverses(fact, inv_fact);

    while (testcases--) {
        ll start, end, count;
        cin >> start >> end >> count;
        count -= 2;
        cout << binomialCoefficient(count + end - start, count, fact, inv_fact) << endl;
    }

    return 0;
}
