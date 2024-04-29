#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long

using namespace std;

void perform_operation(const string &operation) {
    cout << operation << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    perform_operation("? insert 3");
    perform_operation("? insert 1");
    perform_operation("? insert 1");
    perform_operation("? insert 2");
    perform_operation("? remove");

    ll answer;
    cin >> answer;

    if (answer == 2) {
        perform_operation("! stack");
    } else if (answer == 3) {
        perform_operation("! queue");
    } else {
        perform_operation("? remove");
        cin >> answer;

        if (answer == 1) {
            perform_operation("! pq");
        } else if (answer == 2) {
            perform_operation("! set");
        } else {
            perform_operation("! impossible");
        }
    }

    return 0;
}
