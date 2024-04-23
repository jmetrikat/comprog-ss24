#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;


// check all possible combinations of numbers and operations
bool bruteForce(vector<int>& nums) {
    vector<int> res1 = {nums[0] + nums[1], nums[0] - nums[1], nums[0] * nums[1]};
    for (int i : res1) {
        vector<int> res2 = {i + nums[2], i - nums[2], i * nums[2]};
        for (int j : res2) {
            vector<int> res3 = {j + nums[3], j - nums[3], j * nums[3]};
            for (int k : res3) {
                vector<int> res4 = {k + nums[4], k - nums[4], k * nums[4]};
                for (int l : res4) {
                    if (l == 23) return true;
                }
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int testcases;
    cin >> testcases;

    while (testcases--) {
        vector<int> nums(5, 0);
        for (auto& e : nums) cin >> e;
        sort(all(nums));
        bool found = false;

        // check all permutations of the numbers
        do {
            if (bruteForce(nums)) {
                cout << "Possible" << endl;
                found = true;
                break;
            }
        } while (next_permutation(all(nums)));

        if (!found) cout << "Impossible" << endl;
    }

    return 0;
}
