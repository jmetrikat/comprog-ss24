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

    ll medals;
    cin >> medals;

    Graph factors(medals);
    vector<vector<bool>> solution(medals, vector<bool>(169, false));

    vector<ll> primes = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
        101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223,
        227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353,
        359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491,
        499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643,
        647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
        811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967,
        971, 977, 983, 991, 997, 1009};

    for (ll i = 0; i < medals; i++) {
        ll value;
        cin >> value;
        for (ll j = 0; j < 169; j++) {
            if (value % primes[j] == 0) {
                factors[i].push_back(j);
            }
            while (value % primes[j] == 0) {
                value /= primes[j];
            }
            if (value == 1) {
                break;
            }
        }
    }

    for (auto &p : factors[0]) {
        solution[0][p] = true;
    }

    ll maximum = 1;

    for (ll i = 1; i < medals; i++) {
        bool found = false;
        for (ll k = maximum; k > max(0ll, maximum - (medals - i)); k--) {
            for (auto &prime : factors[i]) {
                if (solution[k - 1][prime]) {
                    for (auto &p : factors[i]) {
                        solution[k][p] = true;
                    }
                    if (k == maximum) {
                        maximum++;
                    }
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (!found) {
            for (auto &p : factors[i]) {
                solution[0][p] = true;
            }
        }
    }

    cout << maximum << endl;

    return 0;
}
