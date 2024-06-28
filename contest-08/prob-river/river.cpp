#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

int main() {
    ll w, l;
    cin >> w >> l;

    vector<ll> resilience(w - 1);
    for (ll i = 0; i < w - 1; ++i) {
        cin >> resilience[i];
    }

    ll max_mice = 0;
    vector<ll> current_resilience = resilience;

    // Try to cross the river as many times as possible
    while (true) {
        bool can_cross = true;
        ll position = 0;

        while (position + l < w) {
            ll next_stone = -1;

            // Find the farthest stone within the jump range that is still available
            for (ll j = 1; j <= l; ++j) {
                if (position + j < w && current_resilience[position + j - 1] > 0) {
                    next_stone = position + j;
                }
            }

            // No available stone within jump range
            if (next_stone == -1) {
                can_cross = false;
                break;
            }

            // Move to the next stone
            position = next_stone;
            current_resilience[position - 1]--;
        }

        if (can_cross) {
            max_mice++;
        } else {
            break;
        }
    }

    cout << max_mice << endl;
    return 0;
}
