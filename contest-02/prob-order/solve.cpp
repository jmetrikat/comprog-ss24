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

    ll numberOfProblems;
    cin >> numberOfProblems;

    // sort pq1 by start time, pq2 by end time
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<>> pq1;
    priority_queue<tuple<ll, ll>, vector<tuple<ll, ll>>, greater<>> pq2;

    // create tuples of start, end, index
    for (ll i = 1; i <= numberOfProblems; i++) {
        ll a, b;
        cin >> a >> b;
        pq1.push({a, b, i});
    }

    for (ll i = 1; i <= numberOfProblems; i++) {
        // move relevant tuples according to current start time to pq2
        while (!pq1.empty() && get<0>(pq1.top()) == i) {
            pq2.push({get<1>(pq1.top()), get<2>(pq1.top())});
            pq1.pop();
        }

        // pop index of top element of pq2 to output
        if (!pq2.empty()) {
            cout << get<1>(pq2.top()) << " ";
            pq2.pop();
        }
    }

    cout << endl;

    return 0;
}
