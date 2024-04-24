#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int numberOfKnights, answer;
    cin >> numberOfKnights;
    vector<int> knights;

    // check order of first two knights
    cout << "? 1 2" << endl;
    cin >> answer;
    answer == 0 ? knights = {2, 1} : knights = {1, 2};

    // subsequently check order of knights through binary search approach
    for (int i = 3; i <= numberOfKnights; i++) {
        int left = 0, right = knights.size() - 1;

        // match against worst knight
        cout << "? " << knights[left] << " " << i << endl;
        cin >> answer;

        if (answer == 0) {
            knights.insert(knights.begin(), i);
            continue;
        }

        // match against best knight
        cout << "? " << i << " " << knights[right] << endl;
        cin >> answer;

        if (answer == 0) {
            knights.push_back(i);
            continue;
        }

        // match against middle knights and adjust area of search accordingly
        while (right - left > 1) {
            int mid = (left + right) / 2;
            cout << "? " << knights[mid] << " " << i << endl;
            cin >> answer;

            if (answer == 0) {
                right = mid;
            } else {
                left = mid;
            }
        }

        // insert knight in correct position
        knights.insert(knights.begin() + right, i);
    }

    // print result
    cout << "! ";
    for (int i = 0; i < numberOfKnights; i++) {
        cout << knights[i] << " ";
    }
    cout << endl;

    return 0;
}
