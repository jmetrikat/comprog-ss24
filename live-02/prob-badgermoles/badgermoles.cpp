#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

ll n, m, k;

bool possible(ll height) {
    ll total_blocks = height;
    ll left_height = height - 1;

    // add blocks left of k but remove excess blocks
    if (k > 0) {
        ll left_total_blocks = (left_height * (left_height + 1)) / 2;
        ll left_excess_blocks = (left_height >= k) ? ((left_height - k) * (left_height - k + 1)) / 2 : 0;
        total_blocks += left_total_blocks - left_excess_blocks;
    }

    // add blocks right of k but remove excess blocks
    if (k < n - 1) {
        ll right_height = height - 1;
        ll right_total_blocks = (right_height * (right_height + 1)) / 2;
        ll right_excess_blocks = (right_height >= n - k - 1) ? ((right_height - (n - k - 1)) * (right_height - (n - k - 1) + 1)) / 2 : 0;
        total_blocks += right_total_blocks - right_excess_blocks;
    }

    return total_blocks <= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    cin >> n >> m >> k;
    k -= 1;

    // binary search for the maximum height
    ll left = 1, right = m, answer = 1;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (possible(mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << endl;

    return 0;
}
