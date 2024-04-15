#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int testcases;
    cin >> testcases;

    while (testcases--) {
        int no_of_snoflakes;
        cin >> no_of_snoflakes;

        // read input of snowflakes into a vector
        vector<int> snoflakes(no_of_snoflakes);
        for (int i = 0; i < no_of_snoflakes; i++) {
            cin >> snoflakes[i];
        }

        // track the last index of each snowflake
        unordered_map<int, int> cnt;
        int longest_unique_sequence = 0;

        // find the longest unique sequence
        for (int i = 0, j = 0; i < no_of_snoflakes; i++) {
            j = max(j, cnt[snoflakes[i]]);
            longest_unique_sequence = max(longest_unique_sequence, i - j + 1);
            cnt[snoflakes[i]] = i + 1;
        }

        cout << longest_unique_sequence << endl;
    }

    return 0;
}
