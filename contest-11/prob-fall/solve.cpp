#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

void f1(Graph& a, ll b, ll& c, vector<ll>& d, vector<ll>& e, vector<bool>& f, vector<ll>& g) {
    f[b] = true;
    g[c] = b;
    d[b] = c;
    for (auto h : a[b]) {
        if (f[h]) continue;
        f1(a, h, ++c, d, e, f, g);
    }
    e[b] = c;
}

void f2(vector<vector<ll>>& i, vector<ll>& j, ll k, ll l, ll m, vector<ll>& n) {
    if (l == m) {
        i[k].push_back(j[n[l]]);
    } else {
        ll o = l + (m - l) / 2;
        f2(i, j, 2 * k, l, o, n);
        f2(i, j, 2 * k + 1, o + 1, m, n);
        merge(all(i[2 * k]), all(i[2 * k + 1]), back_inserter(i[k]));
    }
}

ll f3(vector<vector<ll>>& p, ll q, ll r, ll s, ll t, ll u, ll v) {
    if (t > u)
        return 0;
    else if (r == t && s == u) {
        auto w = lower_bound(all(p[q]), v);
        if (w == p[q].end()) return 0;
        auto x = upper_bound(all(p[q]), v);
        return distance(w, x);
    } else {
        ll y = r + (s - r) / 2;
        return f3(p, 2 * q, r, y, t, min(y, u), v) + f3(p, 2 * q + 1, y + 1, s, max(y + 1, t), u, v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll z, aa;
    cin >> z >> aa;
    Graph ab(z);
    for (ll ac = 0; ac < z - 1; ac++) {
        ll ad, ae;
        cin >> ad >> ae >> ws;
        ad--;
        ae--;
        ab[ad].push_back(ae);
        ab[ae].push_back(ad);
    }

    vector<ll> af(z);
    cin >> hex;
    for (ll ag = 0; ag < z; ag++) {
        cin.ignore(3, '#');
        cin >> af[ag] >> ws;
    }

    cin >> dec;
    vector<bool> ah(z, false);
    vector<ll> ai(z);
    vector<ll> aj(z);
    vector<ll> ak(z);

    ll al = 0;
    f1(ab, 0, al, ai, aj, ah, ak);
    vector<vector<ll>> am(4 * z);
    f2(am, af, 1, 0, z - 1, ak);

    for (ll an = 0; an < aa; an++) {
        ll ao, ap;
        cin >> ao;
        cin.ignore(3, '#');
        cin >> hex >> ap >> dec;
        ao--;
        cout << f3(am, 1, 0, z - 1, ai[ao], aj[ao], ap) << "\n";
    }

    return 0;
}
