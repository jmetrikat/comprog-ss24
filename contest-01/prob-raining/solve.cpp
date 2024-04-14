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
        string line;
        cin >> line;

        // transform line into heights
        vector<int> heights(line.length() + 1, 0);
        for (int i = 1; i <= line.size(); i++) {
            if (line[i - 1] == '/') {
                heights[i] = heights[i - 1] + 1;
            } else if (line[i - 1] == '\\') {
                heights[i] = heights[i - 1] - 1;
            } else {
                heights[i] = heights[i - 1];
            }
        }

        // populate left vector with max heights
        vector<int> left(heights.size(), 0);
        int max_height = heights[0];

        for (int i = 1; i < heights.size() - 1; i++) {
            max_height = max(max_height, heights[i]);
            left[i] = max_height - heights[i];
        }

        // populate left vector with max heights
        vector<int> right(heights.size(), 0);
        max_height = heights[heights.size() - 1];

        for (int i = heights.size() - 2; i > 0; i--) {
            max_height = max(max_height, heights[i]);
            right[i] = max_height - heights[i];
        }

        int trapped = 0;
        for (int i = 0; i < heights.size(); i++) {
            trapped += min(left[i], right[i]);
        }

        cout << trapped << endl;
    }

    return 0;
}
