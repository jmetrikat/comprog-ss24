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

    ll testcases;
    cin >> testcases;

    while (testcases--) {
        string line;
        cin >> line;

        // transform line into heights
        vector<ll> heights(line.length() + 1, 0);
        for (ll i = 1; i <= (ll)line.size(); i++) {
            if (line[i - 1] == '/') {
                heights[i] = heights[i - 1] + 1;
            } else if (line[i - 1] == '\\') {
                heights[i] = heights[i - 1] - 1;
            } else {
                heights[i] = heights[i - 1];
            }
        }

        // populate left vector with max heights
        vector<ll> trapped_from_left(heights.size(), 0);
        ll max_height = heights[0];

        for (ll i = 1; i < (ll)heights.size() - 1; i++) {
            max_height = max(max_height, heights[i]);
            trapped_from_left[i] = max_height - heights[i];
        }

        // populate right vector with max heights
        vector<ll> trapped_from_(heights.size(), 0);
        max_height = heights[heights.size() - 1];

        for (ll i = heights.size() - 2; i > 0; i--) {
            max_height = max(max_height, heights[i]);
            trapped_from_[i] = max_height - heights[i];
        }

        ll trapped = 0;
        for (ll i = 0; i < (ll)heights.size(); i++) {
            trapped += min(trapped_from_left[i], trapped_from_[i]);
        }

        cout << trapped << endl;
    }

    return 0;
}
