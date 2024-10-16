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

    long long numberOfProblems, difficulty;
    cin >> numberOfProblems >> difficulty;

    vector<ll> problems(numberOfProblems, 0);
    for (auto& e : problems) cin >> e;

    // sort in reverse order
    sort(all(problems), greater<ll>());

    // expand subset as long as the average is greater than difficulty
    long long additional = 0;
    rep(i, numberOfProblems) {
        additional += problems[i] - difficulty;
        if (additional < 0) {
            cout << i << endl;
            return 0;
        }
    }

    cout << numberOfProblems << endl;

    return 0;
}
