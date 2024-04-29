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

    ll numberOfContests;
    cin >> numberOfContests;

    vector<long long> contests(numberOfContests), increasing(numberOfContests, 1), decreasing(numberOfContests, 1);
    for (auto &contest : contests) cin >> contest;

    // compute the longest increasing subsequence
    for (ll i = 1; i < numberOfContests; i++) {
        for (ll j = 0; j < i; j++) {
            if (contests[j] < contests[i]) {
                increasing[i] = max(increasing[i], increasing[j] + 1);
            }
        }
    }

    // compute the longest decreasing subsequence
    for (ll i = numberOfContests - 2; i >= 0; i--) {
        for (ll j = numberOfContests - 1; j > i; j--) {
            if (contests[j] < contests[i]) {
                decreasing[i] = max(decreasing[i], decreasing[j] + 1);
            }
        }
    }

    // find maximum over both subsequences while having a contest as top difficulty
    long long result = 0;
    for (ll i = 0; i < numberOfContests; i++) {
        result = max(result, increasing[i] + decreasing[i] - 1);
    }

    cout << result << endl;
    return 0;
}
